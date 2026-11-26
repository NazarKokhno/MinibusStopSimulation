#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Passenger.h"
#include "Queue.h"
#include "Minibus.h"
#include "BusStop.h"

using namespace std;

int main()
{
    srand(time(0));

    try
    {
        BusStop stop(1, 11, false);
        stop.RunSimulation(120);
        stop.DisplayStatistics();
    }
    catch (const exception& error)
    {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}