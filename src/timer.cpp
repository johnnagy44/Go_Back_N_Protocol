#include "constants.hpp"
class Timer
{
    vector<int> timers;

public:
    Timer() : timers(MAX_SEQ + 1, -1) {}

    void start(int seq) { timers[seq] = TIMEOUT; }

    void stop(int seq) { timers[seq] = -1; }

    void decrement()
    {
        for (int &t : timers)
        {
            if (t > 0)
                t--;
        }
    }

    bool timeout(int seq) { return timers[seq] == 0; }
};