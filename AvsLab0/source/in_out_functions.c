#include "in_out_functions.h"

int readInteger(FILE *file, int *number) {
    char *input[11], *end;
    fscanf(file, "%s", input);
    *number = (int)strtoul(input, &end, 10);
    if (errno == ERANGE) {
        return 0;
    }
    return 1;
}

int readDimension(FILE *file, long long *number) {
    char *input[21], *end;
    fscanf(file, "%s", input);
    *number = strtoll(input, &end, 10);
    if (errno == ERANGE || *number < 1) {
        return 0;
    }
    return 1;
}

int readNumber(FILE *file, double *number) {
    char *input, *end;
    input = malloc((DBL_MAX_10_EXP + 3) * sizeof(char));
    fscanf(file, "%s", input);
    *number = (double)strtod(input, &end);
    if (errno == ERANGE) {
        return 0;
    }
    if (*number == 0) {
        for (int i = 0; i < DBL_MAX_10_EXP + 3; ++i) {
            if (input[i] != '0' && input[i] != '.') {
                free(input);
                return 0;
            }
        }
    }
    free(input);
    return 1;
}

int readNumericArray(FILE *file, double *array, long long dimension) {
    for (long long i = 0; i < dimension; ++i) {
        if (readNumber(file, &array[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

int readNumericMatrix(FILE *file, double **matrix, long long dimension) {
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            if (readNumber(file, &matrix[i][j]) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void printMatrix(FILE *file, double **matrix, long long dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", matrix[i][j]);
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
    }
}

void printDiagonalMatrix(FILE *file, double *matrix, long long dimension) {
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            fprintf(file, "%lf", (i == j ? matrix[i] : 0));
            fprintf(file, "%c", ' ');
        }
        fprintf(file, "%c", '\n');
    }
}

void printTriangularMatrix(FILE *file, double *matrix, long long dimension) {
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
