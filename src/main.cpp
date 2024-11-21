#include "constants.hpp"
#include "goBackNProtocol.cpp"

int main()
{
    GoBackNProtocol gbn;

    vector<string> packets = {"Packet1", "Packet2", "Packet3", "Packet4", "Packet5"};
    gbn.run_simulation(packets);

    return 0;
}