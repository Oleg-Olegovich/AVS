#include "sort.h"

const long double eps = 1e-8;

long double calculateArithmeticMean(const double *array, size_t dimension) {
    // Используется тип с максимальной вместимостью, так как
    // в массиве может быть любое число элементов.
    long double result = 0;
    for (size_t i = 0; i < dimension; ++i) {
        result += array[i];
    }
    return result / dimension;
}

size_t binarySearchInMatrix(double **matrix, size_t dimension, long double mean,
                    size_t low, size_t high) {
    if (high <= low) {
        return (mean > calculateArithmeticMean(matrix[low], dimension))
               ? (low + 1) : low;
    }
    size_t mid = (low + high) / 2;
    long double mid_value = calculateArithmeticMean(matrix[mid], dimension);
    if (fabsl(mean - mid_value) < eps) {
        return mid + 1;
    }
    if (mean > mid_value + eps) {
        return binarySearchInMatrix(matrix, dimension, mean, mid + 1, high);
    }
    return binarySearchInMatrix(matrix, dimension, mean, low, mid - 1);
}

void binaryInsertionSortMatrix(double **matrix, size_t dimension) {
    for (size_t i = 1; i < dimension; ++i) {
        size_t j = i - 1;
        long double selected_mean = calculateArithmeticMean(matrix[i], dimension);
        size_t index = binarySearchInMatrix(matrix, dimension, selected_mean, 0, j);
        while (j >= index) {
            matrix[j + 1] = matrix[j];
            if (j == 0) {
                break;
            }
            --j;
        }
        matrix[j + 1] = matrix[i];
    }
}

size_t binarySearchInArray(double *array, size_t dimension, double item,
                    size_t low, size_t high) {
    if (high <= low) {
        return (item > array[low]) ? (low + 1) : low;
    }
    size_t mid = (low + high) / 2;
    if (item == array[mid]) {
        return mid + 1;
    }
    if (item > array[mid]) {
        return binarySearchInArray(array, dimension, item, mid + 1, high);
    }
    return binarySearchInArray(array, dimension, item, low, mid - 1);
}

void binaryInsertionSortArray(double *array, size_t dimension) {
    for (size_t i = 1; i < dimension; ++i) {
        size_t j = i - 1;
        double selected = array[i];
        size_t index = binarySearchInArray(array, dimension, selected, 0, j);
        while (j >= index)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = array[i];
    }
}

void binaryInsertionSort(struct BasicMatrix basic) {
    switch (basic.currentType) {
        case USUAL:
            binaryInsertionSortMatrix(basic.usual->matrix, basic.dimension);
            break;
        case DIAGONAL:
            binaryInsertionSortArray(basic.diagonal->matrix, basic.dimension);
            break;
        case TRIANGULAR:
            double **matrix = convertToTwoDimensional(basic.triangular->matrix, basic.dimension);
            binaryInsertionSortMatrix(matrix, basic.dimension);
            free(basic.triangular->matrix);
            basic.triangular->matrix = convertToArray(matrix, basic.dimension);
            for (int i = 0; i < basic.dimension; ++i) {
                free(*matrix);
            }
            free(matrix);
            break;
    }
}
