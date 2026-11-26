#include <iostream>
#include "Passenger.h"
#include "Queue.h"
#include "Minibus.h"
#include "BusStop.h"


using namespace std;

int main()
{
    
        BusStop stop(5.0, 15.0, false);

        stop.AddPassenger(2.5);
        stop.AddPassenger(7.0);
        stop.AddPassenger(12.5);

        for (int i = 0; i < 3; i++)
        {
            cout << stop.GetPassengerArrivalTimes()[i] << '\n';
        }

    return 0;
}