#ifndef AVSLAB1_USUAL_MATRIX_H
#define AVSLAB1_USUAL_MATRIX_H

#include "basic_matrix.h"

class UsualMatrix : public BasicMatrix {
public:
    double **matrix;

    explicit UsualMatrix(long long dimension);
    ~UsualMatrix();

    int read(FILE *file) override;
    void sort() override;
    void print(FILE *file) override;
    void generate() override;
};

#endif
