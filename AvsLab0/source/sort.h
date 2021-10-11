#ifndef AVS_SORT_H
#define AVS_SORT_H

#include "float.h"
#include "math.h"
#include "basic_matrix.h"

long double calculateArithmeticMean(const double *array, size_t dimension);

size_t binarySearchInMatrix(double **matrix, size_t dimension, long double mean,
                            size_t low, size_t high);

void binaryInsertionSortMatrix(double **matrix, size_t dimension);

size_t binarySearchInArray(double *array, size_t dimension, double item,
                           size_t low, size_t high);

void binaryInsertionSortArray(double *array, size_t dimension);

void binaryInsertionSort(struct BasicMatrix basic);

#endif