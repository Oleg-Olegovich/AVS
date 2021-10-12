#ifndef AVS_TRIANGULAR_MATRIX_H
#define AVS_TRIANGULAR_MATRIX_H

#include "stdlib.h"
#include "stddef.h"
#include "float.h"

struct TriangularMatrix {
    // Значения матрицы записываются в одномерный массив построчно.
    double *matrix;
};

void initializeTriangular(struct TriangularMatrix *triangular, size_t dimension);
void clearTriangular(struct TriangularMatrix *triangular);
double** convertToTwoDimensional(double *array, size_t dimension);
double* convertToArray(double **matrix, size_t dimension);

#endif
