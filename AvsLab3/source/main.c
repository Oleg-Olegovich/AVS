#include "string.h"
#include "sys/stat.h"
#include "in_out_functions.h"
#include "sort.h"

int fileExists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0 ? 1 : 0);
}

int fileProcessing(char* input_path, char* output_path) {
    FILE *input = fopen(input_path, "r");
    FILE *output = fopen(output_path, "w");
    int type;
    if (readInteger(input, &type) == 0) {
        printInvalidTypeError();
        fclose(input);
        fclose(output);
        free(output_path);
        return 1;
    }
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    if (readDimension(input, &(base->dimension)) == 0) {
        printInvalideDimensionError();
        fclose(input);
        fclose(output);
        free(output_path);
        return 1;
    }
    switch (type) {
        case 0:
            base->currentType = USUAL;
            initialize(base);
            if (readNumericMatrix(input, base->usual->matrix, base->dimension) == 0) {
                printInvalideNumberError();
                clear(base);
                fclose(input);
                fclose(output);
                free(output_path);
                return 1;
            }
            fprintf(output, "%s", "Matrix before sorting:\n");
            printMatrix(output, base->usual->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printMatrix(output, base->usual->matrix, base->dimension);
            break;
        case 1:
            base->currentType = DIAGONAL;
            initialize(base);
            if (readNumericArray(input, base->diagonal->matrix, base->dimension) == 0) {
                printInvalideNumberError();
                clear(base);
                fclose(input);
                fclose(output);
                free(output_path);
                return 1;
            }
            fprintf(output, "%s", "Matrix before sorting:\n");
            printDiagonalMatrix(output, base->diagonal->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printDiagonalMatrix(output, base->diagonal->matrix, base->dimension);
            break;
        case 2:
            base->currentType = TRIANGULAR;
            initialize(base);
            if (readNumericArray(input, base->triangular->matrix,
                                 base->dimension * (base->dimension - 1) / 2) == 0) {
                printInvalideNumberError();
                clear(base);
                fclose(input);
                fclose(output);
                free(output_path);
                return 1;
            }
            fprintf(output, "%s", "Matrix before sorting:\n");
            printTriangularMatrix(output, base->triangular->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printTriangularMatrix(output, base->triangular->matrix, base->dimension);
            break;
        default:
            printInvalidTypeError();
            fclose(input);
            fclose(output);
            free(output_path);
            return 1;
    }
    clear(base);
    fclose(input);
    fclose(output);
    printOkMessage(output_path);
    free(output_path);
    return 0;
}

int generateProcessing(const char *matrix_type, const char *input_size, char *output_path) {
    FILE *output = fopen(output_path, "w");
    int type = matrix_type[0] - '0';
    char *end;
    long long dimension = strtoll(input_size, &end, 10);
    struct BasicMatrix* base;
    switch (type) {
        case 0:
            base = generateMatrix(dimension);
            fprintf(output, "%s", "Matrix before sorting:\n");
            printMatrix(output, base->usual->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printMatrix(output, base->usual->matrix, base->dimension);
            break;
        case 1:
            base = generateDiagonalMatrix(dimension);
            fprintf(output, "%s", "Matrix before sorting:\n");
            printDiagonalMatrix(output, base->diagonal->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printDiagonalMatrix(output, base->diagonal->matrix, base->dimension);
            break;
        case 2:
            base = generateTriangularMatrix(dimension);
            fprintf(output, "%s", "Matrix before sorting:\n");
            printTriangularMatrix(output, base->triangular->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printTriangularMatrix(output, base->triangular->matrix, base->dimension);
            break;
        default:
            printInvalidTypeError();
            fclose(output);
            free(output_path);
            return 1;
    }
    clear(base);
    fclose(output);
    printOkMessage(output_path);
    free(output_path);
    return 0;
}

int main(int argc, char* argv[]) {
    if (!(argc == 4 && strcmp(argv[1], "-f") == 0 || argc == 5 && strcmp(argv[1], "-r") == 0)) {
        printInvalideCommandLineError();
        return 1;
    }
    if (argc == 4) {
        if (fileExists(argv[2]) == 0) {
            printNonexistentFileError(argv[2]);
            return 1;
        }
        if (fileExists(argv[3]) == 0) {
            printNonexistentFileError(argv[3]);
            return 1;
        }
        char *output_path = (char*)malloc(strlen(argv[3]) * sizeof(char));
        strcpy(output_path, argv[3]);
        return fileProcessing(argv[2], output_path);
    }
    if (fileExists(argv[4]) == 0) {
        printNonexistentFileError(argv[4]);
        return 1;
    }
    char *output_path = (char*)malloc(strlen(argv[4]) * sizeof(char));
    strcpy(output_path, argv[4]);
    return generateProcessing(argv[2], argv[3], output_path);
}
