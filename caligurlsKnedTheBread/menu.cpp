#include "menu.h"
#include "game.h"
#include "customer.h"
#include <iostream>
#include <string>
using namespace std;


void Menu::displayMenu()
{
	bool running = true;
	string input;

	// Displays menu and loops unless start or exit are selected
	while (running)
	{

		cout << "╔══════════════════════════════════════╗" << endl;
		cout << "║                                      ║" << endl;
		cout << "║           Kned the Bread             ║" << endl;
		cout << "║                                      ║" << endl;
		cout << "╠══════════════════════════════════════╣" << endl;
		cout << "║                                      ║" << endl;
		cout << "║     Select an option to continue:    ║" << endl;
		cout << "║                                      ║" << endl;
		cout << "║  ▶ [1] Start                         ║" << endl;
		cout << "║  ▶ [2] Instructions                  ║" << endl;
		cout << "║  ▶ [3] Exit                          ║" << endl;
		cout << "║                                      ║" << endl;
		cout << "╠══════════════════════════════════════╣" << endl;
		cout << "║                                      ║" << endl;
		cout << "║      © 2026 CALI GURLS STUDIOS       ║" << endl;
		cout << "║                                      ║" << endl;
		cout << "╚══════════════════════════════════════╝" << endl << endl;

		cout << "▶ Enter your choice (1-3): ";

		if (!getline(cin, input)) 
			break;

		if (input == "1")
		{
			start();
			running = false;
		}
		else if (input == "2")
		{
			showInstructions();
			cout << "\nPress Enter to return to the menu...";
			getline(cin, input);
		}
		else if (input == "3")
		{
			cout << "Thanks for playing!" << endl;
			running = false;
		}
		else
		{
			cout << "\nSorry, we do not take orders off-menu, Please enter a number from 1 to 3." << endl;
		}
	}
}

//Where player goes when they select start
void Menu::start()
{
	Game game; 
	game.startGame();

}

void Menu::showInstructions()
{
	cout << "\nInstructions:\nYou are in a restaurant that offers a selection of assorted sandwiches. Buy ingredients, take tricky orders, build the sandwich that matches with the customer preferences, and restock more ingredients to keep the restaurant afloat. Survive as many days as possible until you run out of money. How many days will you survive with these customers?" << endl;
}