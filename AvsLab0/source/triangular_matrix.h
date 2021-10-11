#ifndef AVS_TRIANGULAR_MATRIX_H
#define AVS_TRIANGULAR_MATRIX_H

#include "stdlib.h"
#include "stddef.h"

struct TriangularMatrix {
    // Значения матрицы записываются в одномерный массив построчно.
    double *matrix;
};

double** convertToTwoDimensional(double *array, size_t dimension);

double* convertToArray(double **matrix, size_t dimension);

#endif
