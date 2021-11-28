#ifndef AVS3_DIAGONAL_MATRIX_H
#define AVS3_DIAGONAL_MATRIX_H

#include "stdlib.h"
#include "float.h"

struct DiagonalMatrix {
    double *matrix;
};

void initializeDiagonal(struct DiagonalMatrix **diagonal, long long dimension);
void clearDiagonal(struct DiagonalMatrix **diagonal);
long double getDiagonalAverage(struct DiagonalMatrix *diagonal, long long dimension);

#endif
