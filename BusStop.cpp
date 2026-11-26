#include <iostream>
#include <stdexcept>
#include "Queue.h"
#include "Passenger.h"
#include "BusStop.h"


BusStop::BusStop(double avg_interarrival_time,
    double avg_bus_headway, bool isterminal)
    : avg_interarrival_time(avg_interarrival_time),
    avg_bus_headway(avg_bus_headway), isTerminal(isterminal),
    Passengers(100) 
{
    if (avg_interarrival_time <= 0)
        throw std::invalid_argument("Average passenger arrival time must be greater than zero");
    if (avg_bus_headway <= 0)
        throw std::invalid_argument("Average minibus headway must be greater than zero");
}

BusStop::~BusStop()
{
    delete[] PassengerArrivalTimes;
    delete[] PassengerBoardingTimes;
    delete[] MinibusArrivalTimes;

}
void BusStop::AddPassenger(double arrivalTime)
{
    Passenger passenger(arrivalTime);
    Passengers.push(passenger);

    double* newArray = new double[PassengerCount + 1];

    for (int i = 0; i < PassengerCount; i++)
    {
        newArray[i] = PassengerArrivalTimes[i];
    }

    newArray[PassengerCount] = arrivalTime;

    delete[] PassengerArrivalTimes;
    PassengerArrivalTimes = newArray;

    PassengerCount++;
}