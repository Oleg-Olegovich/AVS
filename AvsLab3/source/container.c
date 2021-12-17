#include "container.h"

const long double eps = 1e-8;

void add(Container *containerPtr, Matrix matrix) {
    containerPtr->data[containerPtr->size++] = matrix;
}

double getAverage(Matrix matrix) {
    double sum = 0;
    switch (matrix.tag) {
        case MATRIX_TAG_2D:
            for (int i = 0; i < matrix.size; i++) {
                for (int j = 0; j < matrix.size; j++) {
                    sum += getMatrixValue(matrix, i, j);
                }
            }
            break;
        case MATRIX_TAG_DIAGONAL:
            for (int i = 0; i < matrix.size; i++) {
                sum += getMatrixValue(matrix, i, i);
            }
            break;
        case MATRIX_TAG_LOW_TRIANGLE:
            for (int i = 0; i < matrix.size; i++) {
                for (int j = 0; j <= i; j++) {
                    sum += getMatrixValue(matrix, i, j);
                }
            }
            break;
    }
    int elementsCount = matrix.size * matrix.size;
    return sum / ((double) elementsCount);
}

void binarySearch(struct BasicMatrix *storage, long long length, long double mean,
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

void sort(Container *containerPtr) {
    for (int i = 0; i < containerPtr->size; i++) {
        for (int j = i + 1; j < containerPtr->size; j++) {
            if (getAverage(containerPtr->data[i]) > getAverage(containerPtr->data[j])) {
                Matrix tmp = containerPtr->data[i];
                containerPtr->data[i] = containerPtr->data[j];
                containerPtr->data[j] = tmp;
            }
        }
    }
}

void binaryInsertionSort(Container *container) {
  for (long long i = 1; i < container->size) {
    long long j = i - 1;
    long double selected_mean = getAverage(&container->data[i]);
    long long index = binarySearch((struct BasicMatrix *) container->data, container->size, selected_mean, 0, j);
    long double selected = container->data[i];
    while (j >= index) {
      container->data[j + 1] = container->data[j];
      --j;
    }
    container->data[j + 1] = selected;
  }
}