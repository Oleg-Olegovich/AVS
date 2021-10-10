#ifndef AVS_TRIANGULAR_MATRIX_H
#define AVS_TRIANGULAR_MATRIX_H

struct TriangularMatrix {
    // Значения матрицы записываются в одномерный массив построчно.
    int *matrix;
};

void printMatrix(int *matrix, size_t dimension);

int** convertToTwoDimensional(int *array, size_t dimension);

int* convertToArray(int **matrix, size_t dimension);

#endif
