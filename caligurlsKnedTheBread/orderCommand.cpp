#include "orderCommand.h"
#include "ingredients.h"
#include <algorithm>
#include <cctype>
#include <string>

//sanitization commands finished
bool orderCommand::isOrderUp(std::string input)
{
	bool toReturn = false;

	std::transform(input.begin(), input.end(), input.begin(),
		[](unsigned char c) { return std::tolower(c); });

	if (input == "order up")
	{
		toReturn = true;
	}
	return toReturn;
}

bool orderCommand::isBin(std::string input)
{
	bool toReturn = false;

	std::transform(input.begin(), input.end(), input.begin(),
		[](unsigned char c) { return std::tolower(c); });

	if (input == "bin")
	{
		toReturn = true;
	}
	return toReturn;
}