#include "sandwich.h"
#include <algorithm>

Sandwich::Sandwich() 
{
}

void Sandwich::add_ingredient(const std::string& ingredient)
{
	auto it = std::find(ingredients.begin(), ingredients.end(), ingredient);
	if (it == ingredients.end())
	{
		ingredients.push_back(ingredient);
	}
}
void Sandwich::remove_ingredient(const std::string& ingredient)
{
	auto it = std::find(ingredients.begin(), ingredients.end(), ingredient);
	if (it != ingredients.end())
	{
		ingredients.erase(it);
	}
}

const std::vector<std::string>& Sandwich::get_ingredients() const
{
	return ingredients;
}

bool Sandwich::matches_order(const std::vector<std::string>& correctIngredients) const
{
	if (ingredients.size() != correctIngredients.size())
	{
		return false;
	}
	for (const std::string& ingredient : ingredients)
	{
		auto it = std::find(
			correctIngredients.begin(),
			correctIngredients.end(), 
			ingredient
		);

		if (it == correctIngredients.end())
		{
			return false;
		}
	}
	return true;
}