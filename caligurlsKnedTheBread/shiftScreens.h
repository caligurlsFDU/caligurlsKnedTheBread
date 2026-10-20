#pragma once
#ifndef shiftScreensH
#define shiftScreensH
#include <string>
class shiftScreens
{
public:
	std::string getShiftOverText(int shift, int rating);
	std::string getShiftEndOptionsText();
	bool isValidShiftEndOption(int option);
	std::string getShopText();
	bool isValidShopOption(int option);
	std::string getInvalidChoiceText();
};

#endif