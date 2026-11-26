#include <stdexcept>
#include "Minibus.h"


Minibus::Minibus(int freeSeats, double arrivalTime)
	: FreeSeats(freeSeats), ArrivalTime(arrivalTime)
{
	if (FreeSeats < 0)
		throw std::invalid_argument("Minibus free seats cannot be negative");

	if (ArrivalTime < 0)
		throw std::invalid_argument("Minibus arrival time cannot be negative");
}
int  Minibus::GetFreeSeats() const
{
	return FreeSeats;
}
double Minibus::GetArrivalTime() const
{
	return ArrivalTime;
}

