
#include "IngredientList.h"

const int NUM_INGREDIENTS = 10;

const std::string INGREDIENT_NAMES[NUM_INGREDIENTS + 1] =
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
    return number >= 1 && number <= NUM_INGREDIENTS;
}

std::string IngredientList::getIngredientName(int number)
{
    if (!isValidIngredient(number))
    {
        return "Unknown";
    }
    return INGREDIENT_NAMES[number];
}

std::string IngredientList::getIngredientListText()
{
    std::string text;

    for (int i = 1; i <= NUM_INGREDIENTS; i++)
    {
        text += std::to_string(i) + ". " + INGREDIENT_NAMES[i] + "\n";
    }

    text += "0. Remove an ingredient\n";
    return text;
}