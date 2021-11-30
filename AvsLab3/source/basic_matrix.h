#ifndef AVS3_BASIC_MATRIX_H
#define AVS3_BASIC_MATRIX_H

#include "time.h"
#include "usual_matrix.h"
#include "diagonal_matrix.h"
#include "triangular_matrix.h"

enum MatrixType {
    USUAL, DIAGONAL, TRIANGULAR
};

struct BasicMatrix {
    enum MatrixType currentType;
    union {
        struct UsualMatrix* usual;
        struct DiagonalMatrix* diagonal;
        struct TriangularMatrix* triangular;
    };
    long long dimension;
};

void initialize(struct BasicMatrix *base);
void clear(struct BasicMatrix *base);
long double getAverage(struct BasicMatrix *base);

double generateNumber();
struct BasicMatrix* generateMatrix(long long dimension);
struct BasicMatrix* generateDiagonalMatrix(long long dimension);
struct BasicMatrix* generateTriangularMatrix(long long dimension);

#endif
