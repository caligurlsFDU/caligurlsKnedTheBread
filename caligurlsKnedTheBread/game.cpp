#include "game.h"
#include "customer.h"
#include "IngredientList.h"
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
				failed:
				cout << IngredientList::getIngredientListText();
				cin >> userChoice;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Please select an option between 1-10";
					goto failed;
				}

				if (IngredientList::isValidIngredient(userChoice))
				{
					cout << "Added " << IngredientList::getIngredientName(userChoice) << ".\n";
					// (whatever the group uses to store the sandwich goes here, ig sandwich class would handle this?)
				}
				else if (userChoice == 0)
				{
					// remove an ingredient
				}
				else
				{
					cout << "Please select an option between 0-10\n";
				}

				/*switch (userChoice)
				{

					
				}
				*/
			}

			//Should we move this whole sandwich making section to a new class? it feels like a lot just to be here.
			
			sandwichMade = false; //set 
			customerIndex++;
		}
		
	}

	
}