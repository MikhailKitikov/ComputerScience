#define _CRT_SECURE_NO_WARNINGS

#include "mpi.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <ctime>

void fill_matrix(int n, double *matr, double *save_matr) {
    std::srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matr[i * n + j] = double(rand() % 1000);
            save_matr[i * n + j] = matr[i * n + j];
        }
    }
}

void SolveLU(int n, int myrank, int ranksize, double *matr) {
    // итерации
    for (int iter = 0; iter < n - 1; iter++) {
        // каждый процесс обновляет принадл. ему строки матрицы U
        if (myrank == iter % ranksize) {
            for (int i = iter + 1; i < n; i++) {
                matr[iter * n + i] /= matr[iter * n + iter];
            }
        }
        // рассылка подсчитанной строки U
        MPI_Bcast(&(matr[iter * n + iter + 1]), n - iter - 1, MPI_DOUBLE, iter % ranksize, MPI_COMM_WORLD);
        for (int i = iter + 1; i < n; i++) {
            if (myrank == i % ranksize) {
                for (int j = iter + 1; j < n; j++) {
                    matr[i * n + j] -= matr[i * n + iter] * matr[iter * n + j];
                }
            }
        }
    }
}

int main(int argc, char ** argv)
{
    int myrank, ranksize;
    MPI_Status status;
    clock_t c1, c2;

    int n = 20, batch;
    double *matr, *save_matr = nullptr;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ranksize);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0) {
        std::cout << "Enter n:\n";
        std::cin >> n;
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    matr = new double[n * n];

    if (myrank == 0) {
        save_matr = new double[n * n];
        fill_matrix(n, matr, save_matr);
    }

    c1 = clock();
    MPI_Bcast(matr, n * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    SolveLU(n, myrank, ranksize, matr);
    c2 = clock();

    if (myrank == 0) {
        std::ofstream fout("result.txt");
        fout << "\Initial matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fout << save_matr[i * n + j] << ' ';
            }
            fout << '\n';
        }
        fout << "\nMatrix L:\n";
        for (int i = 0; i < n; i++) {
            if (i % ranksize) {
                MPI_Recv(&(matr[i * n]), n, MPI_DOUBLE, i % ranksize, 100, MPI_COMM_WORLD, &status);
            }                
            for (int j = 0; j <= i; j++) {
                fout << matr[i * n + j] << ' ';
            }                
            for (int j = i + 1; j < n; j++) {
                fout << "0 ";
            }                
            fout << '\n';
        }
        fout << "\nMatrix U:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                fout << "0 ";
            }                
            fout << "1 ";
            for (int j = i + 1; j < n; j++) {
                fout << matr[i * n + j] << " ";
            }                
            fout << '\n';
        }
        fout.close();
    }
    else {
        for (int i = myrank; i < n; i += ranksize)
            MPI_Send(&(matr[i * n]), n, MPI_DOUBLE, 0, 100, MPI_COMM_WORLD);
    }

    if (myrank == 0) {
        std::cout << "Time: " << double(c2 - c1) << " msec\n";
    }        

    delete[] matr;
    MPI_Finalize();
    return 0;
}