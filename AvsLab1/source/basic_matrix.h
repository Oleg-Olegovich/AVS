#ifndef AVS_BASIC_MATRIX_H
#define AVS_BASIC_MATRIX_H

#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <ctime>
#include <cstdint>
#include <cmath>
#include <cfloat>
#include "error_handler.h"

const long double eps = 1e-8;

class BasicMatrix {
protected:
    long long dimension;

public:
    explicit BasicMatrix(long long input_dimension);

    virtual int read(FILE *file);
    virtual void sort();
    virtual void print(FILE *file);
    virtual void generate();

    static double generateNumber(double minimum, double range_width);
    static int readInteger(FILE *file, int *number);
    static int readDimension(FILE *file, long long *number);
    static int readNumber(FILE *file, double *number);
    static BasicMatrix* initialize(int type, long long dimension);
    static void demonstrate(BasicMatrix *basic, FILE *output);
    static int demonstrate(char *input_path, char *output_path);
    static int demonstrate(const char *matrix_type, const char *input_size, char *output_path);
};

#endif
