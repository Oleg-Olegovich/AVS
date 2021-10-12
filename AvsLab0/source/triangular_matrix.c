#include "triangular_matrix.h"

void initializeTriangular(struct TriangularMatrix **triangular, long long dimension) {
    *triangular = (struct TriangularMatrix*)malloc(sizeof(struct TriangularMatrix));
    long long size = dimension * (dimension - 1) / 2;
    (*triangular)->matrix = (double*)malloc(size * sizeof(double));
}

void clearTriangular(struct TriangularMatrix **triangular) {
    free((*triangular)->matrix);
    free(*triangular);
}

double** convertToTwoDimensional(const double *array, long long dimension) {
    double **matrix = (double**)malloc(dimension * sizeof(double*));
    long long start_index_row = 0;
    for (long long i = 0; i < dimension; ++i) {
        matrix[i] = (double*)malloc(dimension * sizeof(double));
        for (long long j = 0; j < dimension; ++j) {
            matrix[i][j] = (j < i ? array[start_index_row + j] : 0);
        }
        start_index_row += i;
    }
    return matrix;
}

double* convertToArray(double **matrix, long long dimension) {
    double *array = (double*)malloc(dimension * (dimension - 1) / 2 * sizeof(double));
    for (long long i = 1, index = 0; i < dimension; ++i) {
        for (long long j = 0; j < i; ++j) {
            array[index++] = matrix[i][j];
        }
    }
    return array;
}
