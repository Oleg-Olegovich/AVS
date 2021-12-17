#ifndef INC_1_CONTAINER_H
#define INC_1_CONTAINER_H

#include "matrix.h"

struct ContainerTag;

typedef struct ContainerTag {
    int size;
    Matrix data[10005];
} Container;

extern void addContainer(void* containerPtr, void *matrix);

extern void sortContainer(void* containerPtr);

#endif //INC_1_CONTAINER_H
