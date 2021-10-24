#include "diagonal_matrix.h"

DiagonalMatrix::DiagonalMatrix(long long dimension) :
        BasicMatrix(dimension) {
    matrix = new double[dimension];
}

DiagonalMatrix::~DiagonalMatrix() {
    delete[] matrix;
}

long long binarySearch(double *array, long long dimension, double item,
                       long long low, long long high) {
    if (high <= low) {
        return (item + eps < array[low]) ? (low + 1) : low;
    }
    long long mid = (low + high) / 2;
    if (fabsl(item - array[mid]) < eps) {
        return mid + 1;
    }
    if (item + eps < array[mid]) {
        return binarySearch(array, dimension, item, mid + 1, high);
    }
    return binarySearch(array, dimension, item, low, mid - 1);
}

void DiagonalMatrix::sort() {
    for (long long i = 1; i < dimension; ++i) {
        long long j = i - 1;
        double selected = matrix[i];
        long long index = binarySearch(matrix, dimension, selected, 0, j);
        while (j >= index) {
            matrix[j + 1] = matrix[j];
            --j;
        }
        matrix[j + 1] = selected;
    }
}

int DiagonalMatrix::read(FILE *file) {
    for (long long i = 0; i < dimension; ++i) {
        if (readNumber(file, &matrix[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

void DiagonalMatrix::print(FILE *file) {
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (i == j ? matrix[i] : 0));
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
    }
}

void DiagonalMatrix::generate() {
    for (long long i = 0; i < dimension; ++i) {
        matrix[i] = generateNumber(-100, 201);
    }
}
