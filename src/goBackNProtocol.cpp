#include "constants.hpp"
#include "timer.cpp"

// Go-Back-N Protocol Class

class GoBackNProtocol
{
private:
    int next_frame_to_send; // Upper edge of the window
    int ack_expected;       // Lower edge of the window
    int frame_expected;     // Next frame expected on the receiver side
    int nbuffered;          // Number of frames currently buffered
    vector<string> buffer;  // Buffer for outgoing frames
    Timer timer;            // Simulated timers for retransmission

public:
    GoBackNProtocol() : next_frame_to_send(0), ack_expected(0), frame_expected(0), nbuffered(0)
    {
        buffer.resize(MAX_SEQ + 1);
    }

    void from_network_layer(string packet)
    {
        buffer[next_frame_to_send] = packet;
        nbuffered++;
        send_frame(next_frame_to_send);
        next_frame_to_send = increment(next_frame_to_send);
    }

    void send_frame(int seq)
    {
        cout << "Sending frame: " << seq << " | Data: " << buffer[seq] << endl;
        timer.start(seq); // Start the timer for the frame
    }

    void receive_ack(int ack)
    {
        while (between(ack_expected, ack, next_frame_to_send))
        {
            cout << "Acknowledged frame: " << ack_expected << endl;
            nbuffered--;
            timer.stop(ack_expected);
            ack_expected = increment(ack_expected);
        }
    }

    void receive_frame(int seq, string data)
    {
        if (seq == frame_expected)
        {
            cout << "Received frame: " << seq << " | Data: " << data << endl;
            frame_expected = increment(frame_expected);
        }
    }

    void timeout_retransmit()
    {
        for (int i = ack_expected; i != next_frame_to_send; i = increment(i))
        {
            if (timer.timeout(i))
            {
                cout << "Timeout for frame: " << i << ". Retransmitting..." << endl;
                send_frame(i);
            }
        }
    }

    void run_simulation(vector<string> packets)
    {
        srand(time(0)); // Seed for randomness

        for (const string &packet : packets)
        {
            if (nbuffered < MAX_SEQ)
            {
                from_network_layer(packet);
            }
            else
            {
                cout << "Network layer disabled: Window full." << endl;
            }

            // Simulate frame arrival and acknowledgments
            int event = rand() % 4; // Random event: 0 = ack, 1 = frame, 2 = timeout, 3 = idle
            if (event == 0)
            {
                int ack = rand() % (MAX_SEQ + 1);
                cout << "Simulating acknowledgment for frame: " << ack << endl;
                receive_ack(ack);
            }
            else if (event == 1)
            {
                int seq = rand() % (MAX_SEQ + 1);
                cout << "Simulating frame arrival: " << seq << endl;
                receive_frame(seq, "Some data");
            }
            else if (event == 2)
            {
                cout << "Simulating timeout event." << endl;
                timeout_retransmit();
            }
            else
            {
                cout << "No event." << endl;
            }

            timer.decrement(); // Decrement timers
            cout << endl;
        }
    }
};