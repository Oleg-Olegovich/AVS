#include "usual_matrix.h"

void initializeUsual(struct UsualMatrix **usual, size_t dimension) {
    *usual = (struct UsualMatrix*)malloc(sizeof(struct UsualMatrix));
    (*usual)->matrix = (double**)malloc(dimension * sizeof(double*));
    for (size_t i = 0; i < dimension; ++i) {
        (*usual)->matrix[i] = (double*)malloc(dimension * sizeof(double));
    }
}

void clearUsual(struct UsualMatrix **usual, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        free((*usual)->matrix[i]);
    }
    free((*usual)->matrix);
    free(*usual);
}
