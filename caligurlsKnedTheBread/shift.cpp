#include "shift.h"

int Shift::getTotalShifts()
{
	return 3; // Total number of shifts in the game
}
int Shift::getCustomerCount(int shift)
{
	switch (shift)
	{
	case 1:
		return 3; // Number of customers in shift 1
	case 2:
		return 4; // Number of customers in shift 2
	case 3:
		return 5; // Number of customers in shift 3
	default:
		return 0; // Invalid shift number
	}
}
bool Shift::isValidShift(int shift)
{
	return shift >= 1 && shift <= getTotalShifts();
}
void Shift::startShift(int shift)
{
	if (!isValidShift(shift))
	{
		return;
	}
	shiftNumber = shift;
	customerCount = getCustomerCount(shift);
	customersServed = 0;
	totalRating = 0;
}
int Shift::getShiftNumber() const
{
	return shiftNumber;
}
int Shift::getCustomersLeft() const
{
	return customerCount - customersServed;
}
int Shift::getTotalRating() const
{
	return totalRating;
}
bool Shift::serveCustomer(int rating)
{
	if (isShiftOver())
	{
		return false; // No more customers to serve
	}
	totalRating += rating;
	customersServed++;
	return true; // Customer served successfully
}
bool Shift::isShiftOver() const
{
	return getCustomersLeft() == 0;
}
std::string Shift::getStatusText() const
{
	return "Shift " + std::to_string(shiftNumber)
		+ " | Customers left: " + std::to_string(getCustomersLeft())
}