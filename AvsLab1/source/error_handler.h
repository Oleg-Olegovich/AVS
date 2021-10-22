#ifndef AVSLAB1_ERRORHANDLER_H
#define AVSLAB1_ERRORHANDLER_H

#include <string>

class ErrorHandler {
public:
    static void printInvalidNumberError();
    static void printInvalidDimensionError();
    static void printInvalidCommandLineError();
    static void printNonexistentFileError(const string &file_path);
    static void printInvalidTypeError();
    static void printOkMessage(const string &file_path);
};

#endif
