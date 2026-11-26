#pragma once
#include "Queue.h"
#include "Passenger.h"
#include "Minibus.h"


class BusStop
{
private:
    Queue<Passenger> Passengers;
    double avg_interarrival_time;
    double avg_bus_headway;
    
    int PassengerCount = 0;
    int BoardingCount = 0;
    int MinibusCount = 0;

    bool isTerminal;

    double* PassengerArrivalTimes = nullptr;
    double* PassengerBoardingTimes = nullptr;
    double* MinibusArrivalTimes = nullptr;
public:
    BusStop(double avg_interarrival_time,
        double avg_bus_headway, bool isterminal);
    ~BusStop();
    
    
    void AddPassenger(double arrivalTime);
    
    double* GetPassengerArrivalTimes() const
    {
        return PassengerArrivalTimes;
    }

    void BoardPassengers(Minibus& minibus);

    void ArriveMinibus(double arrivialTime);
  
};