#include "usual_matrix.h"

void initializeUsual(struct UsualMatrix *usual, size_t dimension) {
    usual = malloc(sizeof(*usual));
    usual->matrix = malloc(dimension * sizeof(*(usual->matrix)));
    for (size_t i = 0; i < dimension; ++i) {
        usual->matrix[i] = malloc(dimension * sizeof(**(usual->matrix)));
    }
}

void clearUsual(struct UsualMatrix *usual, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        free(usual->matrix[i]);
    }
    free(usual->matrix);
    free(usual);
}