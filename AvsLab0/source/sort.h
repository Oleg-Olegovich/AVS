#ifndef AVS_SORT_H
#define AVS_SORT_H

#include "stdint.h"
#include "float.h"
#include "math.h"
#include "basic_matrix.h"

long double calculateArithmeticMean(int *array, size_t dimension);

size_t binarySearchInMatrix(int **matrix, size_t dimension, long double mean,
                            size_t low, size_t high);

void binaryInsertionSortMatrix(int **matrix, size_t dimension);

size_t binarySearchInArray(int *array, size_t dimension, int item,
                           size_t low, size_t high);

void binaryInsertionSortArray(int *array, size_t dimension);

void binaryInsertionSort(struct BasicMatrix basic);

#endif