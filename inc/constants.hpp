#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants
#define MAX_SEQ 7 // Maximum sequence number (window size)
#define TIMEOUT 5 // Simulated timeout duration

// Function to increment sequence numbers circularly
int increment(int seq)
{
    return (seq + 1) % (MAX_SEQ + 1);
}

// Function to check if `b` is between `a` and `c` (circular range)
bool between(int a, int b, int c)
{
    return ((a <= b && b < c) || (c < a && a <= b) || (b < c && c < a));
}