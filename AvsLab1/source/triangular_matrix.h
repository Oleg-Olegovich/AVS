#ifndef AVSLAB1_TRIANGULAR_MATRIX_H
#define AVSLAB1_TRIANGULAR_MATRIX_H

#include "basic_matrix.h"
#include "usual_matrix.h"

class TriangularMatrix : public BasicMatrix {
public:
    double *matrix;

    explicit TriangularMatrix(long long input_dimension);
    ~TriangularMatrix();
    void convertToTwoDimensional(double **matrix);
    void convertToArray(double **matrix);

    int read(FILE *file) override;
    void sort() override;
    void print(FILE *file) override;
    void generate() override;
};

#endif
