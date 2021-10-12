#include "basic_matrix.h"

void initialize(struct BasicMatrix *base) {
    switch (base->currentType) {
        case USUAL:
            base->usual->matrix = malloc(base->dimension * sizeof(*(base->usual->matrix)));
            for (size_t i = 0; i < base->dimension; ++i) {
                base->usual->matrix[i] = malloc(base->dimension * sizeof(**(base->usual->matrix)));
            }
            break;
        case DIAGONAL:
            base->diagonal->matrix = malloc(base->dimension * sizeof(*(base->diagonal->matrix)));
            break;
        case TRIANGULAR:
            size_t size = base->dimension * (base->dimension - 1) / 2;
            base->triangular->matrix = malloc(size * sizeof(*(base->triangular->matrix)));
            break;
    }
}

void clear(struct BasicMatrix *base) {
    switch (base->currentType) {
        case USUAL:
            for (size_t i = 0; i < base->dimension; ++i) {
                free(base->usual->matrix[i]);
            }
            free(base->usual->matrix);
            break;
        case DIAGONAL:
            free(base->diagonal->matrix);
            break;
        case TRIANGULAR:
            free(base->triangular->matrix);
            break;
    }
}
