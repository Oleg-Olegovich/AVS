#include <iostream>
#include <thread>
#include "garden.h"
#include "gardener.h"

using std::cout;
using std::endl;
using std::thread;
using std::mutex;

void Garden::printMatrix() const {
    cout << "Current state of the garden:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void Garden::clearMatrix() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Garden::Garden(const int rows, const int columns) : rows(rows), columns(columns) {
    matrix = new int *[rows];
    mutexes = new mutex**[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
        mutexes[i] = new mutex*[columns];
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = 0;
            mutexes[i][j] = new mutex();
        }
    }
}

Garden::~Garden() {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
        for (int j = 0; j < columns; ++j) {
            delete mutexes[i][j];
        }
        delete[] mutexes[i];
    }
    delete[] matrix;
    delete[] mutexes;
}

// The sleep time is indicated in milliseconds.
void Garden::demonstrate(int sleep_time) {
    clearMatrix();
    cout << "The beginning of the demonstration, the gardeners were not working yet." << endl;
    cout << "The gardener's sleep time is set: " << sleep_time << " ms." << endl;
    printMatrix();
    cout << "The gardeners started working." << endl;
    auto *first = new Gardener(1), *second = new Gardener(2);
    thread firstWorking(&Gardener::work, first, this, Modes::kLeftToRight, sleep_time);
    thread secondWorking(&Gardener::work, second, this, Modes::kBottomToTop, sleep_time);
    firstWorking.join();
    secondWorking.join();
    cout << "The gardeners have finished working." << endl;
    printMatrix();
    cout << "End of the demonstration." << endl;
    delete first;
    delete second;
}

void Garden::demonstrate() {
    demonstrate(0);
}