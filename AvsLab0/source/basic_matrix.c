#include "basic_matrix.h"

void initialize(struct BasicMatrix *base) {
    switch (base->currentType) {
        case USUAL:
            initializeUsual(&base->usual, base->dimension);
            break;
        case DIAGONAL:
            initializeDiagonal(base->diagonal, base->dimension);
            break;
        case TRIANGULAR:
            initializeTriangular(base->triangular, base->dimension);
            break;
    }
}

void clear(struct BasicMatrix *base) {
    switch (base->currentType) {
        case USUAL:
            clearUsual(&base->usual, base->dimension);
            break;
        case DIAGONAL:
            clearDiagonal(base->diagonal);
            break;
        case TRIANGULAR:
            clearTriangular(base->triangular);
            break;
    }
    free(base);
}

double generateNumber() {
    srand(time(0));
    return -100.0 + 201.0 * rand();
}

struct BasicMatrix* generateMatrix() {
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    base->currentType = USUAL;
    srand(time(0));
    base->dimension = 1 + rand() % 10;
    initialize(base);
    for (size_t i = 0; i < base->dimension; ++i) {
        for (size_t j = 0; j < base->dimension; ++j) {
            base->usual->matrix[i][j] = generateNumber();
        }
    }
    return base;
}

struct BasicMatrix* generateDiagonalMatrix() {
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    base->currentType = DIAGONAL;
    srand(time(0));
    base->dimension = 1 + rand() % 10;
    initialize(&base);
    for (size_t i = 0; i < base->dimension; ++i) {
        base->diagonal->matrix[i] = generateNumber();
    }
    return base;
}

struct BasicMatrix* generateTriangularMatrix() {
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    base->currentType = TRIANGULAR;
    srand(time(0));
    base->dimension = 1 + rand() % 10;
    initialize(&base);
    size_t size = base->dimension * (base->dimension - 1) / 2;
    for (size_t i = 0; i < size; ++i) {
        base->triangular->matrix[i] = generateNumber();
    }
    return base;
}
