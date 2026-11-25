#pragma once
#pragma once

class Passenger
{
private:
    double ArrivalTime;
    double BoardingTime;

public:
    Passenger(double ArrivalTime, double BoardingTime);

    void Show();
};