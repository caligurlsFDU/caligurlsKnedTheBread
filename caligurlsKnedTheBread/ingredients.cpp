
#include "ingredients.h"

const int num_ingredients = 10;

const std::string ingredientNames[num_ingredients + 1] =
{
    "",                // 0 - unused (0 means "remove" in the menu)
    "White Bread",     // 1
	"Wheat Bread",     // 2 this is like brown bread, but we can call it wheat bread to make it more clear for the player
    "Ham",             // 3
    "Turkey",          // 4
    "Roast Beef",      // 5
    "American Cheese", // 6
    "Swiss Cheese",    // 7
    "Lettuce",         // 8
    "Tomato",          // 9
    "Mayo"             // 10
};


bool ingredients::isValidIngredient(int number)
{
    return number >= 1 && number <= num_ingredients;
}

std::string ingredients::getIngredientName(int number)
{
    if (!isValidIngredient(number))
    {
        return "Unknown";
    }
    return ingredientNames[number];
}

std::string ingredients::getIngredientListText()
{
    std::string text;

    for (int i = 1; i <= num_ingredients; i++)
    {
        text += std::to_string(i) + ". " + ingredientNames[i] + "\n";
    }

    text += "0. Remove an ingredient\n";
    return text;
}