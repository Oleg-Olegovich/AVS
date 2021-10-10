#include "diagonal_matrix.h"

void printMatrix(int *matrix, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if (i == j) {
                std::cout << *matrix << ' ';
            } else {
                std::cout << "0 ";
            }
        }
        cout << '\n';
    }
}