#include "diagonal_matrix.h"

void initializeDiagonal(struct DiagonalMatrix **diagonal, long long dimension) {
    *diagonal = (struct DiagonalMatrix*)malloc(sizeof(struct DiagonalMatrix));
    (*diagonal)->matrix = (double*)malloc(dimension * sizeof(double));
}

void clearDiagonal(struct DiagonalMatrix **diagonal) {
    free((*diagonal)->matrix);
    free(*diagonal);
}
