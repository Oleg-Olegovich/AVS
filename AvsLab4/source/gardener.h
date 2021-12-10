#ifndef AVSLAB4_GARDENER_H
#define AVSLAB4_GARDENER_H

#include <mutex>
#include "modes.h"
#include "garden.h"

using std::mutex;

class Gardener {
private:
    int number;

    void workLeftToRight(Garden *garden, mutex *garden_mutex, int sleep_time) const;

    void workBottomToTop(Garden *garden, mutex *garden_mutex, int sleep_time) const;

public:
    explicit Gardener(int number);

    void work(Garden *garden, Modes mode, mutex *garden_mutex, int sleep_time);
};

#endif