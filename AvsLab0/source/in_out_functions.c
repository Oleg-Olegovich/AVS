#include "in_out_functions.h"

int readInteger(FILE *file, int *number) {
    fscanf(file, "%u", *number);
    return 1;
}

int readDimension(FILE *file, size_t *number) {
    fscanf(file, "%u", *number);
    return 1;
}

int readNumber(FILE *file, double *number) {
    fscanf(file, "%f", *number);
    return 1;
}

int readNumericArray(FILE *file, double *array, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        if (readNumber(file, &array[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

int readNumericMatrix(FILE *file, double **matrix, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            if (readNumber(file, &matrix[i][j]) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

double generateNumber() {
    srand(time(0));
    return -100.0 + 201.0 * rand();
}

struct BasicMatrix generateMatrix() {
    struct BasicMatrix basic;
    basic.currentType = USUAL;
    srand(time(0));
    basic.dimension = 1 + rand() % 10;
    double **matrix = malloc(basic.dimension * sizeof(*matrix));
    for (size_t i = 0; i < basic.dimension; ++i) {
        matrix[i] = malloc(basic.dimension * sizeof(**matrix));
        for (size_t j = 0; j < basic.dimension; ++j) {
            matrix[i][j] = generateNumber();
        }
    }
    basic.usual->matrix = matrix;
    return basic;
}

struct BasicMatrix generateDiagonalMatrix() {
    struct BasicMatrix basic;
    basic.currentType = DIAGONAL;
    srand(time(0));
    basic.dimension = 1 + rand() % 10;
    double *matrix = malloc(basic.dimension * sizeof(*matrix));
    for (size_t i = 0; i < basic.dimension; ++i) {
        matrix[i] = generateNumber();
    }
    basic.diagonal->matrix = matrix;
    return basic;
}

struct BasicMatrix generateTriangularMatrix() {
    struct BasicMatrix basic;
    basic.currentType = TRIANGULAR;
    srand(time(0));
    basic.dimension = 1 + rand() % 10;
    size_t size = basic.dimension * (basic.dimension - 1) / 2;
    double *matrix = malloc(size * sizeof(*matrix));
    for (size_t i = 0; i < size; ++i) {
        matrix[i] = generateNumber();
    }
    basic.triangular->matrix = matrix;
    return basic;
}

void printMatrix(FILE *file, double **matrix, size_t dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", matrix[i][j]);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
    }
}

void printDiagonalMatrix(FILE *file, double *matrix, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (i == j ? matrix[i] : '0'));
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
    }
}

void printTriangularMatrix(FILE *file, double *matrix, size_t dimension) {
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (j < i ? matrix[start_index_row + j] : '0'));
            fprintf(file, "%c", ' ');
        }
        start_index_row += i;
        fprintf(file, "%c", '\n');
    }
}

void printInvalideNumberError() {
    printf("Invalid number!\n");
    printf("A real number in the range is expected 1,7E +/- 308.\n");
}

void printInvalideDimensionError() {
    printf("Invalid dimension!\n");
    printf("A natural number is expected.\n");
}

void printInvalideCommandLineError() {
    printf("Invalide command line! One of two options is expected:\n");
    printf("command -f <input file name> <output file name>\n");
    printf("command -r <matrix type> <output file name>\n");
}

void printNonexistentFileError(char *file_path) {
    printf("This file doesn't exist:\n");
    printf("%s", file_path);
    printf("%c", '\n');
}

void printInvalidTypeError() {
    printf("Invalid matrix type!\n");
    printf("Expected: \"0\" - usual, \"1\" - diagonal or \"2\" - triangular.\n");
}

void printOkMessage(char *file_path) {
    printf("The program was executed without errors. The output is in this file:\n");
    printf("%s", file_path);
    printf("%c", '\n');
}
