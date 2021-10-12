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
        return 1;
    }
    struct BasicMatrix* base = (struct BasicMatrix*) malloc(sizeof(struct BasicMatrix));
    if (readDimension(input, &(base->dimension)) == 0) {
        printInvalideDimensionError();
        fclose(input);
        fclose(output);
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
            return 1;
    }
    printOkMessage(output_path);
    clear(base);
    fclose(input);
    fclose(output);
    return 0;
}

int generateProcessing(const char *matrix_type, char *output_path) {
    FILE *output = fopen(output_path, "w");
    int type = matrix_type[0] - '0';
    struct BasicMatrix* base;
    switch (type) {
        case 0:
            base = generateMatrix();
            fprintf(output, "%s", "Matrix before sorting:\n");
            printMatrix(output, base->usual->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printMatrix(output, base->usual->matrix, base->dimension);
            break;
        case 1:
            base = generateDiagonalMatrix();
            fprintf(output, "%s", "Matrix before sorting:\n");
            printDiagonalMatrix(output, base->diagonal->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printDiagonalMatrix(output, base->diagonal->matrix, base->dimension);
            break;
        case 2:
            base = generateTriangularMatrix();
            fprintf(output, "%s", "Matrix before sorting:\n");
            printTriangularMatrix(output, base->triangular->matrix, base->dimension);
            fprintf(output, "%s", "Matrix after sorting:\n");
            binaryInsertionSort(base);
            printTriangularMatrix(output, base->triangular->matrix, base->dimension);
            break;
        default:
            printInvalidTypeError();
            fclose(output);
            return 1;
    }
    printOkMessage(output_path);
    clear(base);
    fclose(output);
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
