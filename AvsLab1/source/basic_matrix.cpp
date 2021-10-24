#include "basic_matrix.h"

BasicMatrix::BasicMatrix(long long input_dimension) {
    dimension = input_dimension;
}

void BasicMatrix::sort() {}
void BasicMatrix::read(const ifstream &file) {}
void BasicMatrix::print(const ofstream &file) {}
void BasicMatrix::generate() {}

double BasicMatrix::generateNumber(double minimum, double range_width) {
    srand(time(0));
    return minimum + range_width * rand();
}

int BasicMatrix::readInteger(FILE *file) {
    char *input[11], *end;
    fscanf(file, "%s", *input);
    int number = (int)strtoul(*input, &end, 10);
    if (errno == ERANGE) {
        throw 10;
    }
    return number;
}

long long BasicMatrix::readDimension(FILE *file) {
    string input;
    file >> input;
    long long number = stoll(input);
    if (number < 1) {
        throw 11;
    }
    return number;
}

double BasicMatrix::readNumber(FILE *file) {
    string input;
    file >> input;
    return stod(input);
}
