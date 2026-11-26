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
	for (int shift = 1; shift <= shiftConfig::getTotalShifts(); shift++)
	{
		events.rollEvent(shift);

		const int customersPerShift =
			shiftConfig::getCustomerCount(shift) *
			events.getCurrentEvent().customerMultiplier;

		game.getOrderGenerator().startNewShift();
		orderBook = Customer::createCustomers(
			game.getOrderGenerator(),
			customersPerShift,
			events.getCurrentEvent().minMeats,
			events.getCurrentEvent().scrambleText);

		customerIndex = 0;

		runShift(shift, game);

		if (!game.payUtilities(shift, currentShift.getAverageRating(),
			events.getCurrentEvent().name))
		{
			game.gameOver(shift);
			return;
		}

		int choice = showShiftEnd(game);

		if (choice == 2)
		{
			showShop(game);
		}
		else if (choice == 3)
		{
			std::cout << "Exiting game. Thank you for playing!\n";
			return;
		}
	}
}
void shiftManager::runShift(int shift, Game& game)
{
	game.resetShiftTotal();
	currentShift.startShift(shift);
	game.clearScreen();

	events.announceEvent();

	int customerNumber = 1;

	while (!currentShift.isShiftOver() &&
		customerIndex < static_cast<int>(orderBook.size()))
	{
		game.displayHeader(
			currentShift.getShiftNumber(),
			customerNumber,
			currentShift.getAverageRating(),
			events.getCurrentEvent().name
		);
		double rating = game.serveCustomer(
			orderBook[customerIndex],
			shift,
			events.getCurrentEvent().payMultiplier,
			events.getCurrentEvent().allOrNothing
		);
		currentShift.serveCustomer(rating);
		customerIndex++;
		customerNumber++;

		game.pressEnterToContinue();
	}

	game.finishShift();
}
int shiftManager::showShiftEnd(Game & game)
{
	game.displayHeader(currentShift.getShiftNumber(), 0, currentShift.getAverageRating(), events.getCurrentEvent().name);

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
	game.displayHeader(currentShift.getShiftNumber(), 0, currentShift.getAverageRating(), events.getCurrentEvent().name);
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