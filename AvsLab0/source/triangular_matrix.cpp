#include "triangular_matrix.h"

void printMatrix(int *matrix, int dimension) {
    int start_index_row = 0;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if (j < i) {
                cout << matrix[start_index_row + j];
            } else {
                std::cout << "0 ";
            }
        }
        start_index_row += i;
        std::cout << '\n';
    }
}