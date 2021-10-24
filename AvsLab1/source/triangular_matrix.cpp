#include "triangular_matrix.h"

TriangularMatrix::TriangularMatrix(long long int input_dimension) : BasicMatrix(input_dimension) {
    long long length = dimension * (dimension - 1) / 2;
    matrix = new double[length];
}

TriangularMatrix::~TriangularMatrix() {
    delete[] matrix;
}

void TriangularMatrix::convertToTwoDimensional(double **matrix) {
    long long start_index_row = 0;
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            matrix[i][j] = (j < i ? this->matrix[start_index_row + j] : 0);
        }
        start_index_row += i;
    }
}

void TriangularMatrix::convertToArray(double **matrix) {
    for (long long i = 1, index = 0; i < dimension; ++i) {
        for (long long j = 0; j < i; ++j) {
            this->matrix[index++] = matrix[i][j];
        }
    }
}

void TriangularMatrix::sort() {
    UsualMatrix *usual = new UsualMatrix(dimension);
    convertToTwoDimensional(usual->matrix);
    usual->sort();
    convertToArray(usual->matrix);
    delete usual;
}

int TriangularMatrix::read(FILE *file) {
    long long length = dimension * (dimension - 1) / 2;
    for (long long i = 0; i < length; ++i) {
        if (readNumber(file, &matrix[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void TriangularMatrix::print(FILE *file) {
    long long start_index_row = 0;
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (j < i ? matrix[start_index_row + j] : 0));
            fprintf(file, "%c", ' ');
        }
        start_index_row += i;
        fprintf(file, "%c", '\n');
    }
}

void TriangularMatrix::generate() {
    for (long long i = 0; i < dimension; ++i) {
        matrix[i] = generateNumber(-100, 201);
    }
}
