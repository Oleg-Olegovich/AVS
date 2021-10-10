#include "triangular_matrix.h"

void printMatrix(int *matrix, size_t dimension) {
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            std::cout << (j < i ? matrix[start_index_row + j] : '0') << ' ';
        }
        start_index_row += i;
        std::cout << '\n';
    }
}

int** convertToTwoDimensional(int *array, size_t dimension) {
    int **matrix = new int*[dimension];
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        matrix[i] = new int[dimension];
        for (size_t j = 0; j < dimension; ++j) {
            matrix[i][j] = (j < i ? matrix[start_index_row + j] : 0);
        }
        start_index_row += i;
    }
    return matrix;
}

int* convertToArray(int **matrix, size_t dimension) {
    int *array = new int[dimension * (dimension - 1) / 2];
    for (size_t i = 1, index = 0; i < dimension; ++i) {
        for (size_t j = 0; j < i; ++j) {
            array[index++] = matrix[i][j];
        }
    }
    return array;
}
