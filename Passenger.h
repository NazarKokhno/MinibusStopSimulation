#pragma once

class Passenger
{
private:
    double ArrivalTime;
    double BoardingTime;

public:
    Passenger(double arrivalTime, double boardingTime);

    double GetArrivalTime() const;
    double GetBoardingTime() const;

    
};