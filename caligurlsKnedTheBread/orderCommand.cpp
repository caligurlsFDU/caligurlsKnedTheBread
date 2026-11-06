#include "orderCommand.h"
#include "ingredients.h"
#include <string>

bool orderCommand::isOrderUp(std::string input)
{
	return ingredients::sanitize(input) == "order up";
}

bool orderCommand::isBin(std::string input)
{
	return ingredients::sanitize(input) == "bin";
}