#ifndef AVS_DIAGONAL_MATRIX_H
#define AVS_DIAGONAL_MATRIX_H

#include "stdlib.h"
#include "stddef.h"
#include "float.h"

struct DiagonalMatrix {
    double *matrix;
};

void initializeDiagonal(struct DiagonalMatrix *diagonal, size_t dimension);
void clearDiagonal(struct DiagonalMatrix *diagonal);

#endif
