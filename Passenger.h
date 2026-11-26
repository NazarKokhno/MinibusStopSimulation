#pragma once

class Passenger
{
private:
    double ArrivalTime;
    double BoardingTime = -1;

public:
    Passenger();
    Passenger(double arrivalTime);
    double GetArrivalTime() const;
    double GetBoardingTime() const;

    void SetBoardingTime(double time);
};