#include "Passenger.h"
#include <stdexcept>


Passenger::Passenger()
    : arrivalTime(0), boardingTime(-1) {}

Passenger::Passenger(double arrivalTime)
    : arrivalTime(arrivalTime)
{
    if (arrivalTime < 0)
        throw std::invalid_argument("Passenger arrival time cannot be negative");   
}

double Passenger::GetArrivalTime() const
{
    return arrivalTime;
}

double Passenger::GetBoardingTime() const
{
    return boardingTime;
}

void Passenger::SetBoardingTime(double time)
{
    if (time < 0)
        throw std::invalid_argument("Passenger boarding time cannot be negative");

    if (time < arrivalTime)
        throw std::invalid_argument("Passenger boarding time cannot be earlier than arrival time");

    boardingTime = time;
}

