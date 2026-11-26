#pragma once

class Minibus
{
private:
	int freeSeats;
	double arrivalTime;
public:
	Minibus(int freeSeats,double arrivalTime);

	int GetFreeSeats() const;
	double GetArrivalTime() const;
};