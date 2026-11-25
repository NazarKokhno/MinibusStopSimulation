#include <iostream>
#include "Passenger.h"
#include "Queue.h"
#include "Minibus.h"


using namespace std;

int main()
{
    try
    {
        Passenger passenger(5.5, 12.5);
        Minibus bus(8, 15.0);

        cout << "Passenger created successfully!" << endl;
        cout << "Arrival time: " << passenger.GetArrivalTime() << endl;
        cout << "Boarding time: " << passenger.GetBoardingTime() << endl;

        cout << "\nMinibus created successfully!" << endl;
        cout << "Free seats: " << bus.GetFreeSeats() << endl;
        cout << "Arrival time: " << bus.GetArrivalTime() << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Input error: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}