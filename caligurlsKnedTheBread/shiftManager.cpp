#include "shiftManager.h"
#include "shiftConfig.h"
#include "game.h"
#include "shop.h"
#include "ingredients.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <limits>

void shiftManager::runAllShifts(Game& game)
{

	int choice = 1;

	while (choice == 1)
	{
		// Create every customer for the whole game up front. customerIndex tracks
		// who is next in line, so customers carry over across shifts instead of
		// restarting at the first one each shift.
		orderBook = Customer::createCustomers();
		customerIndex = 0;

		// Shifts are numbered starting at 1 so the number matches what the
		// player sees on screen ("Starting Shift 1").
		for (int shift = 1; shift <= shiftConfig::getTotalShifts(); shift++)
		{
			runShift(shift, game);
			choice = showShiftEnd();

			if (choice == 2 && shift < shiftConfig::getTotalShifts()) // Go to shop
			{
				showShop();
			}
			else if (choice == 3) // Exit game
			{
				std::cout << "Exiting game. Thank you for playing!\n";
				return;
			}
		}
		choice = gameOver();

		if (choice == 2)
		{
			std::cout << "Thank you for playing the game!\n";
			return;
		}
	}
}
void shiftManager::runShift(int shift, Game& game)
{
	game.resetShiftTotal();
	currentShift.startShift(shift);

	std::cout << "Starting Shift " << currentShift.getShiftNumber() << "\n";

	//The existing game logic for serving customers would go here. 
	//For now, we will simulate serving customers with a simple loop.

	while (!currentShift.isShiftOver() && customerIndex < static_cast<int>(orderBook.size()))
	{
		std::cout << currentShift.getStatusText() << "\n";
		double rating = game.serveCustomer(orderBook[customerIndex]);
		currentShift.serveCustomer(rating);
		customerIndex++;
	}
	game.finishShift();
}
int shiftManager::showShiftEnd(Game & game)
{
	std::cout << screens.getShiftOverText(
		currentShift.getShiftNumber(), currentShift.getAverageRating());
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Money earned this shift: $"
		<< game.getShiftTotal() << "\n";
	std::cout << "total balance: $"
		<< game.getCashTotal() << "\n\n";
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
	int choice;
	std::cout << screens.getShopText();
	choice = readChoice();
	while (choice != 0)
	{
		if (shop::isValidShopItem(choice))
		{
			std::cout << ingredients::getIngredientName(choice) << " costs $" << shop::getPriceCents(choice) / 100
				<< "." << std::setw(2) << std::setfill('0') << shop::getPriceCents(choice) % 100 << "\n";
		}
		else 
		{
			std::cout << screens.getInvalidChoiceText();
		}
		std::cout << screens.getShopText();
		choice = readChoice();
	}
}
int shiftManager::gameOver()
{
	int choice;
	std::cout << "Thank you for playing Kned the Bread!\n";
	std::cout << "You have reached the end of the demo.\n\n";
	std::cout << "1. Restart Game\n";
	std::cout << "2. Quit Game\n";
	std::cout << "Enter your choice: ";

	choice = readChoice();
	while (choice != 1 && choice != 2)
	{
		std::cout << screens.getInvalidChoiceText();
		std::cout << "1. Restart Game\n";
		std::cout << "2. Quit Game\n";
		std::cout << "Enter your choice: ";
		choice = readChoice();
	}
	return choice;
}
int shiftManager::readChoice()
{
	int choice;

	// std::cin >> choice fails if the input doesn't start with a number
	// (e.g. "abc"). When that happens, cin goes into an error state and
	// refuses all further reads until we reset it.
	while (!(std::cin >> choice))
	{
		std::cout << screens.getInvalidChoiceText();
		std::cin.clear(); // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
		std::cout << "Please enter a valid number: ";
	}


	// Skip trailing spaces/tabs so input like "2   " still counts as clean.
	// peek() looks at the next character without removing it.
	while (std::cin.peek() == ' ' || std::cin.peek() == '\t') {
		std::cin.get();
	}

	// After the number and any trailing whitespace, the next character
	// should be the newline from pressing Enter. Anything else means the
	// player typed extra junk after the number.
	bool hasExtraInput = std::cin.peek() != '\n';


	// Always clear the rest of the line (including the newline) so the
	// next prompt starts with fresh input.
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
	
	if (hasExtraInput) {
		return -1; // Return an invalid choice if there was extra input
	}
	return choice;
}