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

double generateNumber() {
    srand(time(0));
    return -100.0 + 201.0 * rand();
}

struct BasicMatrix generateMatrix() {
    struct BasicMatrix basic;
    basic.currentType = USUAL;
    srand(time(0));
    basic.dimension = 1 + rand() % 10;
    double **matrix = malloc(basic.dimension * sizeof(*matrix));
    for (size_t i = 0; i < basic.dimension; ++i) {
        matrix[i] = malloc(basic.dimension * sizeof(**matrix));
        for (size_t j = 0; j < basic.dimension; ++j) {
            matrix[i][j] = generateNumber();
        }
    }
    basic.usual->matrix = matrix;
    return basic;
}

struct BasicMatrix generateDiagonalMatrix() {
    struct BasicMatrix basic;
    basic.currentType = DIAGONAL;
    srand(time(0));
    basic.dimension = 1 + rand() % 10;
    double *matrix = malloc(basic.dimension * sizeof(*matrix));
    for (size_t i = 0; i < basic.dimension; ++i) {
        matrix[i] = generateNumber();
    }
    basic.diagonal->matrix = matrix;
    return basic;
}

struct BasicMatrix generateTriangularMatrix() {
    struct BasicMatrix basic;
    basic.currentType = TRIANGULAR;
    srand(time(0));
    basic.dimension = 1 + rand() % 10;
    size_t size = basic.dimension * (basic.dimension - 1) / 2;
    double *matrix = malloc(size * sizeof(*matrix));
    for (size_t i = 0; i < size; ++i) {
        matrix[i] = generateNumber();
    }
    basic.triangular->matrix = matrix;
    return basic;
}
