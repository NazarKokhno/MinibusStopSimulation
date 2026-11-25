#pragma once

class Minibus
{
private:
	int FreeSeats;
	double ArrivalTime;
public:
	Minibus(int freeSeats, double arrivalTime);

	int GetFreeSeats() const;
	double GetArrivalTime() const;
};