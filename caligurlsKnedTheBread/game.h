#pragma once
#include <string>
#include "customer.h"
#include "ingredientBook.h"
#include "orderGenerator.h"

class Game
{
public:
	Game();
	orderGenerator& getOrderGenerator() { return generator; }
	void startGame();
	double serveCustomer(Customer& customer, int shift);
	double getCashTotal() const;
	double getShiftTotal() const;
	void giveCash(double cashEarned);
	void resetShiftTotal();
	void finishShift();
	void clearScreen();
	void pressEnterToContinue();
	void displayHeader(int shift, int customer, double starRating);
private:
	ingredientBook book;
	orderGenerator generator;
	std::string order;
	double cashTotal = 0;
	double shiftTotal = 0;
};