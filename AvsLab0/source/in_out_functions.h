#ifndef AVS_IN_OUT_FUNCTIONS_H
#define AVS_IN_OUT_FUNCTIONS_H

#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
#include "float.h"
#include "errno.h"
#include "basic_matrix.h"

int readInteger(FILE *file, int *number);
int readDimension(FILE *file, long long *number);
int readNumber(FILE *file, double *number);
int readNumericArray(FILE *file, double *array, long long dimension);
int readNumericMatrix(FILE *file, double **matrix, long long dimension);
void printMatrix(FILE *file, double **, long long dimension);
void printDiagonalMatrix(FILE *file, double *matrix, long long dimension);
void printTriangularMatrix(FILE *file, double *matrix, long long dimension);
void printInvalideNumberError();
void printInvalideDimensionError();
void printInvalideCommandLineError();
void printNonexistentFileError(char *file_path);
void printInvalidTypeError();
void printOkMessage(char *file_path);

#endif