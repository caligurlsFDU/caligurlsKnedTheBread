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

bool gamePlaying = true;
int customerIndex = 0;
bool sandwichMade = false;
int userChoice;

	while (gamePlaying && customerIndex < orderBook.size())
	{
		cout << "Customer " << customerIndex + 1 << "'s order.";

		orderBook[customerIndex].displayOrder();

		Sandwich playerSandwich; //create a new sandwich for the player to make
		sandwichMade = false; //reset the sandwichMade variable for the new customer

		cout << ingredients::getIngredientListText();
		cout << finishSandwichOption << ". Finish sandwich\n";

		while (sandwichMade == false)
		{
			cout << "Choose an option: ";
			cin >> userChoice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please select a valid number.\n";
				continue;
			}
			cin.ignore(10000, '\n');

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

				for (int i = 0; i < currentIngredients.size(); i++)
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

				cin.ignore(10000, '\n');

				if (removeChoice >= 1 && removeChoice <= currentIngredients.size())
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
		if (playerSandwich.matches_order(orderBook[customerIndex].getCorrectSandwich()))
		{
			cout << "\nCongratulations! You made the correct sandwich!\n\n";
			customerIndex++;
		}
		else
		{
			cout << "\nSorry, that's not the correct sandwich. The correct ingredients were:\n\n";
			for (const string& ingredient : orderBook[customerIndex].getCorrectSandwich())
			{
				cout << "- " << ingredient << "\n";
			}
			customerIndex++; // Increment customerIndex to move to the next customer
		}
	}
}