#include "game.h"
#include "customer.h"
#include "shiftManager.h"
#include "ingredients.h"
#include "sandwich.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "orderCommand.h"

using namespace std;

constexpr int removeIngredientOption = 0;
constexpr int finishSandwichOption = 11;

// startGame
// Entry point for a play session. Hands control to the shift manager, which
// runs every shift and calls back into this Game (via *this) whenever a
// customer needs to be served.
void Game::startGame()
{
	shiftManager shiftMgr;
	shiftMgr.runAllShifts(*this);
}

// serveCustomer
// Runs the sandwich-building interaction for one customer:
//   1. Show the customer's order and the ingredient menu.
//   2. Let the player add/remove ingredients until they choose "Finish".
//   3. Compare the finished sandwich to the order and score it.
// Returns the star rating (out of 5) so the shift can track its average.
double Game::serveCustomer(Customer& customer, int shift)
{
	const bool isFirstShift = (shift == 1);
	const vector<string> correctIngredients = customer.getCorrectSandwich();

	cout << "Customer Order:" << endl;
	customer.displayOrder();
	Sandwich sandwich;

	if (isFirstShift)
	{
		cout << ingredients::getIngredientListText() << endl;
		cout << finishSandwichOption << ". Finish Sandwich" << endl;
	}
	else
	{
		cout << "Type an ingredient name to add it. Type 'order up' when finished. Type 'bin' to remove ingredients from the sandwich.\n";
	}

	bool sandwichMade = false;
	while (!sandwichMade)
	{
		string input;

		// ---------- Shift 2+: typed ingredient names ----------
		if (!isFirstShift)
		{
			cout << "Enter ingredient: ";
			getline(cin, input);

			if (orderCommand::isOrderUp(input))
			{
				if (sandwich.matchesOrder(correctIngredients))
				{
					sandwichMade = true;
				}
				else
				{
					cout << "The order isn't complete yet. You're still missing ingredients.\n";
				}
				continue;
			}

			Ingredient ing = ingredients::fromText(input);
			if (ing == Ingredient::INVALID)
			{
				cout << "\"" << input << "\" wasn't accepted. Check your spelling.\n";
				continue;
			}

			string name = ingredients::getIngredientName(static_cast<int>(ing));
			bool inOrder = find(correctIngredients.begin(), correctIngredients.end(), name)
				!= correctIngredients.end();
			const vector<string>& current = sandwich.getIngredients();

			if (!inOrder)
			{
				cout << name << " isn't part of this order, so it wasn't added.\n";
			}
			else if (find(current.begin(), current.end(), name) != current.end())
			{
				cout << "You already added " << name << ".\n";
			}
			else
			{
				sandwich.addIngredient(name);
				cout << "Added " << name << ".\n";
			}
			continue;
		}

		// ---------- Shift 1: numbered menu (existing logic) ----------
		int userChoice;
		cout << "Enter your choice: ";
		getline(cin, input);
		stringstream inputStream(input);
		char extra;

		if (!(inputStream >> userChoice) || (inputStream >> extra))
		{
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}
		if (ingredients::isValidIngredient(userChoice))
		{
			string name = ingredients::getIngredientName(userChoice);
			const vector<string>& currentIngredients = sandwich.getIngredients();

			if (find(currentIngredients.begin(), currentIngredients.end(), name) != currentIngredients.end())
			{
				cout << "You already added " << name << ".\n";
			}
			else
			{
				sandwich.addIngredient(name);
				cout << "Added " << name << ".\n";
			}
		}
		else if (userChoice == removeIngredientOption)
		{
			const vector<string>& currentIngredients = sandwich.getIngredients();

			if (currentIngredients.empty())
			{
				cout << "Your sandwich is empty\n";
				continue;
			}
			cout << "Current sandwich ingredients:\n";
			for (int i = 0; i < static_cast<int>(currentIngredients.size()); i++)
			{
				cout << i + 1 << ". " << currentIngredients[i] << "\n";
			}
			cout << "Enter the number of the ingredient to remove: ";
			getline(cin, input);
			stringstream removeStream(input);
			int removeChoice;
			if (!(removeStream >> removeChoice) || (removeStream >> extra))
			{
				cout << "Invalid input. Sandwich unchanged.\n";
				continue;
			}
			if (removeChoice >= 1 && removeChoice <= static_cast<int>(currentIngredients.size()))
			{
				string name = currentIngredients[removeChoice - 1];
				sandwich.removeIngredient(name);
				cout << "Removed " << name << ".\n";
			}
			else
			{
				cout << "Choose a valid ingredient number to remove.\n";
			}
		}
		else if (userChoice == finishSandwichOption)
		{
			sandwichMade = true;
		}
		else
		{
			cout << "Invalid choice. Please pick a number from the list." << endl;
		}
	}

	// check if completed sandwich matches requested sandwich
	if (sandwich.matchesOrder(correctIngredients))
	{
		cout << "\nCongratulations! You made the correct sandwich!\n\n";
	}
	else
	{
		cout << "\nSorry, that's not the correct sandwich. " << "The correct ingredients were:\n\n";
		for (const string& ingredient : correctIngredients)
		{
			cout << "- " << ingredient << "\n";
		}
	}

	double stars = sandwich.orderStars(correctIngredients);
	cout << "\nYou earned " << stars << " / 5 stars\n\n";

	return stars;
}