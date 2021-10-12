#ifndef AVS_SORT_H
#define AVS_SORT_H

#include "float.h"
#include "math.h"
#include "basic_matrix.h"

long double calculateArithmeticMean(const double *array, long long dimension);
long long binarySearchInMatrix(const double **matrix, long long dimension, long double mean,
                            long long low, long long high);
void binaryInsertionSortMatrix(double **matrix, long long dimension);
long long binarySearchInArray(double *array, long long dimension, double item,
                           long long low, long long high);
void binaryInsertionSortArray(double *array, long long dimension);
void binaryInsertionSort(struct BasicMatrix *basic);

#endif