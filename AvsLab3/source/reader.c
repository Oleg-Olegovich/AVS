#include "reader.h"
#include "generator.h"
#include "matrix.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int INPUT_TYPE_MAX_LENGTH = 255;
const int MATRIX_TYPE_MAX_LENGTH = 255;

const char USUAL_INPUT_TYPE[] = "usual";
const char RANDOM_INPUT_TYPE[] = "random";

const char TWO_DIMENSIONS_MATRIX_TYPE[] = "2d";
const char LOW_TRIANGLE_MATRIX_TYPE[] = "low_triangle";
const char DIAGONAL_MATRIX_TYPE[] = "diagonal";

Matrix readMatrix2d(FILE *file) {
    int size;
    fscanf(file, "%d", &size);
    Matrix matrix = createMatrix2d(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double value;
            fscanf(file, "%lf", &value);
            setMatrixValue(matrix, i, j, value);
        }
    }
    return matrix;
}

Matrix readMatrixLowTriangle(FILE *file) {
    int size;
    fscanf(file, "%d", &size);
    Matrix matrix = createMatrixLowTriangle(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            double value;
            fscanf(file, "%lf", &value);
            setMatrixValue(matrix, i, j, value);
        }
    }
    return matrix;
}

Matrix readMatrixDiagonal(FILE *file) {
    int size;
    fscanf(file, "%d", &size);
    Matrix matrix = createMatrixDiagonal(size);
    for (int i = 0; i < size; i++) {
        double value;
        fscanf(file, "%lf", &value);
        setMatrixValue(matrix, i, i, value);
    }
    return matrix;
}

void readToUsual(FILE *file, Container *container) {
    while (!feof(file)) {
        char matrixType[MATRIX_TYPE_MAX_LENGTH];
        fscanf(file, "%s", matrixType);
        if (strcmp(matrixType, TWO_DIMENSIONS_MATRIX_TYPE) == 0) {
            Matrix m = readMatrix2d(file);
            addContainer(container, &m);
        } else if (strcmp(matrixType, LOW_TRIANGLE_MATRIX_TYPE) == 0) {
            Matrix m = readMatrixLowTriangle(file);
            addContainer(container, &m);
        } else if (strcmp(matrixType, DIAGONAL_MATRIX_TYPE) == 0) {
            Matrix m = readMatrixDiagonal(file);
            addContainer(container, &m);
        }
    }
}

void readToRandom(FILE *file, Container *container) {
    int randomKey;
    fscanf(file, "%d", &randomKey);
    srand(randomKey);

    int count;
    char unused[255];
    fscanf(file, "%s %d", unused, &count);
    generateMatricesTo(count, container);
}

void readTo(char *fileName, Container *container) {
    FILE *file = fopen(fileName, "r");
    if (file != NULL) {
        char inputType[INPUT_TYPE_MAX_LENGTH];
        fscanf(file, "%s", inputType);
        if (strcmp(inputType, USUAL_INPUT_TYPE) == 0) {
            readToUsual(file, container);
        } else if (strcmp(inputType, RANDOM_INPUT_TYPE) == 0) {
            readToRandom(file, container);
        }
        fclose(file);
    }
}
