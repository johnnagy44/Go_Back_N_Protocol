#include "constants.hpp"
class Frame
{
public:
    int seq;     // Sequence number
    int ack;     // Acknowledgment number
    string data; // Frame data

    Frame(int seq, int ack, string data) : seq(seq), ack(ack), data(data) {}
};