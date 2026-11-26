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
        BusStop stop(5, 10, false);

        stop.RunSimulation(30);

        cout << "Passengers: " << stop.GetPassengerCount() << endl;
        cout << "Boarded: " << stop.GetBoardingCount() << endl;
        cout << "Minibuses: " << stop.GetMinibusCount() << endl;

        cout << "Average waiting time: "
            << stop.CalculateAverageWaitingTime() << endl;

    }
    catch (const exception& error)
    {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}