#ifndef AVS_BASIC_MATRIX_H
#define AVS_BASIC_MATRIX_H

#include <cstdio>

class BasicMatrix {
private:
    void readNumber(FILE *file);
protected:
    virtual void read(FILE *file);
    virtual void sort();
    long long dimension;
public:
    explicit BasicMatrix(long long input_dimension);
    ~BasicMatrix();

    static double generateNumber();
    static BasicMatrix& generateMatrix(long long dimension);
    static BasicMatrix& generateDiagonalMatrix(long long dimension);
    static BasicMatrix& generateTriangularMatrix(long long dimension);
};

#endif
