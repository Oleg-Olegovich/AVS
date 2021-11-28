#ifndef AVSLAB3_CONTAINER_H
#define AVSLAB3_CONTAINER_H

#include "basic_matrix.h"

struct Container {
    long long length;
    BasicMatrix *storage;
};

struct Container *generateContainer(long long length);
void binarySearch(BasicMatrix *storage, long long length, long double mean,
                  long long low, long long high);
void binaryInsertionSort(Container *container);

#endif
