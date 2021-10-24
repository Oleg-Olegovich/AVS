#ifndef AVSLAB1_ERRORHANDLER_H
#define AVSLAB1_ERRORHANDLER_H

#include <iostream>

class ErrorHandler {
public:
    static void printInvalidNumberError();
    static void printInvalidDimensionError();
    static void printInvalidCommandLineError();
    static void printNonexistentFileError(char *file_path);
    static void printInvalidTypeError();
    static void printOkMessage(char *file_path);
};

#endif
