#include <cstring>
#include <ctime>
#include "sys/stat.h"
#include "error_handler.h"
#include "basic_matrix.h"

bool fileExists(char *filename) {
    struct stat buffer{};
    return (stat (filename, &buffer) == 0);
}

int run(int argc, char *argv[]) {
    if (!(argc == 4 && strcmp(argv[1], "-f") == 0
          || argc == 5 && strcmp(argv[1], "-r") == 0)) {
        ErrorHandler::printInvalidCommandLineError();
        return 1;
    }
    if (argc == 4) {
        if (!fileExists(argv[2])) {
            ErrorHandler::printNonexistentFileError(argv[2]);
            return 1;
        }
        if (!fileExists(argv[3])) {
            ErrorHandler::printNonexistentFileError(argv[3]);
            return 1;
        }
        char *output_path = (char *) malloc(strlen(argv[3]) * sizeof(char));
        strcpy(output_path, argv[3]);
        return BasicMatrix::demonstrate(argv[2], output_path);
    }
    if (!fileExists(argv[4])) {
        ErrorHandler::printNonexistentFileError(argv[4]);
        return 1;
    }
    char *output_path = (char *) malloc(strlen(argv[4]) * sizeof(char));
    strcpy(output_path, argv[4]);
    return BasicMatrix::demonstrate(argv[2], argv[3], output_path);
}

int main(int argc, char *argv[]) {
    clock_t begin = clock();
    int result = run(argc, argv);
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("%s", "The running time of the program is ");
    printf("%lf", time_spent);
    printf("%s", " seconds.");
    return result;
}
