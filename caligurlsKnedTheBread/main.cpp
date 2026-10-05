#include "Menu.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	// Set the console output code page to allow UTF-8 characters used in menu display
	SetConsoleOutputCP(CP_UTF8);

	Menu menu;
	menu.displayMenu();

	return 0;
}