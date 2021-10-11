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
    //return rand();
}

void printDiagonalMatrix(char *filepath, double *matrix, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            if (i == j) {
                //    std::cout << matrix[i] << ' ';
            } else {
                //    std::cout << "0 ";
            }
        }
        //cout << '\n';
    }
}

void printArray(char *filepath, double *array) {
    while (*array) {
        //    std::cout << *array++ << ' ';
    }
    //std::cout << '\n';
}

void printMatrix(char *filepath, double **matrix) {
    while (*matrix) {
        printArray(filepath, *matrix++);
    }
}

void printTriangularMatrix(char *file_path, double *matrix, size_t dimension) {
    FILE *file = fopen(file_path, "w");
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (j < i ? matrix[start_index_row + j] : '0'));
        }
        start_index_row += i;
        fprintf(file, "%с", '\n');
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
    printf("Expected: \"usual\", \"diagonal\" or \"triangular\".\n");
}

void printOkMessage(char *file_path) {
    printf("The program was executed without errors. The output is in this file:\n");
    printf("%s", file_path);
}
