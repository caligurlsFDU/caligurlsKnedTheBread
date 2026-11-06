#pragma once
#include <iostream>
/// @class OrderCommands 
/// @brief Recognizes typed commands that aren't ingredients 
/// Stateless class, all methods are static, no constructor
/// Methods:
	/// -bool isOrderUp(string) - true if IngredientList::sanitize(input) == "order up" 
	/// /// -bool isBin(string) - true if IngredientList::sanitize(input) == "bin"
	
class orderCommand
{
public:
	static bool isOrderUp(std::string input);
	static bool isBin(std::string input);
};

