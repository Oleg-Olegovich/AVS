#ifndef AVS_TRIANGULAR_MATRIX_H
#define AVS_TRIANGULAR_MATRIX_H

struct TriangularMatrix {
    // Значения матрицы записываются в одномерный массив построчно.
    int *matrix;
};

void printMatrix(int *matrix, int dimension);

#endif
