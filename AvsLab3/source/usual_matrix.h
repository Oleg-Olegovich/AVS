#ifndef AVS3_USUAL_MATRIX_H
#define AVS3_USUAL_MATRIX_H

#include "stdlib.h"
#include "float.h"

struct UsualMatrix {
    double **matrix;
};

void initializeUsual(struct UsualMatrix **usual, long long dimension);
void clearUsual(struct UsualMatrix **usual, long long dimension);
long double getUsualAverage(struct UsualMatrix *usual, long long dimension);

#endif
