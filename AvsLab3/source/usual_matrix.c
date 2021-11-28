#include "usual_matrix.h"

void initializeUsual(struct UsualMatrix **usual, long long dimension) {
    *usual = (struct UsualMatrix*)malloc(sizeof(struct UsualMatrix));
    (*usual)->matrix = (double**)malloc(dimension * sizeof(double*));
    for (long long i = 0; i < dimension; ++i) {
        (*usual)->matrix[i] = (double*)malloc(dimension * sizeof(double));
    }
}

void clearUsual(struct UsualMatrix **usual, long long dimension) {
    for (long long i = dimension - 1; i > -1; --i) {
        free((*usual)->matrix[i]);
    }
    free((*usual)->matrix);
    free(*usual);
}

long double getUsualAverage(struct UsualMatrix *usual, long long dimension) {
    long double result = 0;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            result += usual->matrix[i][j];
        }
    }
    return result / dimension / dimension;
}