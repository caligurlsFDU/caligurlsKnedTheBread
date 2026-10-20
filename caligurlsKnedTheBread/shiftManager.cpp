#include "shiftManager.h"
#include <iostream>
#include <limits>

void shiftManager::runAllShifts()
{
	for (int shift = 1; shift <= Shift::getTotalShifts(); shift++)
	{
		runShift(shift);
		showShiftEnd();
	}
}
void shiftManager::runShift(int shift)
{
	currentShift.startShift(shift);

	std::cout << "Starting Shift " << currentShift.getShiftNumber() << "\n";
	std::cout << currentShift.getStatusText() << "\n";

	//The existing game logic for serving customers would go here. 
	//For now, we will simulate serving customers with a simple loop.
}
void shiftManager::showShiftEnd()
{
	std::cout << screens.getShiftOverText(
		currentShift.getShiftNumber(), 
		currentShift.getTotalRating()) << "\n";
	std::cout << screens.getShiftEndOptionsText() << "\n";
	int choice = readChoice();
	while (!screens.isValidShiftEndOption(choice))
	{
		std::cout << screens.getInvalidChoiceText();
		std::cout << screens.getShiftEndOptionsText();
		choice = readChoice();
	}
	if (choice == 1) // Continue to next shift
	{
		return;
	}
	else if (choice == 2) // Go to shop
	{
		showShop();
	}
}
void shiftManager::showShop()
{
	std::cout << screens.getShopText() << "\n";
	int choice = readChoice();
	while (!screens.isValidShopOption(choice))
	{
		std::cout << screens.getInvalidChoiceText();
		std::cout << screens.getShopText();
		choice = readChoice();
	}
	// Handle shop choice here
}
int shiftManager::readChoice()
{
	int choice;
	while (!(std::cin >> choice))
	{
		std::cout << screens.getInvalidChoiceText();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please choose an option: ";
	}
	return choice;
}
	