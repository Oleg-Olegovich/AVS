#include "usual_matrix.h"

UsualMatrix::UsualMatrix(long long dimension) :
        BasicMatrix(dimension) {
    matrix = new double*[dimension];
    for (long long i = 0; i < dimension; ++i) {
        matrix[i] = new double[dimension];
    }
}

UsualMatrix::~UsualMatrix() {
    for (long long i = 0; i < dimension; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

long double calculateArithmeticMean(const double *array, long long dimension) {
    // Используется тип с максимальной вместимостью, чтобы избежать переполнение.
    long double result = 0;
    for (long long i = 0; i < dimension; ++i) {
        result += array[i];
    }
    return result / dimension;
}

long long binarySearch(const double **matrix, long long dimension, long double mean,
                       long long low, long long high) {
    if (high <= low) {
        return (mean + eps < calculateArithmeticMean(matrix[low], dimension))
               ? (low + 1) : low;
    }
    long long mid = (low + high) / 2;
    long double mid_value = calculateArithmeticMean(matrix[mid], dimension);
    if (fabsl(mean - mid_value) < eps) {
        return mid + 1;
    }
    if (mean + eps < mid_value) {
        return binarySearch(matrix, dimension, mean, mid + 1, high);
    }
    return binarySearch(matrix, dimension, mean, low, mid - 1);
}

void UsualMatrix::sort() {
    for (long long i = 1; i < dimension; ++i) {
        long long j = i - 1;
        long double selected_mean = calculateArithmeticMean(matrix[i], dimension);
        long long index = binarySearch((const double **) matrix, dimension, selected_mean, 0, j);
        double *selected = matrix[i];
        while (j >= index) {
            matrix[j + 1] = matrix[j];
            --j;
        }
        matrix[j + 1] = selected;
    }
}

int UsualMatrix::read(FILE *file) {
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            if (readNumber(file, &matrix[i][j]) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

void UsualMatrix::print(FILE *file) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", matrix[i][j]);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
    }
}

void UsualMatrix::generate() {
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            matrix[i][j] = generateNumber(-100, 201);
        }
    }
}
