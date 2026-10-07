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
				failed:
				cout << "Sandwich Ingredient List:\n 1: White Bread.\n 2: Wheat Bread.\n 3: Ham \n 4: Turkey \n 5: Roast Beef: \n 6: American Cheese \n 7: Swiss Cheese \n 8: Lettuce \n 9: Tomato \n 10: Mayo";
				cin >> userChoice;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Please select an option between 1-10";
					goto failed;
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