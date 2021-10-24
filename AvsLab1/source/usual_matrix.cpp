#include "usual_matrix.h"

UsualMatrix::UsualMatrix(long long dimension) :
        BasicMatrix(dimension) {

}

int UsualMatrix::readNumber(const ifstream &file) {
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            if (readNumber(file, &matrix[i][j]) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

virtual void UsualMatrix::read(const ifstream &file) {

}

virtual void UsualMatrix::sort() {

}

void UsualMatrix::print(const ofstream &file) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            file << fixed() << setprecision(3) << matrix[i][j] << ' ';
        }
        file << '\n';
    }
}

UsualMatrix& UsualMatrix::generate(long long dimension) {
    UsualMatrix *usual = new UsualMatrix(dimension);
    for (long long i = 0; i < dimension; ++i) {
        for (long long j = 0; j < dimension; ++j) {
            usual->matrix[i][j] = generateNumber(-100, 201);
        }
    }
    return usual;
}
