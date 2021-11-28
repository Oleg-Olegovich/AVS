#include "container.h"

const long double eps = 1e-8;

/*
long double calculateArithmeticMean(const double *array, long long dimension) {
    // Используется тип с максимальной вместимостью, чтобы избежать переполнение.
    long double result = 0;
    for (long long i = 0; i < dimension; ++i) {
        result += array[i];
    }
    return result / dimension;
}

long long binarySearchInMatrix(const double **matrix, long long dimension, long double mean,
                    long long low, long long high) {
    if (high <= low) {
        return (mean + eps < calculateArithmeticMean(matrix[low], dimension))
               ? (low + 1) : low;
    }
    long long mid = (low + high) / 2;
    long double mid_value = calculateArithmeticMean(matrix[mid], dimension);
    if (fabsl(mean - mid_value) < eps) {
        return mid + 1;
    }
    if (mean + eps < mid_value) {
        return binarySearchInMatrix(matrix, dimension, mean, mid + 1, high);
    }
    return binarySearchInMatrix(matrix, dimension, mean, low, mid - 1);
}

void binaryInsertionSortMatrix(double **matrix, long long dimension) {
    for (long long i = 1; i < dimension; ++i) {
        long long j = i - 1;
        long double selected_mean = calculateArithmeticMean(matrix[i], dimension);
        long long index = binarySearchInMatrix((const double **)matrix, dimension, selected_mean, 0, j);
        double *selected = matrix[i];
        while (j >= index) {
            matrix[j + 1] = matrix[j];
            --j;
        }
        matrix[j + 1] = selected;
    }
}

long long binarySearchInArray(double *array, long long dimension, double item,
                    long long low, long long high) {
    if (high <= low) {
        return (item + eps < array[low]) ? (low + 1) : low;
    }
    long long mid = (low + high) / 2;
    if (fabsl(item - array[mid]) < eps) {
        return mid + 1;
    }
    if (item + eps < array[mid]) {
        return binarySearchInArray(array, dimension, item, mid + 1, high);
    }
    return binarySearchInArray(array, dimension, item, low, mid - 1);
}

void binaryInsertionSortArray(double *array, long long dimension) {
    for (long long i = 1; i < dimension; ++i) {
        long long j = i - 1;
        double selected = array[i];
        long long index = binarySearchInArray(array, dimension, selected, 0, j);
        while (j >= index) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = selected;
    }
}
 */

void binaryInsertionSort(Container *container) {
    switch (basic->currentType) {
        case USUAL:
            binaryInsertionSortMatrix(basic->usual->matrix, basic->dimension);
            break;
        case DIAGONAL:
            binaryInsertionSortArray(basic->diagonal->matrix, basic->dimension);
            break;
        case TRIANGULAR:
            double **matrix = convertToTwoDimensional(basic->triangular->matrix, basic->dimension);
            binaryInsertionSortMatrix(matrix, basic->dimension);
            free(basic->triangular->matrix);
            basic->triangular->matrix = convertToArray(matrix, basic->dimension);
            for (long long i = basic->dimension; i > -1; --i) {
                free(matrix[i]);
            }
            free(matrix);
            break;
    }
}