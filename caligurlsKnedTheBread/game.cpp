#include "game.h"
#include <iostream>
#include <string>

using namespace std;


void Game::startGame()
{
	cout << "╔══════════════════════════════════════╗" << endl;
	cout << "║           Kned the Bread             ║" << endl;
	cout << "╚══════════════════════════════════════╝" << endl;
	cout << endl;
	cout << "Game Started" << endl;
	getline(cin, input); // Press Enter to continue
	cout << "Well hot digity dog! Do my eyes have me decived?" << endl;
	getline(cin, input); 
	cout << "You must be the new hire!Welcome in chap!" << endl;
	getline(cin, input);
	cout << "Today is your lucky day!I'll guild you on your first day" << endl;
	getline(cin, input);
	cout << "Go Grab yourself an apron and a hat, and let's get started!" << endl;
	getline(cin, input);
}