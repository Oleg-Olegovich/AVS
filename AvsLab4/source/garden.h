#ifndef AVSLAB4_GARDEN_H
#define AVSLAB4_GARDEN_H

#include <mutex>

class Garden {
private:
    void printMatrix() const;
    void clearMatrix() const;
    std::mutex *garden_mutex;

public:
    int** matrix, rows, columns;

    Garden(int rows, int columns);
    ~Garden();
    void demonstrate(int sleep_time);
    void demonstrate();
};

#endif
