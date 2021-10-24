#ifndef AVSLAB1_DIAGONAL_MATRIX_H
#define AVSLAB1_DIAGONAL_MATRIX_H

#include "basic_matrix.h"

class DiagonalMatrix : public BasicMatrix {
public:
    double *matrix;

    explicit DiagonalMatrix(long long input_dimension);
    ~DiagonalMatrix();

    int read(FILE *file) override;
    void sort() override;
    void print(FILE *file) override;
    void generate() override;
};

#endif
