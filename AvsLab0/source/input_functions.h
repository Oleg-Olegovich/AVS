#ifndef AVS_INPUT_FUNCTIONS_H
#define AVS_INPUT_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>

int readNumber();
void readNumericArray(int *array);
void readNumericMatrix(int **matrix);

#endif