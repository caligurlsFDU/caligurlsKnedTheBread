#include "menu.h"
#include <iostream>
#include <string>
using namespace std;


void Menu::displayMenu()
{
	string input;

	cout << "╔══════════════════════════════════════╗" << endl;
	cout << "║                                      ║" << endl;
	cout << "║           Kned the Bread	       ║" << endl;
	cout << "║                                      ║" << endl;
	cout << "╠══════════════════════════════════════╣" << endl;
	cout << "║                          	       ║" << endl;
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

	// Loops until valid input is entered
	while (true)
	{
		if (!getline(cin, input)) break;

		if (input == "1")
		{
			start();
			break;
		}
		else if (input == "2")
		{
			showInstructions();
			break;
		}
		else if (input == "3")
		{
			cout << "Thanks for playing!" << endl;
			break;
		}
		else
		{
			cout << "\nInvalid input. Please enter a number from 1 to 3." << endl;
			cout << "▶ Enter your choice (1-3): ";
		}
	}
}

//Where player goes when they select start
void Menu::start()
{
	cout << "Starting game..." << endl;
}

void Menu::showInstructions()
{
	cout << "These are the instructions." << endl;
}