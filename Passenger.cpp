#include "Passenger.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Passenger::Passenger(double arrivalTime, double boardingTime)
    : ArrivalTime(arrivalTime), BoardingTime(boardingTime)
{
    if (ArrivalTime < 0)
        throw std::invalid_argument("Passenger arrival time cannot be negative");

    if (BoardingTime < 0)
        throw std::invalid_argument("Passenger boarding time cannot be negative");
}

double Passenger::GetArrivalTime() const
{
    return ArrivalTime;
}

double Passenger::GetBoardingTime() const
{
    return BoardingTime;
}

