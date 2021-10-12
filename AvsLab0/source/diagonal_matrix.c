#include "diagonal_matrix.h"

void initializeDiagonal(struct DiagonalMatrix *diagonal, size_t dimension) {
    diagonal = malloc(sizeof(*diagonal));
    diagonal->matrix = malloc(dimension * sizeof(*(diagonal->matrix)));
}

void clearDiagonal(struct DiagonalMatrix *diagonal) {
    free(diagonal->matrix);
    free(diagonal);
}
