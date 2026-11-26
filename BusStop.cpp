#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "Queue.h"
#include "Passenger.h"
#include "BusStop.h"
#include "Minibus.h"



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

  /*  cout << "\nShow queue \n----------" << endl;
    Passengers.show();
    cout << "\n----------" << endl;*/

    PassengerCount++;
}

void BusStop::BoardPassengers(Minibus& minibus)
{
    while (!Passengers.empty() && minibus.GetFreeSeats() > 0)
    {
        double* newArray = new double[BoardingCount + 1];

        for (int i = 0; i < BoardingCount; i++)
        {
            newArray[i] = PassengerBoardingTimes[i];
        }

        Passenger& passenger = Passengers.front();
        passenger.SetBoardingTime(minibus.GetArrivalTime());
        double BoardingTime = passenger.GetBoardingTime();

        newArray[BoardingCount] = BoardingTime;

        Passengers.pop();

        delete[] PassengerBoardingTimes;

        PassengerBoardingTimes = newArray;

        BoardingCount++;

        minibus.UseSeat();
    }
    
}

void BusStop::ArriveMinibus(double arrivalTime)
{
    int freeSeats = std::rand() % 17;

    Minibus minibus(freeSeats,arrivalTime);
    double* newArray = new double[MinibusCount + 1];

    for (int i = 0; i < MinibusCount; i++)
    {
        newArray[i] = MinibusArrivalTimes[i];
    }

    newArray[MinibusCount] = arrivalTime;

    delete[] MinibusArrivalTimes;
    
    MinibusArrivalTimes = newArray;

    MinibusCount++;

    if (!isTerminal)
    {
        BoardPassengers(minibus);
    }
}

double BusStop::CalculateAverageWaitingTime() const
{
    
    if (BoardingCount <= 0)
        throw std::runtime_error("Cannot calculate average waiting time: no passengers boarded");
    
    double sum = 0;

    for (int i = 0; i < BoardingCount; i++)
    {
        sum += PassengerBoardingTimes[i] - PassengerArrivalTimes[i];
    }

    return sum / BoardingCount;
}

void BusStop::RunSimulation(double simulationDuration)
{
    double currentTime = 0;
    double nextPassengerArrival = avg_interarrival_time;
    double nextMinibusArrival = avg_bus_headway;

    while (std::min(nextPassengerArrival, nextMinibusArrival) <= simulationDuration)
    {
        if (nextPassengerArrival > nextMinibusArrival)
        {
            if (nextMinibusArrival > simulationDuration)
                break;
            
            currentTime = nextMinibusArrival;
            ArriveMinibus(currentTime);
            
            nextMinibusArrival += avg_bus_headway;
        }
        else
        {
            if (nextPassengerArrival > simulationDuration)
                break;
            currentTime = nextPassengerArrival;
            AddPassenger(currentTime);

            nextPassengerArrival += avg_interarrival_time;
        }
    }
}

int BusStop::GetPassengerCount() const
{
    return PassengerCount;
}

int BusStop::GetBoardingCount() const
{
    return BoardingCount;
}

int BusStop::GetMinibusCount() const
{
    return MinibusCount;
}

void BusStop::DisplayStatistics() const
{
    std::cout << "Passengers: " << PassengerCount << std::endl;
    std::cout << "Boarded: " << BoardingCount << std::endl;
    std::cout << "Waiting: " << PassengerCount - BoardingCount << std::endl;
    std::cout << "Minibuses: " << MinibusCount << std::endl;
    try
    {
        std::cout << "Average waiting time: "
            << CalculateAverageWaitingTime() << std::endl;
    }
    catch (const std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
}
