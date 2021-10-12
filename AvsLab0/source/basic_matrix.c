#include "basic_matrix.h"

void initialize(struct BasicMatrix *base) {
    switch (base->currentType) {
        case USUAL:
            initializeUsual(&base->usual, base->dimension);
            break;
        case DIAGONAL:
            initializeDiagonal(&base->diagonal, base->dimension);
            break;
        case TRIANGULAR:
            initializeTriangular(&base->triangular, base->dimension);
            break;
    }
}

void clear(struct BasicMatrix *base) {
    switch (base->currentType) {
        case USUAL:
            clearUsual(&base->usual, base->dimension);
            break;
        case DIAGONAL:
            clearDiagonal(&base->diagonal);
            break;
        case TRIANGULAR:
            clearTriangular(&base->triangular);
            break;
    }
    free(base);
}

double generateNumber() {
    srand(time(0));
    return -100.0 + 201.0 * rand();
}

struct BasicMatrix* generateMatrix(long long dimension) {
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    base->currentType = USUAL;
    base->dimension = dimension;
    initialize(base);
    srand(time(0));
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            base->usual->matrix[i][j] = generateNumber();
        }
    }
    return base;
}

struct BasicMatrix* generateDiagonalMatrix(long long dimension) {
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    base->currentType = DIAGONAL;
    base->dimension = dimension;
    initialize(base);
    srand(time(0));
    for (long long i = 0; i < dimension; ++i) {
        base->diagonal->matrix[i] = generateNumber();
    }
    return base;
}

struct BasicMatrix* generateTriangularMatrix(long long dimension) {
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    base->currentType = TRIANGULAR;
    base->dimension = dimension;
    initialize(base);
    srand(time(0));
    long long size = dimension * (dimension - 1) / 2;
    for (long long i = 0; i < size; ++i) {
        base->triangular->matrix[i] = generateNumber();
    }
    return base;
}
