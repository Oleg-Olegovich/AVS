#include "in_out_functions.h"

int readNumber(double *number) {
    char* input;
    scanf(input);
    while (*input) {
        if (*input < '0' || *input > '9') {
            return 0;
        }
        *number = 10 * (*number) + *input++ - '0';
    }
    return 1;
}

int readNumericArray(double *array) {
    printf("Input numbers (array):\n");
    char* input;
    scanf(input);
    while (*input) {
        if (*input == ' ') {
            ++array;
            continue;
        }
        if (*input < '0' || *input > '9') {
            return 0;
        }
        *array = 10 * *array + *input++;
    }
    return 1;
}

int readNumericMatrix(double **matrix) {
    printf("Input matrix line by line.\n");
    while (*matrix) {
        if(readNumericArray(*matrix++) == 0) {
            return 0;
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
    for (int i = 0; i < basic.dimension; ++i) {
        matrix[i] = malloc(basic.dimension * sizeof(**matrix));
        for (int j = 0; j < basic.dimension; ++j) {
            matrix[i][j] = generateNumber();
        }
    }
    basic.usual->matrix = matrix;
    return basic;
}

struct DiagonalMatrix generateDiagonalMatrix() {
    srand(time(0));
    int dimension = 1 + rand() % 10;
}

struct TriangularMatrix generateTriangularMatrix() {
    srand(time(0));
    int dimension = 1 + rand() % 10;
}

void printMatrix(FILE *file, double **matrix) {
    while (*matrix) {
        while (**matrix) {
            fprintf(file, "%lf", **matrix++);
        }
        fprintf(file, "%c", '\n');
        ++matrix;
    }
}

void printDiagonalMatrix(FILE *file, double *matrix, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (i == j ? matrix[i] : '0'));
        }
        fprintf(file, "%c", '\n');
    }
}

void printTriangularMatrix(FILE *file, double *matrix, size_t dimension) {
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (j < i ? matrix[start_index_row + j] : '0'));
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
    printf("command -f <input file name> <output file name>");
    printf("command -r <output file name>");
}

void printNonexistentFileError(char *file_path) {
    printf("This file doesn't exist:\n");
    printf("%s", file_path);
}

void printInvalidTypeError() {
    printf("Invalid matrix type!\n");
    printf("Expected: \"0\" - usual, \"1\" - diagonal or \"2\" - triangular.\n");
}

void printOkMessage(char *file_path) {
    printf("The program was executed without errors. The output is in this file:\n");
    printf("%s", file_path);
}
