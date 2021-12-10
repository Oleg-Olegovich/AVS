#ifndef AVSLAB4_GARDENER_H
#define AVSLAB4_GARDENER_H

#include <mutex>
#include "modes.h"
#include "garden.h"

using std::mutex;

class Gardener {
private:
    int number;

    void workLeftToRight(Garden *garden, int sleep_time) const;

    void workBottomToTop(Garden *garden, int sleep_time) const;

public:
    explicit Gardener(int number);

    void work(Garden *garden, Modes mode, int sleep_time);
};

#endif