#include <thread>
#include "gardener.h"

using std::mutex;

void Gardener::workLeftToRight(Garden *garden, mutex *garden_mutex, int sleep_time) const {
    for (int i = 0; i < garden->rows; ++i) {
        for (int j = 0; j < garden->columns; ++j) {
            garden_mutex->lock();
            if (garden->matrix[i][j] == 0) {
                garden->matrix[i][j] = number;
            }
            garden_mutex->unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        }
    }
}

void Gardener::workBottomToTop(Garden *garden, mutex *garden_mutex, int sleep_time) const {
    for (int j = garden->columns - 1; j > -1; --j) {
        for (int i = garden->rows - 1; i > -1; --i) {
            garden_mutex->lock();
            if (garden->matrix[i][j] == 0) {
                garden->matrix[i][j] = number;
            }
            garden_mutex->unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        }
    }
}

Gardener::Gardener(int number) : number(number) {
}

void Gardener::work(Garden *garden, Modes mode, mutex *garden_mutex, int sleep_time) {
    if (mode == Modes::kBottomToTop) {
        workBottomToTop(garden, garden_mutex, sleep_time);
    } else {
        workLeftToRight(garden, garden_mutex, sleep_time);
    }
}
