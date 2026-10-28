#pragma once
#ifndef shiftManagerH
#define shiftManagerH
#include "shift.h"
#include "shiftScreens.h"
#include "customer.h"
#include <vector>
class Game;
class shiftManager
{
public:
	void runAllShifts(Game& game);
	void runShift(int shift, Game& game);
	int showShiftEnd(Game& game);
	void showShop();
	int gameOver();
	int readChoice();
private:
	Shift currentShift;
	shiftScreens screens;
	std::vector<Customer> orderBook;
	int customerIndex = 0;
};

#endif