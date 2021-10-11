#include "string.h"
#include "sys/stat.h"
#include "in_out_functions.h"
#include "sort.h"

int fileExists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0 ? 1 : 0);
}

int fileProcessing(char* input_path, char* output_path) {
    FILE *input = fopen(input_path, "w");
    FILE *output = fopen(output_path, "r");
    int *type;
    if (readInteger(input, type) == 0) {
        printInvalidTypeError();
        return 1;
    }
    int *dimension;
    if (readInteger(input, dimension) == 0) {
        printInvalideDimensionError();
        return 1;
    }
    struct BasicMatrix base;
    base.dimension = *dimension;
    switch (*type) {
        case 0:
            base.usual->matrix = malloc(base.dimension * sizeof(*(base.usual->matrix)));
            for (size_t i = 0; i < base.dimension; ++i) {
                base.usual->matrix[i] = malloc(base.dimension * sizeof(**(base.usual->matrix)));
            }
            if (readNumericMatrix(input, base.usual->matrix, base.dimension) == 0) {
                return 1;
            }
            fprintf(output, "%s", "Matrix before sorting:\n");
            printMatrix(output, base.usual->matrix, base.dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printMatrix(output, base.usual->matrix, base.dimension);
            for (int i = 0; i < base.dimension; ++i) {
                free(*(base.usual->matrix));
            }
            free(base.usual->matrix);
            break;
        case 1:
            base.diagonal->matrix = malloc(base.dimension * sizeof(*(base.diagonal->matrix)));
            if (readNumericArray(input, base.diagonal->matrix, base.dimension) == 0) {
                return 1;
            }
            fprintf(output, "%s", "Matrix before sorting:\n");
            printDiagonalMatrix(output, base.diagonal->matrix, base.dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printDiagonalMatrix(output, base.diagonal->matrix, base.dimension);
            free(base.diagonal->matrix);
            break;
        case 2:
            size_t size = base.dimension * (base.dimension - 1) / 2;
            base.triangular->matrix = malloc(size * sizeof(*(base.triangular->matrix)));
            if (readNumericArray(input, base.triangular->matrix, size) == 0) {
                return 1;
            }
            fprintf(output, "%s", "Matrix before sorting:\n");
            printTriangularMatrix(output, base.triangular->matrix, base.dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printTriangularMatrix(output, base.triangular->matrix, base.dimension);
            free(base.triangular->matrix);
            break;
        default:
            printInvalidTypeError();
            return 1;
    }
    fclose(input);
    fclose(output);
    return 0;
}

int generateProcessing(char *matrix_type, char *output_path) {
    FILE *output = fopen(output_path, "r");
    int type = matrix_type[0] - '0';
    struct BasicMatrix base;
    switch (type) {
        case 0:
            base = generateMatrix();
            fprintf(output, "%s", "Matrix before sorting:\n");
            printMatrix(output, base.usual->matrix, base.dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printMatrix(output, base.usual->matrix, base.dimension);
            free(base.usual->matrix);
            break;
        case 1:
            base = generateDiagonalMatrix();
            fprintf(output, "%s", "Matrix before sorting:\n");
            printDiagonalMatrix(output, base.diagonal->matrix, base.dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printDiagonalMatrix(output, base.diagonal->matrix, base.dimension);
            free(base.diagonal->matrix);
            break;
        case 2:
            base = generateTriangularMatrix();
            fprintf(output, "%s", "Matrix before sorting:\n");
            printTriangularMatrix(output, base.triangular->matrix, base.dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printTriangularMatrix(output, base.triangular->matrix, base.dimension);
            free(base.triangular->matrix);
            break;
        default:
            printInvalidTypeError();
            return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printInvalideCommandLineError();
        return 1;
    }
    if (fileExists(argv[3]) == 0) {
        printNonexistentFileError(argv[3]);
        return 1;
    }
    if (strcmp(argv[1], "-f") == 0) {
        if (fileExists(argv[2]) == 0) {
            printNonexistentFileError(argv[2]);
            return 1;
        }
        return fileProcessing(argv[2], argv[3]);
    }
    if (strcmp(argv[1], "-r") == 0) {
        return generateProcessing(argv[2], argv[3]);
    }
    printInvalideCommandLineError();
    return 1;
}
