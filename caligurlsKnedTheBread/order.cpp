#include "order.h"
#include <algorithm>

// Constructor for the order class, initializes the display text and items
order::order(std::string displayText, std::vector<PickedItem> items)
{
	this->displayText = displayText;
	this->items = items;
}

// Returns the display text of the order
std::string order::getDisplayText() const
{
	return this->displayText;
}

//Creates a vector "names" that stores the real names of the ingredients in a generated order
//Sorts the names alphabetically
//Returns a string that is a list of the sorted ingredient names, separated by commas
//This is used to detect if an order has already been given in a shift (prevents repeated orders)

std::string order::getSignature() const
{
	std::vector<std::string> names;
	for (const auto& item : items)
	{
		names.push_back(item.ingredient->realName);
	}

	std::sort(names.begin(), names.end());
	
	std::string signature;
	for (const auto& name : names)
	{
		if (!signature.empty())
		{
			signature += ",";
		}
		signature += name;
	}
	return signature;
}

// Returns the vector of PickedItem objects that make up the order
const std::vector<PickedItem>& order::getItems() const
{
	return this->items;
}

