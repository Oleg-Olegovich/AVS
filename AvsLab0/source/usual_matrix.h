#ifndef AVS_USUAL_MATRIX_H
#define AVS_USUAL_MATRIX_H

#include "stdlib.h"
#include "float.h"

struct UsualMatrix {
    double **matrix;
};

void initializeUsual(struct UsualMatrix **usual, long long dimension);
void clearUsual(struct UsualMatrix **usual, long long dimension);

#endif
