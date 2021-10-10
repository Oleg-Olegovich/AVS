#include "sort.h"

const long double eps = 1e-8;

long double calculateArithmeticMean(int *array, size_t dimension) {
    // Используется тип с максимальной вместимостью, так как
    // в массиве может быть любое число элементов.
    long double result = 0;
    for (size_t i = 0; i < dimension; ++i) {
        result += array[i];
    }
    return result / dimension;
}

size_t binarySearch(int **matrix, size_t dimension, long double mean,
                    size_t low, size_t high) {
    if (high <= low) {
        return (mean > calculateArithmeticMean(matrix[low], dimension))
                 ? (low + 1) : low;
    }
    size_t mid = (low + high) / 2;
    long double mid_value = calculateArithmeticMean(matrix[mid], dimension);
    if (fabs(mean - mid_value) < eps) {
        return mid + 1;
    }
    if (mean > mid_value + eps) {
        return binarySearch(matrix, dimension, mean, mid + 1, high);
    }
    return binarySearch(matrix, dimension, mean, low, mid - 1);
}

void binaryInsertionSort(int **matrix, size_t dimension) {
    for (size_t i = 1; i < dimension; ++i) {
        size_t j = i - 1;
        long double selected_mean = calculateArithmeticMean(matrix[i], dimension);
        size_t index = binarySearch(matrix, dimension, selected_mean, 0, j);
        while (j >= index)
        {
            matrix[j + 1] = matrix[j];
            --j;
        }
        matrix[j + 1] = matrix[i];
    }
}

size_t binarySearch(int *array, size_t dimension, int item,
                    size_t low, size_t high) {
    if (high <= low) {
        return (item > array[low]) ? (low + 1) : low;
    }
    size_t mid = (low + high) / 2;
    if (item == array[mid]) {
        return mid + 1;
    }
    if (item > array[mid]) {
        return binarySearch(array, dimension, item, mid + 1, high);
    }
    return binarySearch(array, dimension, item, low, mid - 1);
}

void binaryInsertionSort(int *array, size_t dimension) {
    for (size_t i = 1; i < dimension; ++i) {
        size_t j = i - 1;
        int selected = array[i];
        size_t index = binarySearch(array, dimension, selected, 0, j);
        while (j >= index)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = array[i];
    }
}

void binaryInsertionSort(BasicMatrix basic) {
    switch (basic.currentType) {
        case USUAL:
            binaryInsertionSort(basic.usual->matrix, basic.dimension);
            break;
        case DIAGONAL:
            binaryInsertionSort(basic.diagonal->matrix, basic.dimension);
            break;
        case TRIANGULAR:
            int **matrix = convertToTwoDimensional(basic.triangular->matrix, basic.dimension);
            binaryInsertionSort(matrix, basic.dimension);
            basic.triangular->matrix = convertToArray(matrix, basic.dimension);
            break;
    }
}
