#ifndef AVS3_TRIANGULAR_MATRIX_H
#define AVS3_TRIANGULAR_MATRIX_H

#include "stdlib.h"
#include "float.h"

struct TriangularMatrix {
    // Значения матрицы записываются в одномерный массив построчно.
    double *matrix;
};

void initializeTriangular(struct TriangularMatrix **triangular, long long dimension);
void clearTriangular(struct TriangularMatrix **triangular);
double** convertToTwoDimensional(const double *array, long long dimension);
double* convertToArray(double **matrix, long long dimension);
long double getTriangularAverage(struct TriangularMatrix *triangular, long long dimension);

#endif
