#pragma once
#include <string>
#include "customer.h"

class Game
{
public:
	void startGame();
	double serveCustomer(Customer& customer);
	double getCashTotal() const;
	double getShiftTotal() const;
	void giveCash(double cashEarned);
	void resetShiftTotal();
	void finishShift();
	void clearScreen();
	void pressEnterToContinue();
	void displayHeader(int shift, int customer, double starRating);
private:
	std::string order;
	double cashTotal = 0;
	double shiftTotal = 0;
};
