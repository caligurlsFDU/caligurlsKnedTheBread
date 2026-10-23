#include "sandwich.h"
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <cmath>

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

	// CALI 28 STAR SYSTEM CODE

	double Sandwich::orderStars(const std::vector<std::string>& correctIngredients)
	{
		const size_t asked = correctIngredients.size();
		const size_t delivered = ingredients.size();

		// Count how many of each ingredient was asked for
		std::unordered_map<std::string, int> remaining;
		for (const auto& item : correctIngredients)
		{
			++remaining[item];
		}

		// Count delivered ingredients that match, using each asked-for one at most once
		size_t correct = 0;
		for (const auto& item : ingredients)
		{
			auto it = remaining.find(item);
			if (it != remaining.end() && it->second > 0)
			{
				++correct;
				--it->second;
			}
		}

		// Guard against divide-by-zero (empty order and empty sandwich)
		if (asked == 0 && delivered == 0)
		{
			return 5.0; //default value
		}

		if (asked >= delivered)
		{
			return std::round(static_cast<double>(correct) / asked * 5.0 * 2.0) / 2.0;
		}
		else
		{
			return std::round(static_cast<double>(correct) / delivered * 5.0 * 2.0) / 2.0;
		}
	}