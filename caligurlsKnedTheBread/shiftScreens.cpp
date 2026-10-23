#include "shiftScreens.h"
#include <string>

// ShiftScreens class implementation
std::string shiftScreens::getShiftOverText(int shift, int rating)
{
	return "Shift Over\n"
		"Shift " + std::to_string(shift)
		+ "\nTotal Rating: " + std::to_string(rating) + "\n";
}

// Returns the text for the shift end options
std::string shiftScreens::getShiftEndOptionsText()
{
	return "1. Continue to next shift\n"
		"2. Go to shop\n"
		"3. Exit game\n";
}
// Validates the user's choice for shift end options
bool shiftScreens::isValidShiftEndOption(int option)
{
	return option >= 1 && option <= 3;
}
// Returns the text for the shop screen
std::string shiftScreens::getShopText()
{
	return "SHOP COMING TO A LOCAL CITY NEAR YOU SOON!\n"
		//"1. Continue\n";
		"1. Exit shop\n";
}
// Validates the user's choice for shop options
bool shiftScreens::isValidShopOption(int option)
{
	return option == 1;
	//|| option == 2;
}
// Returns the text for the invalid choice message
std::string shiftScreens::getInvalidChoiceText()
{
	return "Invalid choice. Please select a valid option.\n";
}