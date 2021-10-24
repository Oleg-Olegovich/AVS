#ifndef AVSLAB1_TRIANGULAR_MATRIX_H
#define AVSLAB1_TRIANGULAR_MATRIX_H

class triangular_matrix {
public:

    virtual void read(const ifstream &file);
    virtual void sort();
    virtual void print(const ofstream &file);
    virtual void generate();
};

#endif
