#include "shiftScreens.h"
#include <string>

std::string shiftScreens::getShiftOverText(int shift, int rating)
{
	return "Shift Over\n"
		"Shift " + std::to_string(shift)
		+ "\nTotal Rating: " + std::to_string(rating) + "\n";
}

std::nullptr_t ShiftScreens::getShiftEndOptionsText()
{
	return "1. Continue to next shift\n"
		"2. Go to shop\n"
		"3. Exit game\n";
}
bool shiftScreens::isValidShiftEndOption(int option)
{
	return option >= 1 && option <= 3;
}
std::string shiftScreens::getShopText()
{
	return "SHOP COMING TO A LOCAL CITY NEAR YOU SOON!\n"
		"1. Continue\n"
		"2. Exit shop\n";
}
bool shiftScreens::isValidShopOption(int option)
{
	return option == 1 || option == 2;
}
std::string shiftScreens::getInvalidChoiceText()
{
	return "Invalid choice. Please select a valid option.\n";
}