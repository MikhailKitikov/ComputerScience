#include "mpi.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <clocale>

std::ofstream fout("result_1D.txt");

double f1(double x, double y) {
    return sin(y);
}

double f2(double x, double y) {
    return y;
}

double f3(double x, double y) {
    return x * x * x;
}

double f4(double x, double y) {
    return x * x;
}

double F(double x, double y) {
    return x * y;
}

int main(int argc, char** argv) {

    std::setlocale(LC_ALL, "Russian");

    int myrank, ranksize;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &ranksize);

    // размеры
    int row_size, col_size;

    if (myrank == 0) {
        std::cout << "Введите размеры сетки: \n";
        std::cin >> row_size >> col_size;
    }

    MPI_Bcast(&row_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&col_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // границы промежутков
    double x_left = 0, x_right = 1;
    double y_bottom = 0, y_top = 1;

    // шаг
    double x_step = double(x_right - x_left) / (col_size - 1);
    double y_step = double(y_top - y_bottom) / (row_size - 1);

    // коэффициенты
    double x_coeff = 1.0 / (x_step * x_step);
    double y_coeff = 1.0 / (y_step * y_step);
    double coeff = 2.0 * (x_coeff + y_coeff);

    // время
    double time_start;

    // таблица значений
    double* u = new double[row_size * col_size];

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            u[i * col_size + j] = 0;
        }
    }

    double x, y;
    int batch_size = (row_size - 2) / ranksize;

    // batch для каждого процесса
    int start = myrank * batch_size + 1;
    int stop = (myrank == ranksize - 1 ? row_size - 1 : start + batch_size);

    // снизу
    if (myrank == 0) {
        x = x_left;
        for (int j = 0; j < col_size; j++, x += x_step) {
            u[0 * col_size + j] = f3(x, y_bottom);
        }
    }

    // сверху
    if (myrank == ranksize - 1) {
        x = x_left;
        for (int j = 0; j < col_size; ++j, x += x_step) {
            u[(row_size - 1) * col_size + j] = f4(x, y_top);
        }
    }

    // слева и справа
    y = y_bottom + start * y_step;
    for (int i = start; i < stop; ++i, y += y_step) {
        u[i * col_size] = f1(x_left, y);
        u[i * col_size + col_size - 1] = f2(x_right, y);
    }

    // точность
    double eps = 0.00001;
    double err = 1;

    if (myrank == 0) {
        time_start = MPI_Wtime();
    }

    // итерации вычисления
    while (err > eps) {
        err = 0;
        y = y_bottom + start * y_step;

        // считаем новые значения
        for (int i = start; i < stop; ++i, y += y_step) {
            x = x_left + x_step;
            for (int j = 1; j < col_size - 1; ++j, x += x_step) {
                double saved_u = u[i * col_size + j];
                u[i * col_size + j] = (y_coeff * (u[(i - 1) * col_size + j]
                    + u[(i + 1) * col_size + j]) + x_coeff * (u[i * col_size + j - 1]
                        + u[i * col_size + j + 1]) - F(x, y)) / coeff;
                err = std::max(err, std::abs(saved_u - u[i * col_size + j]));
            }
        }

        // объединяем ошибки
        if (myrank == 0) {
            double proc_err;
            for (int i = 1; i < ranksize; i++) {
                MPI_Recv(&proc_err, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
                err = std::max(err, proc_err);
            }
        }
        else {
            MPI_Send(&err, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }

        MPI_Barrier(MPI_COMM_WORLD);

        if (myrank == 0) {
            for (int i = 1; i < ranksize; i++)
                MPI_Send(&err, 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD);
        }
        else {
            MPI_Recv(&err, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }

        // отправляем строку соседу сверху
        if (myrank != ranksize - 1) {
            MPI_Send(&u[(stop - 1) * col_size], col_size, MPI_DOUBLE, myrank + 1, 2, MPI_COMM_WORLD);
            MPI_Recv(&u[stop * col_size], col_size, MPI_DOUBLE, myrank + 1, 2, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }

        // отправляем строку соседу снизу
        if (myrank != 0) {
            MPI_Send(&u[start * col_size], col_size, MPI_DOUBLE, myrank - 1, 2, MPI_COMM_WORLD);
            MPI_Recv(&u[(start - 1) * col_size], col_size, MPI_DOUBLE, myrank - 1, 2, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);

    // собираем ответ в менеджере
    int* gather_cnt = new int[ranksize]; // сколько
    int* gather_offset = new int[ranksize]; // куда
    if (myrank == 0) { // (важно только менеджеру)
        for (int i = 0; i < ranksize - 1; i++) {
            gather_offset[i] = batch_size * col_size * i + col_size;
            gather_cnt[i] = batch_size * col_size;
        }
        gather_offset[ranksize - 1] = batch_size * col_size * (ranksize - 1) + col_size;
        gather_cnt[ranksize - 1] = col_size * row_size - gather_offset[ranksize - 1];
    }
    int myoffset = start * col_size;
    int mycnt = (myrank == ranksize - 1 ?
        col_size * row_size - myoffset : batch_size * col_size);
    
    MPI_Gatherv(&u[myoffset], mycnt, MPI_DOUBLE, u,
        gather_cnt, gather_offset, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (myrank == 0) {
        std::cout << "time: " << MPI_Wtime() - time_start << "sec \n";
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                fout << std::fixed << std::setprecision(5) << u[i * col_size + j] << "\t";
            }
            fout << '\n';
        }
    }

    MPI_Finalize();
    return 0;
}
