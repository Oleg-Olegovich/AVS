#include "container.h"

const long double eps = 1e-8;

struct Container *generateContainer(long long length) {
    // TO DO!!!
    return nullptr;
}

void binaryInsertionSort() {
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

void binarySearch(BasicMatrix *storage, long long length, long double mean,
                  long long low, long long high) {
    if (high <= low) {
        return (mean + eps < getAverage(&storage[low])) ? (low + 1) : low;
    }
    long long mid = (low + high) / 2;
    long double mid_value = getAverage(&storage[mid]));
    if (fabsl(mean - mid_value) < eps) {
        return mid + 1;
    }
    if (mean + eps < mid_value) {
        return binarySearch(storage, length, mean, mid + 1, high);
    }
    return binarySearch(storage, length, mean, low, mid - 1);
}

void binaryInsertionSort(Container *container) {
    for (long long i = 1; i < container->length) {
        long long j = i - 1;
        long double selected_mean = getAverage(&container->storage[i]);
        long long index = binarySearch(container->storage, container->length, selected_mean, 0, j);
        long double selected = container->storage[i];
        while (j >= index) {
            container->storage[j + 1] = container->storage[j];
            --j;
        }
        container->storage[j + 1] = selected;
    }
}