#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "mpi.h"
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <ctime>

void multiply(int myrank, int batch, int n, int m, double** matr, double* vec, double* res)
{
	int start = myrank * batch;
	int finish = std::min(n, start + batch);
	//std::cout << "Process #" << myrank << " from " << start << " to " << finish << std::endl;
	for (int row = start; row < finish; ++row) {
		double sum = 0;
		for (int col = 0; col < m; ++col) {
			sum += matr[row][col] * vec[col];
		}
		res[row] = sum;
	}
}

void initialize_data(int n, int m, double ***matr, double **vec, double **res) {
	(*matr) = new double*[n];
	for (int i = 0; i < n; ++i) {
		(*matr)[i] = new double[m];
	}
	(*vec) = new double[m];
	(*res) = new double[n];
}

int main(int argc, char ** argv)
{
	int myrank, ranksize;
	MPI_Status status;
	clock_t c1, c2;

	int n, m, batch;
	double **matr;
	double *vec;
	double *res;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &ranksize);

	if (myrank == 0) {
		std::cout << "\t\t\tMatrix * vector:\n";
		std::cout << "\tMatrix:\n";
		std::cout << "Enter n, m: ";
		std::cin >> n >> m;
		batch = floor(n / ranksize);
		std::cout << "ranksize = " << ranksize << std::endl;
		std::cout << "batch = " << batch << std::endl;
		for (int i = 1; i < ranksize; ++i) {
			MPI_Send(&n, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
			MPI_Send(&m, 1, MPI_INT, i, 2, MPI_COMM_WORLD);
			MPI_Send(&batch, 1, MPI_INT, i, 3, MPI_COMM_WORLD);
		}
	}
	else {
		MPI_Recv(&n, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		MPI_Recv(&m, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&batch, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
	}

	initialize_data(n, m, &matr, &vec, &res);
	MPI_Barrier(MPI_COMM_WORLD);

	if (myrank == 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				matr[i][j] = rand() % 20;
			}
		}
		for (int i = 0; i < m; ++i) {
			vec[i] = rand() % 20;
		}
		c1 = clock();
		for (int dest = 1; dest < ranksize; dest++) {
			int start = dest * batch;
			int finish = start + batch;
			for (int j = start; j < finish; ++j) {
				MPI_Send(matr[j], m, MPI_DOUBLE, dest, 4 + j, MPI_COMM_WORLD);
			}
			MPI_Send(vec, m, MPI_DOUBLE, dest, n + 1, MPI_COMM_WORLD);
		}
	}
	else {
		int start = myrank * batch;
		int finish = start + batch;
		for (int j = start; j < finish; ++j) {
			MPI_Recv(matr[j], m, MPI_DOUBLE, 0, 4 + j, MPI_COMM_WORLD, &status);
		}
		MPI_Recv(vec, m, MPI_DOUBLE, 0, n + 1, MPI_COMM_WORLD, &status);
	}

	multiply(myrank, batch, n, m, matr, vec, res);
	MPI_Barrier(MPI_COMM_WORLD);

	if (myrank == 0) {
		int rows_left = n - batch * ranksize;
		if (rows_left > 0) {
			multiply(ranksize, batch, n, m, matr, vec, res);
		}
		for (int src = 1; src < ranksize; src++) {
			MPI_Recv(&res[src * batch], batch, MPI_DOUBLE, src, n + 2, MPI_COMM_WORLD, &status);
		}
		c2 = clock();
		std::cout << "Time: " << double(c2 - c1) << " msec\n";
	}
	else {
		MPI_Send(&res[myrank * batch], batch, MPI_DOUBLE, 0, n + 2, MPI_COMM_WORLD);
	}

	MPI_Finalize();

	return 0;
}