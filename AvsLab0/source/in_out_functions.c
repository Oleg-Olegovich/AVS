#include "in_out_functions.h"

int readNumber() {
    try_read:
    char* input;
    scanf(input);
    int number = 0;
    while (*input) {
        if (*input < '0' || *input > '9') {
            printf("Invalid input!\n");
            return 0;
        }
        number = 10 * number + *input++ - '0';
    }
    return number;
}

void readNumericArray(int *array) {
    try_read:
    printf("Input numbers (array):\n");
    char* input;
    scanf(input);
    while (*input) {
        if (*input == ' ') {
            ++array;
            continue;
        }
        if (*input < '0' || *input > '9') {
            printf("Invalid input!\n");
            goto try_read;
        }
        *array = 10 * *array + *input++;
    }
}

void readNumericMatrix(int **matrix) {
    printf("Input matrix line by line.\n");
    while (*matrix) {
        readNumericArray(*matrix++);
    }
}

int generateNumber() {
    return rand();
}

void printDiagonalMatrix(int *matrix, size_t dimension) {
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

void printArray(int *array) {
    while (*array) {
        //    std::cout << *array++ << ' ';
    }
    //std::cout << '\n';
}

void printMatrix(int **matrix) {
    while (*matrix) {
        printArray(*matrix++);
    }
}

void printTriangularMatrix(int *matrix, size_t dimension) {
    size_t start_index_row = 0;
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            //    std::cout << (j < i ? matrix[start_index_row + j] : '0') << ' ';
        }
        start_index_row += i;
        //std::cout << '\n';
    }
}
