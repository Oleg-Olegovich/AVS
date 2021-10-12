#ifndef AVS_DIAGONAL_MATRIX_H
#define AVS_DIAGONAL_MATRIX_H

#include "stdlib.h"
#include "float.h"

struct DiagonalMatrix {
    double *matrix;
};

void initializeDiagonal(struct DiagonalMatrix **diagonal, long long dimension);
void clearDiagonal(struct DiagonalMatrix **diagonal);

#endif
