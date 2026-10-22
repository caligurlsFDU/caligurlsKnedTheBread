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
			const vector<string>& currentIngredients = sandwich.getIngredients();

			if (find(currentIngredients.begin(), currentIngredients.end(), name) != currentIngreidnets.end())
			{
				cout << "You already added " << name << ".\n"
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

			if (currentIngreidents.empty())
			{
				cout << "Your sandwich is empty\n";
				continue;
			}
			cout << "Current sandwich Ingreidnets:\n";
			for (int i = 0; i < static_cast<int>(currentIngreidents.size()); i++)
			{
				cout << i + 1 << ". " << currentIngredients[i] << "\n";
			}
			cout << "Enter the number of the ingredient to remove: ";
			getline(cin, input);
			stringstream removeStream(input);
			int removeChoice;
			if (!(removeStream >> removeChoice) || (removeStream >> extra)
			{
				cout << "Invalid input. Sandwich unchanged." << endl;
				continue;
			}
			if (removeChoice >= 1 && removeChoice <= static_cast<int>(currentIngredients.size()))
			{
				string name = currentIngreidents[removeChoice - 1];
			sandwich.removeIngredient(name);
			cout << "Removed " << name << ".\n";
			}
			else {
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
		// check is completed sandwich matches requested sandwich
		vector<string> correctIngredients = customer.getCorrectSandwich();

		if (sandwich.matchesOrder(correctIngredients))
		{
			cout << "\nCongratulations! You made the correct sandwich!\n\n";
			return 1;
		}
		else
		{
			cout << "\nSorry, that's not the correct sandwich. " << "The correct ingredients were:\n\n";
			for (const string& ingrdient : correctIngreidents)
			{
				cout << "- " << ingrdient << "\n"
			}
			return
		}
	} 