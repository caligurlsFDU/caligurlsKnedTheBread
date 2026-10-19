#include "sandwich.h"
#include <algorithm>
#include <sstream>

Sandwich::Sandwich() 
{
}

void Sandwich::addIngredient(const std::string& ingredient)
{
	auto ingredientIterator = std::find(ingredients.begin(), ingredients.end(), ingredient);
	if (ingredientIterator == ingredients.end())
	{
		ingredients.push_back(ingredient);
	}
}
void Sandwich::removeIngredient(const std::string& ingredient)
{
	auto ingredientIterator = std::find(ingredients.begin(), ingredients.end(), ingredient);
	if (ingredientIterator != ingredients.end())
	{
		ingredients.erase(ingredientIterator);
	}
}

const std::vector<std::string>& Sandwich::getIngredients() const
{
	return ingredients;
}

bool Sandwich::matchesOrder(const std::string& correctSandwich) const
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
	
	return matchesOrder(correctIngredients);
	}

	bool Sandwich::matchesOrder(const std::vector<std::string>&correctIngredients) const
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