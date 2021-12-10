#ifndef AVSLAB4_GARDEN_H
#define AVSLAB4_GARDEN_H

#include <mutex>

class Garden {
private:
    void printMatrix() const;

public:
    int** matrix, rows, columns;
    std::mutex ***mutexes;

    Garden(int rows, int columns);
    ~Garden();
    void demonstrate(int first_sleep_time, int second_sleep_time);
};

#endif
