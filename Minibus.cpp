#include <stdexcept>
#include "Minibus.h"


Minibus::Minibus(int freeSeats, double arrivalTime)
	: freeSeats(freeSeats), arrivalTime(arrivalTime)
{
	if (freeSeats < 0)
		throw std::invalid_argument("Minibus free seats cannot be negative");

	if (arrivalTime < 0)
		throw std::invalid_argument("Minibus arrival time cannot be negative");
}
int  Minibus::GetFreeSeats() const
{
	return freeSeats;
}
double Minibus::GetArrivalTime() const
{
	return arrivalTime;
}

void Minibus::UseSeat()
{
	if (freeSeats > 0)
		freeSeats--;
}



