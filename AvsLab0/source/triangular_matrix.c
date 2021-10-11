#include "triangular_matrix.h"

int** convertToTwoDimensional(int *array, size_t dimension) {
    int **matrix = malloc(dimension * sizeof(*matrix));
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        matrix[i] = malloc(dimension * sizeof(**matrix));
        for (size_t j = 0; j < dimension; ++j) {
            matrix[i][j] = (j < i ? matrix[start_index_row + j] : 0);
        }
        start_index_row += i;
    }
    return matrix;
}

int* convertToArray(int **matrix, size_t dimension) {
    int *array = malloc(dimension * (dimension - 1) / 2 * sizeof(*matrix));
    for (size_t i = 1, index = 0; i < dimension; ++i) {
        for (size_t j = 0; j < i; ++j) {
            array[index++] = matrix[i][j];
        }
    }
    return array;
}
