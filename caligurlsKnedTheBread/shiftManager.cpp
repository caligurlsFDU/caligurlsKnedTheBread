#include "shiftManager.h"
#include "shiftConfig.h"
#include "game.h"
#include <iostream>
#include <limits>

void shiftManager::runAllShifts(Game& game)
{
	orderBook = Customer::createCustomers();
	customerIndex = 0;

	for (int shift = 1; shift <= shiftConfig::getTotalShifts(); shift++)
	{
		runShift(shift, game);
		int choice = showShiftEnd();

		if (choice == 2) // Go to shop
		{
			showShop();
		}
		else if (choice == 3) // Exit game
		{
			std::cout << "Exiting game. Thank you for playing!\n";
			return;
		}
	}
}
void shiftManager::runShift(int shift, Game& game)
{
	currentShift.startShift(shift);

	std::cout << "Starting Shift " << currentShift.getShiftNumber() << "\n";

	//The existing game logic for serving customers would go here. 
	//For now, we will simulate serving customers with a simple loop.

	while (!currentShift.isShiftOver() && customerIndex < static_cast<int>(orderBook.size()))
	{
		std::cout << currentShift.getStatusText() << "\n";
		int rating = game.serveCustomer(orderBook[customerIndex]);
		currentShift.serveCustomer(rating);
		customerIndex++;
	}
}
int shiftManager::showShiftEnd()
{
	std::cout << screens.getShiftOverText(currentShift.getShiftNumber(), currentShift.getTotalRating());
	std::cout << screens.getShiftEndOptionsText();
	int choice = readChoice();
	while (!screens.isValidShiftEndOption(choice))
	{
		std::cout << screens.getInvalidChoiceText();
		std::cout << screens.getShiftEndOptionsText();
		choice = readChoice();
	}
	return choice;
}
void shiftManager::showShop()
{
	std::cout << screens.getShopText();
	int choice = readChoice();
	while (!screens.isValidShopOption(choice))
	{
		std::cout << screens.getInvalidChoiceText();
		std::cout << screens.getShopText();
		choice = readChoice();
	}
}
int shiftManager::readChoice()
{
	int choice;
	while (!(std::cin >> choice))
	{
		std::cout << screens.getInvalidChoiceText();
		std::cin.clear(); // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
		std::cout << "Please enter a valid number: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
	return choice;
}