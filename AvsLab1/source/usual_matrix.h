#ifndef AVSLAB1_USUAL_MATRIX_H
#define AVSLAB1_USUAL_MATRIX_H

#include "basic_matrix.h"

class UsualMatrix : public BasicMatrix {
private:
    double **matrix;

public:
    UsualMatrix(long long dimension);
    ~UsualMatrix();
    virtual void read(const ifstream &file);
    virtual void sort();
    virtual void print(const ofstream &file);
    virtual void generate();
};

#endif
