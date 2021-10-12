#include "basic_matrix.h"

void initialize(struct BasicMatrix *base) {
    switch (base->currentType) {
        case USUAL:
            base->usual = malloc(sizeof(&base->usual));
            base->usual->matrix = malloc(base->dimension * sizeof(*(base->usual->matrix)));
            for (size_t i = 0; i < base->dimension; ++i) {
                base->usual->matrix[i] = malloc(base->dimension * sizeof(**(base->usual->matrix)));
            }
            break;
        case DIAGONAL:
            base->diagonal = malloc(sizeof(&base->diagonal));
            base->diagonal->matrix = malloc(base->dimension * sizeof(*(base->diagonal->matrix)));
            break;
        case TRIANGULAR:
            base->triangular = malloc(sizeof(&base->triangular));
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
            free(base->usual);
            break;
        case DIAGONAL:
            free(base->diagonal->matrix);
            free(base->diagonal);
            break;
        case TRIANGULAR:
            free(base->triangular->matrix);
            free(base->triangular);
            break;
    }
}

double generateNumber() {
    srand(time(0));
    return -100.0 + 201.0 * rand();
}

struct BasicMatrix generateMatrix() {
    struct BasicMatrix base;
    base.currentType = USUAL;
    srand(time(0));
    base.dimension = 1 + rand() % 10;
    initialize(&base);
    for (size_t i = 0; i < base.dimension; ++i) {
        for (size_t j = 0; j < base.dimension; ++j) {
            base.usual->matrix[i][j] = generateNumber();
        }
    }
    return base;
}

struct BasicMatrix generateDiagonalMatrix() {
    struct BasicMatrix base;
    base.currentType = DIAGONAL;
    srand(time(0));
    base.dimension = 1 + rand() % 10;
    initialize(&base);
    for (size_t i = 0; i < base.dimension; ++i) {
        base.diagonal->matrix[i] = generateNumber();
    }
    return base;
}

struct BasicMatrix generateTriangularMatrix() {
    struct BasicMatrix base;
    base.currentType = TRIANGULAR;
    srand(time(0));
    base.dimension = 1 + rand() % 10;
    initialize(&base);
    size_t size = base.dimension * (base.dimension - 1) / 2;
    for (size_t i = 0; i < size; ++i) {
        base.triangular->matrix[i] = generateNumber();
    }
    return base;
}
