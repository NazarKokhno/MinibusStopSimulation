#include "Passenger.h"
#include <iostream>
#include <stdexcept>



Passenger::Passenger(double arrivalTime)
    : ArrivalTime(arrivalTime)
{
    if (ArrivalTime < 0)
        throw std::invalid_argument("Passenger arrival time cannot be negative");   
}

Passenger::Passenger()
    : ArrivalTime(0), BoardingTime(-1) {}

double Passenger::GetArrivalTime() const
{
    return ArrivalTime;
}

double Passenger::GetBoardingTime() const
{
    return BoardingTime;
}

void Passenger::SetBoardingTime(double time)
{
    if (time < 0)
        throw std::invalid_argument("Passenger boarding time cannot be negative");

    if (time < ArrivalTime)
        throw std::invalid_argument("Passenger boarding time cannot be earlier than arrival time");

    BoardingTime = time;
}

