#ifndef AVS_BASIC_MATRIX_H
#define AVS_BASIC_MATRIX_H

#include <cstdlib>
#include <cstdio>
#include <cerrno>

class BasicMatrix {
public:
    long long dimension;

    explicit BasicMatrix(long long input_dimension);

    virtual void read(FILE *file);
    virtual void sort();
    virtual void print(FILE *file);
    virtual void generate();

    static double generateNumber(double minimum, double range_width);
    static int readInteger(FILE *file);
    static long long readDimension(FILE *file);
    static double readNumber(FILE *file);
};

#endif
