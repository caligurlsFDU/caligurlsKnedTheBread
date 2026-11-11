#pragma once
#include <string>
#include <vector>
#include "category.h"

/// @struct IngredientData
/// @brief One row of the code word table
/// Members:
/// -std::string realName - exact name the player types ("Roast Beef")
/// -Category category - which group it belongs to (Category::Meat)
/// -std::vector<std::string> codeWords - 2 to 3 code words
struct IngredientData 
{
    std::string realName;
    Category category;
    std::vector<std::string> codeWords;
};

/// @struct PickedItem
/// @brief One ingredient chosen for an order, plus the code word picked for it
/// Members:
/// -const IngredientData* ingredient - points into IngredientBook's list
/// -std::string codeWord - the code word shown in the sentence
struct PickedItem 
{
    const IngredientData* ingredient;
    std::string codeWord;
};

