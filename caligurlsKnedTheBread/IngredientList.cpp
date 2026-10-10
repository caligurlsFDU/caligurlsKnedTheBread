
#include "IngredientList.h"

const int num_ingredients = 10;

const std::string ingredientNames[num_ingredients + 1] =
{
    "",                // 0 - unused (0 means "remove" in the menu)
    "White Bread",     // 1
    "Wheat Bread",     // 2
    "Ham",             // 3
    "Turkey",          // 4
    "Roast Beef",      // 5
    "American Cheese", // 6
    "Swiss Cheese",    // 7
    "Lettuce",         // 8
    "Tomato",          // 9
    "Mayo"             // 10
};


bool IngredientList::isValidIngredient(int number)
{
    return number >= 1 && number <= num_ingredients;
}

std::string IngredientList::getIngredientName(int number)
{
    if (!isValidIngredient(number))
    {
        return "Unknown";
    }
    return ingredientNames[number];
}

std::string IngredientList::getIngredientListText()
{
    std::string text;

    for (int i = 1; i <= num_ingredients; i++)
    {
        text += std::to_string(i) + ". " + ingredientNames[i] + "\n";
    }

    text += "0. Remove an ingredient\n";
    return text;
}