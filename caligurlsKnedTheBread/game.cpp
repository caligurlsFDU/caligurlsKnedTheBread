#include "game.h"
#include "customer.h"
#include <iostream>
using namespace std;

bool gamePlaying = true;
int customerIndex = 0;
bool sandwichMade = false;
int userChoice;

void Game::startGame()
{
	Customer* customerList = new Customer[5];


	while (gamePlaying)
	{
		while (customerIndex < 5)
		{
			cout << "Customer " << customerIndex+1 << "'s order.";

			customerList[customerIndex].displayOrder();

			cout << "\n\n\n";

			while (sandwichMade = false)
			{
				cout << "Sandwich Ingredient List:\n 1: White Bread.\n 2: Wheat Bread. ";
				cin >> 
			}
			
			sandwichMade = false; //set 
			customerIndex++;
		}
		
	}

	
}