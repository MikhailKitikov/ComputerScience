#include "mpi.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <clocale>

std::ofstream fout("result_2D.txt");

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
    int n_cols, n_rows;

    if (myrank == 0) {
        std::cout << "Enter dimensions:\n";
        std::cin >> n_cols >> n_rows;
    }

    MPI_Bcast(&n_cols, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n_rows, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // границы промежутка
    double x_left = 0, x_right = 1;
    double y_bottom = 0, y_top = 1;

    // шаг
    double x_step = (x_right - x_left) / (n_rows - 1);
    double y_step = (y_top - y_bottom) / (n_cols - 1);

    // коэффициенты
    double x_coeff = 1 / (x_step * x_step);
    double y_coeff = 1 / (y_step * y_step);
    double coeff = 2 * (x_coeff + y_coeff);

    // время
    double time_start;

    // матрица
    double* u = new double[n_cols * n_rows];

    for (int i = 0; i < n_cols; ++i) {
        for (int j = 0; j < n_rows; ++j) {
            u[i * n_rows + j] = 0;
        }
    }

    // делаем примерно квадратную сетку процессов
    int proc_on_col = std::sqrt(ranksize);
    int proc_on_row = ranksize / proc_on_col;

    int cols_per_proc = (n_cols - 2) / proc_on_row + 2;
    int rows_per_proc = (n_rows - 2) / proc_on_col + 2;

    int row_start = (myrank / proc_on_col) * (cols_per_proc - 2);
    int row_end = row_start + cols_per_proc;

    int col_start = (myrank % proc_on_col) * (rows_per_proc - 2);
    int col_end = col_start + rows_per_proc;

    // слева
    if (row_start == 0) {
        double x_pos = x_left + col_start * x_step;
        for (int j = col_start; j < col_end; ++j, x_pos += x_step) {
            u[0 * n_rows + j] = f3(x_pos, y_bottom);
        }
    }

    // справа
    if (row_end == n_cols) {
        double x_pos = x_left + col_start * x_step;
        for (int j = col_start; j < col_end; ++j, x_pos += x_step) {
            u[(n_cols - 1) * n_rows + j] = f4(x_pos, y_top);
        }
    }

    // снизу
    if (col_start == 0) {
        double y_pos = y_bottom + row_start * y_step;
        for (int i = row_start; i < row_end; ++i, y_pos += y_step) {
            u[i * n_rows] = f1(x_left, y_pos);
        }
    }

    // сверху
    if (col_end == n_rows) {
        double y_pos = y_bottom + row_start * y_step;
        for (int i = row_start; i < row_end; ++i, y_pos += y_step) {
            u[i * n_rows + n_rows - 1] = f2(x_right, y_pos);
        }
    }

    // точность
    double eps = 0.00001;
    double err = 10000;

    if (myrank == 0) {
        time_start = MPI_Wtime();
    }

    // итерации вычисления
    while (err > eps) {
        err = 0;
        double y_pos = y_bottom + (row_start + 1) * y_step;

        // вычисляем новые значения
        for (int i = row_start + 1; i < row_end - 1; ++i, y_pos += y_step) {
            double x_pos = x_left + (col_start + 1) * x_step;
            for (int j = col_start + 1; j < col_end - 1; ++j, x_pos += x_step) {
                double saved_u = u[i * n_rows + j];
                u[i * n_rows + j] = (y_coeff * (u[(i - 1) * n_rows + j] +
                    u[(i + 1) * n_rows + j]) + x_coeff * (u[i * n_rows + j - 1] +
                        u[i * n_rows + j + 1]) - F(x_pos, y_pos)) / coeff;
                err = std::max(err, abs(saved_u - u[i * n_rows + j]));
            }
        }

        // объединяем ошибки
        if (myrank == 0) {
            double proc_err;
            for (int i = 1; i < ranksize; ++i) {
                MPI_Recv(&proc_err, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
                err = std::max(err, proc_err);
            }
        }
        else MPI_Send(&err, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

        if (myrank == 0) {
            for (int i = 1; i < ranksize; ++i)
                MPI_Send(&err, 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD);
        }
        else MPI_Recv(&err, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);

        MPI_Barrier(MPI_COMM_WORLD);

        int send_to;

        // пересылаем соседу справа
        if (row_end < n_cols) {
            send_to = myrank + proc_on_col;
            MPI_Send(&u[(row_end - 2) * n_rows + col_start + 1], rows_per_proc - 2, MPI_DOUBLE, send_to, 2, MPI_COMM_WORLD);
            MPI_Recv(&u[(row_end - 1) * n_rows + col_start + 1], rows_per_proc - 2, MPI_DOUBLE, send_to, 2, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }

        // пересылаем соседу слева
        if (row_start > 0) {
            send_to = myrank - proc_on_col;
            MPI_Send(&u[(row_start + 1) * n_rows + col_start + 1], rows_per_proc - 2, MPI_DOUBLE, send_to, 2, MPI_COMM_WORLD);
            MPI_Recv(&u[row_start * n_rows + col_start + 1], rows_per_proc - 2, MPI_DOUBLE, send_to, 2, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }

        MPI_Barrier(MPI_COMM_WORLD);

        // пересылаем соседу сверху
        if (col_end < n_rows) {
            for (int i = row_start; i < row_end; ++i) {
                send_to = myrank + 1;
                MPI_Send(&u[i * n_rows + col_end - 2], 1, MPI_DOUBLE, send_to, 3, MPI_COMM_WORLD);
                MPI_Recv(&u[i * n_rows + col_end - 1], 1, MPI_DOUBLE, send_to, 3, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
            }
        }

        // пересылаем соседу снизу
        if (col_start > 0) {
            send_to = myrank - 1;
            for (int i = row_start; i < row_end; ++i) {
                MPI_Send(&u[i * n_rows + col_start + 1], 1, MPI_DOUBLE, send_to, 3, MPI_COMM_WORLD);
                MPI_Recv(&u[i * n_rows + col_start], 1, MPI_DOUBLE, myrank - 1, 3, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
            }
        }
    }

    // сборка ответа в менеджере
    if (myrank == 0) {
        for (int proc = 1; proc < ranksize; ++proc) {
            int proc_row_offset = (proc / proc_on_col) * (cols_per_proc - 2);
            int proc_col_offset = (proc % proc_on_col) * (rows_per_proc - 2);
            auto offset = [&](int i) { return i * n_rows + proc_col_offset + 2 * int(proc_col_offset != 0); };
            int cnt = rows_per_proc - 2 * int(proc_col_offset != 0);
            for (int i = proc_row_offset; i < proc_row_offset + cols_per_proc; i++)
                MPI_Recv(&u[offset(i)], cnt, MPI_DOUBLE, proc, 4, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        }
    }
    else {
        for (int i = row_start; i < row_end; i++)
            MPI_Send(&u[i * n_rows + col_start + 2 * int(col_start != 0)],
                rows_per_proc - 2 * int(col_start != 0), MPI_DOUBLE, 0, 4, MPI_COMM_WORLD);
    }

    if (myrank == 0) {
        std::cout << MPI_Wtime() - time_start << '\n';
        for (int i = 0; i < n_cols; ++i) {
            for (int j = 0; j < n_rows; ++j)
                fout << std::fixed << std::setprecision(6) << u[i * n_rows + j] << "\t";
            fout << '\n';
        }
    }

    MPI_Finalize();
    return 0;
}
