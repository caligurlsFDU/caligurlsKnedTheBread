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
		customerIndex = 0;

		for (int shift = 1; shift <= shiftConfig::getTotalShifts(); shift++)
		{
			const int customersPerShift = 7;

			game.getOrderGenerator().startNewShift();
			orderBook = Customer::createCustomers(game.getOrderGenerator(), customersPerShift);
			customerIndex = 0;

			runShift(shift, game);
			if (!game.payUtilities(shift, currentShift.getAverageRating()))
			{
				game.gameOver(shift);
				return;
			}
			//end go game display
			if (shift == shiftConfig::getTotalShifts())
			{
				std::cout << "Congrats you completed all three shifts in the demo";
				std::cout << "Thanks for playing kned the bread";
				return;
			}

			choice = showShiftEnd(game);

			if (choice == 2) //shop
			{
				showShop(game);
			}
			else if (choice == 3) // exit game
			{
				std::cout << "Exiting game. Thank you for playing!\n";
				return;
			}
		}
	}
}


void shiftManager::runShift(int shift, Game& game)
{
	game.resetShiftTotal();
	currentShift.startShift(shift);
	game.clearScreen();
	int customerNumber = 1;

	//The existing game logic for serving customers would go here. 
	//For now, we will simulate serving customers with a simple loop.

	while (!currentShift.isShiftOver() && customerIndex < static_cast<int>(orderBook.size()))
	{
		game.displayHeader(currentShift.getShiftNumber(), customerNumber, currentShift.getAverageRating());
		double rating = game.serveCustomer(orderBook[customerIndex], shift);
		currentShift.serveCustomer(rating);
		customerIndex++;
		customerNumber++;
		//pause
		game.pressEnterToContinue();
	}
	game.finishShift();
}
int shiftManager::showShiftEnd(Game & game)
{
	game.displayHeader(currentShift.getShiftNumber(), 0, currentShift.getAverageRating());

	std::cout << screens.getShiftOverText(currentShift.getShiftNumber(), currentShift.getAverageRating());
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Money earned this shift: $"
		<< game.getShiftTotal() << "\n";
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
void shiftManager::showShop(Game& game)
{
	game.clearScreen();
	game.displayHeader(currentShift.getShiftNumber(), 0, currentShift.getAverageRating());
	int choice;
	std::cout << std::fixed << std::setprecision(2);
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

		std::cout << "Enter an ingredient number or 0 to exit:\n";
		choice = readChoice();
	}
	std::cout << "Leaving shop\n";
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