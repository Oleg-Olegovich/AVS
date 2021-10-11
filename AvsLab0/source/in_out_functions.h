#ifndef AVS_IN_OUT_FUNCTIONS_H
#define AVS_IN_OUT_FUNCTIONS_H

#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
#include "float.h"
#include "time.h"
#include "basic_matrix.h"

int readNumber();
int readNumericArray(double *array);
int readNumericMatrix(double **matrix);
double generateNumber();
struct UsualMatrix generateMatrix();
struct DiagonalMatrix generateDiagonalMatrix();
struct TriangularMatrix generateTriangularMatrix();
void printMatrix(FILE *file, double **matrix);
void printDiagonalMatrix(FILE *file, double *matrix, size_t dimension);
void printTriangularMatrix(FILE *file, double *matrix, size_t dimension);
void printInvalideNumberError();
void printInvalideDimensionError();
void printInvalideCommandLineError();
void printNonexistentFileError(char *file_path);
void printInvalidTypeError();
void printOkMessage(char *file_path);

#endif