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

        stop.AddPassenger(2.5);
        stop.AddPassenger(7.0);
        stop.AddPassenger(12.5);

        stop.ArriveMinibus(12);
        stop.ArriveMinibus(10);
        stop.ArriveMinibus(7);

       for (int i = 0; i < 3; i++)
       {
            cout << stop.GetPassengerArrivalTimes()[i] << '\n';
       }
    }
    catch (const exception& error)
    {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}