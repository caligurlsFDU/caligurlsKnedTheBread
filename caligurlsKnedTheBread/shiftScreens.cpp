#include "shiftScreens.h"
#include <string>
#include <sstream>
#include <iomanip>

// ShiftScreens class implementation
std::string shiftScreens::getShiftOverText(int shift, double averageRating)
{
	std::ostringstream text;
	text << "Shift Over\n"
		<< "Shift " << shift
		<< "\nAverage Rating: " << std::fixed << std::setprecision(1) << averageRating << " / 5\n";
	return text.str();
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