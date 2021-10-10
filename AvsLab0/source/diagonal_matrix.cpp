#include "diagonal_matrix.h"

void printMatrix(int *matrix, size_t dimension) {
    for (size_t i = 0; i < dimension; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            if (i == j) {
                std::cout << matrix[i] << ' ';
            } else {
                std::cout << "0 ";
            }
        }
        cout << '\n';
    }
}