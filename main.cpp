#include <iostream>
#include <exception>
#include "Passenger.h"
#include "Queue.h"
#include "Minibus.h"
#include "BusStop.h"


using namespace std;

int main()
{
    try
    {
        BusStop stop(5.0, 15.0, false);
       
        stop.AddPassenger(2);
        stop.AddPassenger(5);
        stop.AddPassenger(7);

        Minibus minibus(3, 10);
        stop.BoardPassengers(minibus);

        cout << stop.CalculateAverageWaitingTime() << endl;

    }
    catch (const exception& error)
    {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}