#include "triangular_matrix.h"

double** convertToTwoDimensional(double *array, size_t dimension) {
    double **matrix = malloc(dimension * sizeof(*matrix));
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        matrix[i] = malloc(dimension * sizeof(**matrix));
        for (size_t j = 0; j < dimension; ++j) {
            matrix[i][j] = (j < i ? array[start_index_row + j] : 0);
        }
        start_index_row += i;
    }
    return matrix;
}

double* convertToArray(double **matrix, size_t dimension) {
    double *array = malloc(dimension * (dimension - 1) / 2 * sizeof(*matrix));
    for (size_t i = 1, index = 0; i < dimension; ++i) {
        for (size_t j = 0; j < i; ++j) {
            array[index++] = matrix[i][j];
        }
    }
    return array;
}
