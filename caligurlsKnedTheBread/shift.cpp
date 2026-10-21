#include "shift.h"
#include "shiftConfig.h"

void Shift::startShift(int shift)
{
	if (!shiftConfig::isValidShift(shift))
	{
		return;
	}
	shiftNumber = shift;
	customerCount = shiftConfig::getCustomerCount(shift);
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
		+ " | Customers left: " + std::to_string(getCustomersLeft());
}