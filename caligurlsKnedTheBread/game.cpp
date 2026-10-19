#include "game.h"
#include "customer.h"
#include "ingredients.h"
#include "sandwich.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

constexpr int removeIngredientOption = 0;
constexpr int finishSandwichOption = 11;

void Game::startGame()
{
	vector<Customer> orderBook = Customer::createCustomers();

int customerIndex = 0;

	while (customerIndex < orderBook.size())
	{
		cout << "Customer " << customerIndex + 1 << "'s order.";

		orderBook[customerIndex].displayOrder();

		Sandwich playerSandwich; //create a new sandwich for the player to make

		cout << ingredients::getIngredientListText();
		cout << finishSandwichOption << ". Finish sandwich\n";

		bool sandwichMade = false;

		while (sandwichMade == false)
		{
			int userChoice;
			cout << "Choose an option: ";
			cin >> userChoice;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please select a valid number.\n";
				continue;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (ingredients::isValidIngredient(userChoice))
			{
				string ingredientName = ingredients::getIngredientName(userChoice);

				playerSandwich.addIngredient(ingredientName);

				cout << "Added " << ingredientName << ".\n";
			}
			else if (userChoice == removeIngredientOption)
			{
				const vector<string>& currentIngredients = playerSandwich.getIngredients();

				if (currentIngredients.empty())
				{
					cout << "Your sandwich is empty.\n";
					continue;
				}

				cout << "Current sandwich ingredients:\n";

				for (int i = 0; i < static_cast<int>(currentIngredients.size());
				{
					cout << i + 1 << ". " << currentIngredients[i] << "\n";
				}

				int removeChoice;

				cout << "Enter the ingredient number to remove: ";
				cin >> removeChoice;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Please select a valid number.\n";
					continue;
				}

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (removeChoice >= 1 && removeChoice <= static_cast<int>(currentIngredients.size()))
				{
					string ingredientName = currentIngredients[removeChoice - 1];
					playerSandwich.removeIngredient(ingredientName);
					cout << "Removed " << ingredientName << ".\n";
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
				cout << "Please select a valid option.\n";
			}
		}
		if (playerSandwich.matchesOrder(orderBook[customerIndex].getCorrectSandwich()))
		{
			cout << "\nCongratulations! You made the correct sandwich!\n\n";
		}
		else
		{
			cout << "\nSorry, that's not the correct sandwich. The correct ingredients were:\n\n";

			for (const string& ingredient : orderBook[customerIndex].getCorrectSandwich())
			{
				cout << "- " << ingredient << "\n";
			}
		}
			customerIndex++; // Increment customerIndex to move to the next customer
	}
}