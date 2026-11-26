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
    BusStop& operator=(const BusStop&) = delete;
    BusStop(const BusStop&) = delete;
    ~BusStop();
    
    void AddPassenger(double arrivalTime);
    
    void BoardPassengers(Minibus& minibus);

    void ArriveMinibus(double arrivialTime);
  
    double CalculateAverageWaitingTime() const;
    
    void RunSimulation(double simulationDuration);

    int GetPassengerCount() const;
    int GetBoardingCount() const;
    int GetMinibusCount() const;

    void DisplayStatistics() const;
    
};