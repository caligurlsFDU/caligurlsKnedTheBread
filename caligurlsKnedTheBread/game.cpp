#include "game.h"
#include "customer.h"
#include "ingredients.h"
#include "sandwich.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool gamePlaying = true;
int customerIndex = 0;
bool sandwichMade = false;
int userChoice;

void Game::startGame()
{
	//new comment
	Customer* orderBook = new Customer[25];
	orderBook[0].setOrder("I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ", { "White Bread", "Ham", "American Cheese" });
	orderBook[1].setOrder("Gobble-gobble bird and the cheese full of holes, on the brown grainy slices, please. ", { "Wheat Bread", "Turkey", "Swiss Cheese" });
	orderBook[2].setOrder("Give me the cow, cooked low and slow, under the holey cheese from the Alps, on ghost-colored slices. ", { "White Bread", "Roast Beef", "Swiss Cheese" });
	orderBook[3].setOrder("Oink-oink meat, the cheese with holes, and that creamy eggy spread, all on the healthy-looking brown slices. ", { "Wheat Bread", "Ham", "Swiss Cheese", "Mayo" });
	orderBook[4].setOrder("Thanksgiving bird with rabbit food and the red fruit everyone calls a vegetable, on the plain pasty slices. ", { "White Bread", "Turkey", "Lettuce", "Tomato" });
	orderBook[5].setOrder("Moo meat, the orange square that melts, and something leafy and green on the grainy brown slices. ", { "Wheat Bread", "Roast Beef", "American Cheese", "Lettuce" });
	orderBook[6].setOrder("Pig AND Thanksgiving bird, both, on that pale stuff. No cheese, no veggies, no spread. ", { "White Bread", "Ham", "Turkey" });
	orderBook[7].setOrder("Pink pork, crunchy leaves, red juicy slices, and the creamy eggy spread on the brown grainy kind. ", { "Wheat Bread", "Ham", "Lettuce", "Tomato", "Mayo" });
	orderBook[8].setOrder("Just Uncle Sam's melty orange square on the pale slices. Nothing else, I'm keeping it simple. ", { "White Bread", "American Cheese" });
	orderBook[9].setOrder("No meat, no cheese. I just want leaves and the red seedy slices on the brown grainy kind. ", { "Wheat Bread", "Lettuce", "Tomato" });
	orderBook[10].setOrder("The cow, cooked low and slow, with that creamy eggy spread on ghost-colored slices. ", { "White Bread", "Roast Beef", "Mayo" });
	orderBook[11].setOrder("Gobbler meat, the stars-and-stripes slice, and creamy eggy spread on the healthy brown slices.  ", { "Wheat Bread", "Turkey", "American Cheese", "Mayo" });
	orderBook[12].setOrder("Oink-oink, the Alpine cheese with holes, and red seedy slices, all on the pale stuff. ", { "White Bread", "Ham", "Swiss Cheese", "Tomato" });
	orderBook[13].setOrder("Moo-cow meat, the holey cheese, and the red seedy slices on the brown grainy kind. ", { "Wheat Bread", "Roast Beef", "Swiss Cheese", "Tomato" });
	orderBook[14].setOrder("The Thanksgiving bird, holey cheese, rabbit food, and the creamy eggy spread on the plain pasty slices.", { "White Bread", "Turkey", "Swiss Cheese", "Lettuce", "Mayo" });
	orderBook[15].setOrder("I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ", { "White Bread", "Ham", "American Cheese" });
	orderBook[16].setOrder("Pig, bird, AND cow all stacked together on brown grainy slices. Skip the cheese, veggies, and spread.", { "Wheat Bread", "Ham", "Turkey", "Roast Beef" });
	orderBook[17].setOrder("Two cheeses: the orange square from Uncle Sam and the holey one from the Alps. Pale slices, nothing else.", { "White Bread", "American Cheese", "Swiss Cheese" });
	orderBook[18].setOrder("Some pig with the red-white-and-blue cheese on the healthy-looking brown slices.", { "Wheat Bread", "Ham", "American Cheese" });
	orderBook[19].setOrder("Gobble-gobble meat and the creamy eggy spread on ghost-colored slices. That's all.", { "White Bread", "Turkey", "Mayo" });
	orderBook[20].setOrder("Moo meat, rabbit food, and the creamy eggy spread on the brown grainy kind.", { "Wheat Bread", "Roast Beef", "Lettuce", "Mayo" });
	orderBook[21].setOrder("Pink pork, crunchy green leaves, and the creamy eggy spread on that pale stuff.", { "White Bread", "Ham", "Lettuce", "Mayo" });
	orderBook[22].setOrder("Thanksgiving bird and the red slices that are secretly a fruit, on the grainy brown kind.", { "Wheat Bread", "Turkey", "Tomato" });
	orderBook[23].setOrder("Cow cooked low and slow, Uncle Sam's melty orange square, and red seedy slices on the pale stuff.", { "White Bread", "Roast Beef", "American Cheese", "Tomato" });
	orderBook[24].setOrder("Pig and gobbler together, the holey cheese, leaves, red seedy slices, and the creamy eggy spread on pale slices. Hold the cow and the orange cheese. ", { "White Bread", "Ham", "Turkey", "Swiss Cheese", "Lettuce", "Tomato", "Mayo" });




	while (gamePlaying && customerIndex < 25)
	{
		cout << "Customer " << customerIndex + 1 << "'s order.";

		orderBook[customerIndex].displayOrder();

		Sandwich playerSandwich; //create a new sandwich for the player to make
		sandwichMade = false; //reset the sandwichMade variable for the new customer

		cout << ingredients::getIngredientListText();
		cout << "11. Finish sandwich\n";

		while (sandwichMade == false)
		{
			cout << "Choose an option: ";
			cin >> userChoice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please select a valid option.\n";
				continue;
			}

			if (cin.peek() != '\n') // Check if there are extra characters in the input buffer
			{
				cin.ignore(10000, '\n');
				cout << "Please enter 1 number at a time.\n";
				continue;
			}

			char extra;
			cin.get(extra);

			if (extra != '\n') // Check if there are extra characters in the input buffer
			{
				cout << "Please enter 1 number at a time.\n";
				cin.ignore(10000, '\n');
				continue;
			}

			if (ingredients::isValidIngredient(userChoice))
			{
				string ingredientName = ingredients::getIngredientName(userChoice);

				playerSandwich.add_ingredient(ingredientName);

				cout << "Added " << ingredientName << ".\n";
			}
			else if (userChoice == 0)
			{
				const vector<string>& currentIngredients = playerSandwich.get_ingredients();

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

				cout << "Enter the ingredient number to remove: ";

				int removeChoice;
				cin >> removeChoice;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Please select a valid number.\n";
					continue;
				}

				if (removeChoice >= 1 && removeChoice <= currentIngredients.size())
				{
					string ingredientName = currentIngredients[removeChoice - 1];
					playerSandwich.remove_ingredient(ingredientName);
					cout << "Removed " << ingredientName << ".\n";
				}
				else
				{
					cout << "Choose the ingredient number to remove.\n";
				}
			}
			else if (userChoice == 11)
			{
				sandwichMade = true;
			}
			else
			{
				cout << "Please select an option between 1 and 11.\n";
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