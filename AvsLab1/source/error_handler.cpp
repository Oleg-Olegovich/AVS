#include "error_handler.h"

static void ErrorHandler::printInvalidNumberError() {
    cout << "Invalid number!\n"
         << "A real number in the range is expected 1,7E +/- 308.\n";
}

static void ErrorHandler::printInvalidDimensionError() {
    cout << "Invalid dimension!\nA natural number is expected.\n";
}

static void ErrorHandler::printInvalidCommandLineError() {
    cout << "Invalide command line! One of two options is expected:\n";
    cout << "command -f <input file name> <output file name>\n";
    cout << "command -r <matrix type> <matrix size> <output file name>\n";
}

static void ErrorHandler::printNonexistentFileError(const string &file_path) {
    cout << "This file doesn't exist:\n" << file_path << '\n';
}

static void ErrorHandler::printInvalidTypeError() {
    cout << "Invalid matrix type!\n"
         << "Expected: \"0\" - usual, \"1\" - diagonal or \"2\" - triangular.\n";
}

static void ErrorHandler::printOkMessage(const string &file_path) {
    cout << "The program was executed without errors. The output is in this file:\n"
         << file_path << '\n';
}
