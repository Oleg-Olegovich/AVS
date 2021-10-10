#ifndef AVS_BASIC_MATRIX_H
#define AVS_BASIC_MATRIX_H

#include "usual_matrix.h"
#include "diagonal_matrix.h"
#include "triangular_matrix.h"

enum MatrixType {
    USUAL, DIAGONAL, TRIANGULAR
};

struct BasicMatrix {
    enum MatrixType currentType;
    union {
        UsualMatrix* usual;
        DiagonalMatrix* diagonal;
        TriangularMatrix* triangular;
    };
    size_t dimension;
};

#endif
