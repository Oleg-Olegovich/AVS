#include "triangular_matrix.h"

void initializeTriangular(struct TriangularMatrix **triangular, size_t dimension) {
    *triangular = (struct TriangularMatrix*)malloc(sizeof(struct TriangularMatrix));
    size_t size = dimension * (dimension - 1) / 2;
    (*triangular)->matrix = (double*)malloc(size * sizeof(double));
}

void clearTriangular(struct TriangularMatrix **triangular) {
    free((*triangular)->matrix);
    free(*triangular);
}

double** convertToTwoDimensional(const double *array, size_t dimension) {
    double **matrix = (double**)malloc(dimension * sizeof(double*));
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        matrix[i] = (double*)malloc(dimension * sizeof(double));
        for (size_t j = 0; j < dimension; ++j) {
            matrix[i][j] = (j < i ? array[start_index_row + j] : 0);
        }
        start_index_row += i;
    }
    return matrix;
}

double* convertToArray(double **matrix, size_t dimension) {
    double *array = (double*)malloc(dimension * (dimension - 1) / 2 * sizeof(double));
    for (size_t i = 1, index = 0; i < dimension; ++i) {
        for (size_t j = 0; j < i; ++j) {
            array[index++] = matrix[i][j];
        }
    }
    return array;
}
