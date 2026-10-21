#include "shift.h"
#include "shiftConfig.h"

// Shift class implementation
void Shift::startShift(int shift)
{
	// Validate the shift number
	if (!shiftConfig::isValidShift(shift))
	{
		return;
	}
	shiftNumber = shift;
	customerCount = shiftConfig::getCustomerCount(shift);
	// Reset the number of customers served and total rating for the new shift
	customersServed = 0;
	totalRating = 0;
}
// Getters for shift properties
int Shift::getShiftNumber() const
{
	return shiftNumber;
}
// Getters for shift properties
int Shift::getCustomersLeft() const
{
	return customerCount - customersServed;
}
// Getters for shift properties
int Shift::getTotalRating() const
{
	return totalRating;
}
// Getters for shift properties
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
// Checks if the shift is over (no more customers left)
bool Shift::isShiftOver() const
{
	return getCustomersLeft() == 0;
}
// Returns a string representation of the current shift status
std::string Shift::getStatusText() const
{
	return "Shift " + std::to_string(shiftNumber)
		+ " | Customers left: " + std::to_string(getCustomersLeft());
}