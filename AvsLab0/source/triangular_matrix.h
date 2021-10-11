#ifndef AVS_TRIANGULAR_MATRIX_H
#define AVS_TRIANGULAR_MATRIX_H

#include "stdlib.h"
#include "stddef.h"
#include "stdint.h"

struct TriangularMatrix {
    // Значения матрицы записываются в одномерный массив построчно.
    int *matrix;
};

int** convertToTwoDimensional(int *array, size_t dimension);

int* convertToArray(int **matrix, size_t dimension);

#endif
