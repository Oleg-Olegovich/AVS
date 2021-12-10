#include <iostream>
#include <thread>
#include "garden.h"
#include "gardener.h"

using std::cout;
using std::endl;
using std::thread;

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
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = 0;
        }
    }
    garden_mutex = new std::mutex();
}

Garden::~Garden() {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete garden_mutex;
}

// The sleep time is indicated in milliseconds.
void Garden::demonstrate(int sleep_time) {
    clearMatrix();
    cout << "The beginning of the demonstration, the gardeners were not working yet." << endl;
    cout << "The gardener's sleep time is set: " << sleep_time << " ms." << endl;
    printMatrix();
    cout << "The gardeners started working." << endl;
    auto *first = new Gardener(1), *second = new Gardener(2);
    thread firstWorking(&Gardener::work, first, this, Modes::kLeftToRight, garden_mutex, sleep_time);
    thread secondWorking(&Gardener::work, second, this, Modes::kBottomToTop, garden_mutex, sleep_time);
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