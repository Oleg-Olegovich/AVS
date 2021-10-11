#ifndef AVS_IN_OUT_FUNCTIONS_H
#define AVS_IN_OUT_FUNCTIONS_H

#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
#include "float.h"

int readNumber();
int readNumericArray(double *array);
int readNumericMatrix(double **matrix);
void printArray(char *filepath, double *array);
void printMatrix(char *filepath, double **matrix);
void printDiagonalMatrix(char *filepath, double *matrix, size_t dimension);
void printTriangularMatrix(char *filepath, double *matrix, size_t dimension);

#endif