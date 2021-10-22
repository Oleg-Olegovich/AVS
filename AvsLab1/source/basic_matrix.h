#ifndef AVS_BASIC_MATRIX_H
#define AVS_BASIC_MATRIX_H

#include <cstdio>

class BasicMatrix {
protected:
    long long dimension;

    void readNumber(FILE *file);
    virtual void read(FILE *file);
    virtual void sort();
    virtual void print(FILE *file);

public:
    explicit BasicMatrix(long long input_dimension);
    ~BasicMatrix();

    static double generateNumber();
    static BasicMatrix& generateMatrix(long long dimension);
    static BasicMatrix& generateDiagonalMatrix(long long dimension);
    static BasicMatrix& generateTriangularMatrix(long long dimension);
};

#endif
