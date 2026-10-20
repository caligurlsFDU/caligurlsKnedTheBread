#pragma once
#ifndef shiftManagerH
#define shiftManagerH
#include "shift.h"
#include "shiftScreens.h"
class shiftManager
{
public:
	void runAllShifts();
	void runShift(int shift);
	void showShiftEnd();
	void showShop();
	int readChoice();
private:
	Shift currentShift;
	shiftScreens screens;
};

#endif