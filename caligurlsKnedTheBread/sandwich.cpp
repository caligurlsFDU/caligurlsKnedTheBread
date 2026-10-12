#include "sandwich.h"
#include <algorithm>
#include <sstream>

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

bool Sandwich::matches_order(const std::string& correctSandwich) const
{
		
	std::vector<std::string> correctIngredients;
	std::stringstream ss(correctSandwich);
	std::string ingredient;

	while (std::getline(ss, ingredient, ','))
	{
		size_t start = ingredient.find_first_not_of(" \t");
		if (start != std::string::npos)
		{
			ingredient.erase(0, start);
		}
		size_t end = ingredient.find_last_not_of(" \t");
		if (end != std::string::npos)
		{
			ingredient.erase(end + 1);
		}
		correctIngredients.push_back(ingredient);
	}
	
	return matches_order(correctIngredients);
	}

	bool Sandwich::matches_order(const std::vector<std::string>&correctIngredients) const
	{
		if (ingredients.size() != correctIngredients.size())
		{
			return false;
		}
		for (const std::string& ingredient : ingredients)
		{
			auto it = std::find(correctIngredients.begin(),
				correctIngredients.end(),
				ingredient);
				

				if (it == correctIngredients.end())
				{
					return false;
				}
		}
		return true;
	}