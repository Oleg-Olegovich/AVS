#include "diagonal_matrix.h"

void initializeDiagonal(struct DiagonalMatrix **diagonal, size_t dimension) {
    *diagonal = (struct DiagonalMatrix*)malloc(sizeof(struct DiagonalMatrix));
    (*diagonal)->matrix = (double*)malloc(dimension * sizeof(double));
}

void clearDiagonal(struct DiagonalMatrix **diagonal) {
    free((*diagonal)->matrix);
    free(*diagonal);
}
