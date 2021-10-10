#include "usual_matrix.h"

void printArray(int *array) {
    while (*array) {
        std::cout << *array++ << ' ';
    }
    std::cout << '\n';
}

void printMatrix(int **matrix) {
    while (*matrix) {
        printArray(*matrix++);
    }
}
