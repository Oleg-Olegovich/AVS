#ifndef AVS_USUAL_MATRIX_H
#define AVS_USUAL_MATRIX_H

#include "stdlib.h"
#include "stddef.h"
#include "float.h"

struct UsualMatrix {
    double **matrix;
};

void initializeUsual(struct UsualMatrix *usual, size_t dimension);
void clearUsual(struct UsualMatrix *usual, size_t dimension);

#endif
