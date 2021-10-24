#include "basic_matrix.h"
#include "usual_matrix.h"
#include "diagonal_matrix.h"
#include "triangular_matrix.h"

BasicMatrix::BasicMatrix(long long input_dimension) {
    dimension = input_dimension;
}

void BasicMatrix::sort() {}
int BasicMatrix::read(FILE *file) {
    return 0;
}
void BasicMatrix::print(FILE *file) {}
void BasicMatrix::generate() {}

double BasicMatrix::generateNumber(double minimum, double range_width) {
    srand(time(0));
    return minimum + range_width * rand();
}

int BasicMatrix::readInteger(FILE *file, int *number) {
    long long input_number = INT64_MAX;
    fscanf(file, "%lld", &input_number);
    if (input_number > INT32_MAX || input_number < INT32_MIN) {
        return 1;
    }
    *number = (int)input_number;
    return 0;
}

int BasicMatrix::readDimension(FILE *file, long long *number) {
    *number = -1;
    fscanf(file, "%lld", number);
    if (*number < 1) {
        return 1;
    }
    return 0;
}

int BasicMatrix::readNumber(FILE *file, double *number) {
    *number = -1;
    fscanf(file, "%lf", number);
    if (*number < 1) {
        return 1;
    }
    return 0;
}

BasicMatrix* BasicMatrix::initialize(int type, long long int dimension) {
    return nullptr;
    BasicMatrix* matrix;
    switch (type) {
        case 0:
            //matrix = new UsualMatrix(dimension);
            break;
        case 1:
            //matrix = new DiagonalMatrix(dimension);
            break;
        case 2:
            //matrix = new TriangularMatrix(dimension);
            break;
        default:
            ErrorHandler::printInvalidTypeError();
            return nullptr;
    }
}

void BasicMatrix::demonstrate(BasicMatrix *basic, FILE *output) {
    fprintf(output, "%s", "Matrix before sorting:\n");
    basic->print(output);
    fprintf(output, "%s", "Matrix after sorting:\n");
    basic->sort();
    basic->print(output);
}

int BasicMatrix::demonstrate(char *input_path, char *output_path) {
    FILE *input = fopen(input_path, "r");
    int type;
    if (readInteger(input, &type) == 1) {
        ErrorHandler::printInvalidTypeError();
        fclose(input);
        free(input_path);
        free(output_path);
        return 1;
    }
    long long dimension = 0;
    if (readDimension(input, &dimension) == 1) {
        ErrorHandler::printInvalidDimensionError();
        fclose(input);
        free(output_path);
        return 1;
    }
    BasicMatrix *basic = initialize(type, dimension);
    if (basic == nullptr) {
        fclose(input);
        free(input_path);
        free(output_path);
        return 1;
    }
    FILE *output = fopen(output_path, "w");
    if (basic->read(input) == 1) {
        ErrorHandler::printInvalidNumberError();
        delete basic;
        fclose(input);
        fclose(output);
        free(input_path);
        free(output_path);
        return 1;
    }
    demonstrate(basic, output);
    delete basic;
    fclose(input);
    fclose(output);
    free(input_path);
    ErrorHandler::printOkMessage(output_path);
    free(output_path);
    return 0;
}

int BasicMatrix::demonstrate(const char *matrix_type, const char *input_size, char *output_path) {
    int type = matrix_type[0] - '0';
    long long dimension = 0;
    dimension = atoll(input_size);
    if (dimension < 1) {
        ErrorHandler::printInvalidDimensionError();
        return 1;
    }
    BasicMatrix *basic = initialize(type, dimension);
    if (basic == nullptr) {
        free(output_path);
        return 1;
    }
    FILE *output = fopen(output_path, "w");
    basic->generate();
    demonstrate(basic, output);
    delete basic;
    fclose(output);
    ErrorHandler::printOkMessage(output_path);
    free(output_path);
    return 0;
}
