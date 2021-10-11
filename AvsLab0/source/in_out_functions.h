#ifndef AVS_IN_OUT_FUNCTIONS_H
#define AVS_IN_OUT_FUNCTIONS_H

#include "stdio.h"
#include "stdint.h"

int readNumber();
void readNumericArray(int *array);
void readNumericMatrix(int **matrix);
void printArray(int *array);
void printMatrix(int **matrix);
void printDiagonalMatrix(int *matrix, size_t dimension);
void printTriangularMatrix(int *matrix, size_t dimension);

#endif