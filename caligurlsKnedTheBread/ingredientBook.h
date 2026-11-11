#pragma once
/// @class ingredientBook
/// @brief Holds all 10 ingredients and their code words from the Riddle Guide


/// Stateful class, one instance created when the program starts


/// Members:
/// -std::vector<IngredientData> allIngredients - all 10 ingredients


/// Methods:
/// -ingredientBook() - constructor; calls loadIngredients()
/// -void loadIngredients() - fills allIngredients with the guide's table
/// -std::vector<const IngredientData*> getByCategory(Category category) const - every ingredient in one category

#include <vector>
#include "ingredientData.h"
#include "category.h"
#include <string>

class ingredientBook
{
public:
	ingredientBook();
	void loadIngredients();
	std::vector<const IngredientData*> getByCategory(Category category) const;

private:
	std::vector<IngredientData> allIngredients;
};

