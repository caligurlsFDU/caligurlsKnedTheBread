#include "game.h"
#include <iostream>
#include <string>

using namespace std;


void Game::startGame()
{
	string input;
	cout << "╔══════════════════════════════════════╗" << endl;
	cout << "║           Kned the Bread             ║" << endl;
	cout << "╚══════════════════════════════════════╝" << endl;
	cout << endl;
	cout << "Game Started" << endl;
	cout << "[Press Enter to continue...]" << endl;
	getline(cin, input); // Press Enter to continue
	cout << "Well hot digity dog! Do my eyes have me decived?" << endl;
	cout << "[Press Enter to continue...]" << endl;
	getline(cin, input); 
	cout << "You must be the new hire!Welcome in chap!" << endl;
	cout << "[Press Enter to continue...]" << endl;
	getline(cin, input);
	cout << "Today is your lucky day!I'll guild you on your first day" << endl;
	cout << "[Press Enter to continue...]" << endl;
	getline(cin, input);
	cout << "Go Grab yourself an apron and a hat, and let's get started!" << endl;
	cout << "[Press Enter to continue...]" << endl;
	getline(cin, input);
	cout << "End of current game" << endl;
	cout << "[Press Enter to quit...]" << endl;
}