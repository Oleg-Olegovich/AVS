#ifndef AVS_IN_OUT_FUNCTIONS_H
#define AVS_IN_OUT_FUNCTIONS_H

#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
#include "float.h"
#include "time.h"
#include "basic_matrix.h"

int readInteger(FILE *file, int *number);
int readDimension(FILE *file, size_t *number);
int readNumber(FILE *file, double *number);
int readNumericArray(FILE *file, double *array, size_t dimension);
int readNumericMatrix(FILE *file, double **matrix, size_t dimension);
double generateNumber();
struct BasicMatrix generateMatrix();
struct BasicMatrix generateDiagonalMatrix();
struct BasicMatrix generateTriangularMatrix();
void printMatrix(FILE *file, double **, size_t dimension);
void printDiagonalMatrix(FILE *file, double *matrix, size_t dimension);
void printTriangularMatrix(FILE *file, double *matrix, size_t dimension);
void printInvalideNumberError();
void printInvalideDimensionError();
void printInvalideCommandLineError();
void printNonexistentFileError(char *file_path);
void printInvalidTypeError();
void printOkMessage(char *file_path);

#endif