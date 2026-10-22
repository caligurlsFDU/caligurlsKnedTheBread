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

using namespace std;

constexpr int removeIngredientOption = 0;
constexpr int finishSandwichOption = 11;

void Game::startGame()
{
	shiftManager shiftMgr;
	shiftMgr.runAllShifts(*this);
}
int Game::serveCustomer(Customer& customer)
{
	cout << "Customer Order:" << endl;
	customer.displayOrder();
	Sandwich sandwich;
	cout << ingredients::getIngredientListText() << endl;
	cout << finishSandwichOption << ". Finish Sandwich" << endl;
	bool sandwichMade = false;
	while (!sandwichMade)
	{
		int userChoice;
		string input;
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
			sandwich.addIngredient(name);
			cout << "Added " << name << "." << endl;
		}
		else if (userChoice == removeIngredientOption)
		{
			cout << "Enter the number of the ingredient to remove: ";
			getline(cin, input);
			stringstream removeStream(input);
			int removeChoice;
			if (!(removeStream >> removeChoice) || (removeStream >> extra)
				|| !ingredients::isValidIngredient(removeChoice))
			{
				cout << "Invalid input. Sandwich unchanged." << endl;
				continue;
			}
			string name = ingredients::getIngredientName(removeChoice);
			sandwich.removeIngredient(name);
			cout << "Removed " << name << "." << endl;
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
} 