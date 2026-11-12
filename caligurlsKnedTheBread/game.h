#pragma once
#include <string>
#include "customer.h"
#include "ingredientBook.h"
#include "orderGenerator.h"
#include "utilities.h"

class Game
{
public:
	Game();
	orderGenerator& getOrderGenerator() { return generator; }
	void startGame();
	double serveCustomer(Customer& customer, int shift);
	double getCashTotal() const;
	double getShiftTotal() const;
	double getAverageRating() const;
	void giveCash(double cashEarned);
	void resetShiftTotal();
	void finishShift();
	void clearScreen();
	void pressEnterToContinue();
	void displayHeader(int shift, int customer, double starRating);
	bool payUtilities(int shift, double averageRating);
	void gameOver(int shiftsSurvived);

private:
	ingredientBook book;
	orderGenerator generator;
	std::string order;
	double cashTotal = 0;
	double shiftTotal = 0;
	utilities utilities;
};
