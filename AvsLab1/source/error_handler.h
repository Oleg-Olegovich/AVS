#ifndef AVSLAB1_ERRORHANDLER_H
#define AVSLAB1_ERRORHANDLER_H

#include <iostream>

class ErrorHandler {
public:
    // Error code 10.
    static void printInvalidNumberError();
    // Error code 11.
    static void printInvalidDimensionError();
    // Error code 12.
    static void printInvalidCommandLineError();
    // Error code 13.
    static void printNonexistentFileError(const string &file_path);
    // Error code 14.
    static void printInvalidTypeError();
    static void printOkMessage(const string &file_path);
};

#endif
