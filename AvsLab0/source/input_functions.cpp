#include "input_functions.h"

int readNumber() {
try_read:
    std::cout << "Input number:\n";
    char* input;
    std::cin >> input;
    int number = 0;
    while (*input) {
        if (*input < '0' || *input > '9') {
            std::cerr << "Invalid input!\n";
            goto try_read;
        }
        number = 10 * number + *input++ - '0';
    }
    return number;
}

void readNumericArray(int *array) {
try_read:
    std::cout << "Input numbers (array):\n";
    char* input;
    std::cin >> input;
    while (*input) {
        if (*input == ' ') {
            ++array;
            continue;
        }
        if (*input < '0' || *input > '9') {
            std::cerr << "Invalid input!\n";
            goto try_read;
        }
        *array = 10 * *array + *input++;
    }
    return number;
}

void readNumericMatrix(int **matrix) {
    std::cout << "Input matrix line by line.\n";
    while (*matrix) {
        readNumericArray(*matrix++);
    }
    return number;
}
