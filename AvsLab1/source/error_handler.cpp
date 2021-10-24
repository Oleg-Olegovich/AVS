#include "error_handler.h"

void ErrorHandler::printInvalidNumberError() {
    printf("Invalid number!\n");
    printf("A real number in the range is expected 1,7E +/- 308.\n");
}

void ErrorHandler::printInvalidDimensionError() {
    printf("Invalid dimension!\n");
    printf("A natural number is expected.\n");
}

void ErrorHandler::printInvalidCommandLineError() {
    printf("Invalide command line! One of two options is expected:\n");
    printf("command -f <input file name> <output file name>\n");
    printf("command -r <matrix type> <matrix size> <output file name>\n");
}

void ErrorHandler::printNonexistentFileError(char *file_path) {
    printf("This file doesn't exist:\n");
    printf("%s", file_path);
    printf("%c", '\n');
}

void ErrorHandler::printInvalidTypeError() {
    printf("Invalid matrix type!\n");
    printf("Expected: \"0\" - usual, \"1\" - diagonal or \"2\" - triangular.\n");
}

void ErrorHandler::printOkMessage(char *file_path) {
    printf("The program was executed without errors. The output is in this file:\n");
    printf("%s", file_path);
    printf("%c", '\n');
}
