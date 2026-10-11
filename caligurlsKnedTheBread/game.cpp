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
	Customer* orderBook = new Customer[25];
	orderBook[0].setOrder("I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ", {"White Bread", "Ham", "American Cheese"});

	orderBook[1].setOrder("Gobble-gobble bird and the cheese full of holes, on the brown grainy slices, please. ", {"Wheat Bread", "Turkey", "Swiss Cheese"});

	orderBook[2].setOrder("Give me the cow, cooked low and slow, under the holey cheese from the Alps, on ghost-colored slices. ", { "Beef", "Lettuce", "Cheese" });

	orderBook[3].setOrder("Oink-oink meat, the cheese with holes, and that creamy eggy spread, all on the healthy-looking brown slices. ", { "White Bread", "Roast Beef", "Swiss Cheese" });

	orderBook[4].setOrder("Thanksgiving bird with rabbit food and the red fruit everyone calls a vegetable, on the plain pasty slices. ", { "Wheat Bread", "Ham", "Swiss Cheese", "Mayo" });

	orderBook[5].setOrder("Moo meat, the orange square that melts, and something leafy and green on the grainy brown slices. ", { "" });
	orderBook[6].setOrder("Pig AND Thanksgiving bird, both, on that pale stuff. No cheese, no veggies, no spread. ", { "" });
	orderBook[7].setOrder("Pink pork, crunchy leaves, red juicy slices, and the creamy eggy spread on the brown grainy kind. ", { "" });
	orderBook[8].setOrder("Just Uncle Sam's melty orange square on the pale slices. Nothing else, I'm keeping it simple. ", { "" });
	orderBook[9].setOrder("No meat, no cheese. I just want leaves and the red seedy slices on the brown grainy kind. ", { "" });
	orderBook[10].setOrder("The cow, cooked low and slow, with that creamy eggy spread on ghost-colored slices. ", { "" });
	orderBook[11].setOrder("Gobbler meat, the stars-and-stripes slice, and creamy eggy spread on the healthy brown slices.  ", { "" });
	orderBook[12].setOrder("Oink-oink, the Alpine cheese with holes, and red seedy slices, all on the pale stuff. ", { "" });
	orderBook[13].setOrder("Moo-cow meat, the holey cheese, and the red seedy slices on the brown grainy kind. ", { "" });
	orderBook[14].setOrder("The Thanksgiving bird, holey cheese, rabbit food, and the creamy eggy spread on the plain pasty slices.", { "" });
	orderBook[15].setOrder("I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ", { "" });
	orderBook[16].setOrder("Pig, bird, AND cow all stacked together on brown grainy slices. Skip the cheese, veggies, and spread.", { "" });
	orderBook[17].setOrder("Two cheeses: the orange square from Uncle Sam and the holey one from the Alps. Pale slices, nothing else.", { "" });
	orderBook[18].setOrder("Some pig with the red-white-and-blue cheese on the healthy-looking brown slices.", { "" });
	orderBook[19].setOrder("Gobble-gobble meat and the creamy eggy spread on ghost-colored slices. That's all.", { "" });
	orderBook[20].setOrder("Moo meat, rabbit food, and the creamy eggy spread on the brown grainy kind.", { "" });
	orderBook[21].setOrder("Pink pork, crunchy green leaves, and the creamy eggy spread on that pale stuff.", { "" });
	orderBook[22].setOrder("Thanksgiving bird and the red slices that are secretly a fruit, on the grainy brown kind.", { "" });
	orderBook[23].setOrder("Cow cooked low and slow, Uncle Sam's melty orange square, and red seedy slices on the pale stuff.", { "" });
	orderBook[24].setOrder("Pig and gobbler together, the holey cheese, leaves, red seedy slices, and the creamy eggy spread on pale slices. Hold the cow and the orange cheese. ", { "" });
	*/
	

	/*






"White Bread", "Turkey", "Lettuce", Tomato"

"Wheat Bread", Roast Beef, American Cheese, "Lettuce""

"White Bread", Ham, "Turkey"

"Wheat Bread", Ham, "Lettuce", Tomato, Mayo

"White Bread", American Cheese

"Wheat Bread", "Lettuce", Tomato

"White Bread", Roast Beef, Mayo

"Wheat Bread", "Turkey", American Cheese, Mayo

"White Bread", Ham, Swiss Cheese, Tomato

"Wheat Bread", Roast Beef, Swiss Cheese, Tomato

"White Bread", "Turkey", Swiss Cheese, "Lettuce", Mayo

"Wheat Bread", Ham, "Turkey", Roast Beef

"White Bread", American Cheese, Swiss Cheese

"Wheat Bread", Ham, American Cheese

"White Bread", "Turkey", Mayo

"Wheat Bread", Roast Beef, "Lettuce", Mayo

"White Bread", Ham, "Lettuce", Mayo

"Wheat Bread", "Turkey", Tomato

"White Bread", Roast Beef, American Cheese, Tomato

"Wheat Bread", American Cheese, Swiss Cheese, "Lettuce", Tomato

"White Bread", Ham, "Turkey", Swiss Cheese, "Lettuce", Tomato, Mayo


 

 

 

*/

	while (gamePlaying)
	{
		while (customerIndex < 5)
		{
			cout << "Customer " << customerIndex+1 << "'s order.";

			orderBook[customerIndex].displayOrder();

			cout << "\n\n\n";

			while (sandwichMade == false)
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