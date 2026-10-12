#include "sandwich.h"

Sandwich::Sandwich() 
{
}
void Sandwich::add_ingredient(const std::string& ingredient)
{
	ingredients.push_back(ingredient);
}

const std::vector<std::string>& Sandwich::get_ingredients() const
{
	return ingredients;
}