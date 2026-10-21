#pragma once
#ifndef shiftH
#define shiftH
#include <string>

class Shift
{
public:
	//Shift info and progress
	void startShift(int shift);
	int getShiftNumber() const;
	int getCustomersLeft() const;
	int getTotalRating() const;
	bool serveCustomer(int rating);
	bool isShiftOver() const;
	std::string getStatusText() const;

private:
	int shiftNumber = 0;
	int customersServed = 0;
	int totalRating = 0;
	int customerCount = 0;
};
#endif