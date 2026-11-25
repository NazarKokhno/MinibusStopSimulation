#include "Passenger.h"
#include <iostream>
#include <cmath>

using namespace std;

Passenger::Passenger(double ArrivalTime, double BoardingTime)
    : ArrivalTime(ArrivalTime), BoardingTime(BoardingTime)
{
    if (ArrivalTime < 0)
    {
        this->ArrivalTime = abs(ArrivalTime);
    }

    if (BoardingTime < 0)
    {
        this->BoardingTime = abs(BoardingTime);
    }
}

void Passenger::Show()
{
    cout << "Arrival time: " << ArrivalTime << endl;
    cout << "Boarding time: " << BoardingTime << endl;
}

