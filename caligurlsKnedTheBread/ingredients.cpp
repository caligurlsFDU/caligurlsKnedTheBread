
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

const double ingredientPrices[num_ingredients + 1] =
{
    0.00, //unused 0
    1.00, //established price of white bread 1
    1.25, //price of wheat bread 2
    1.50, //price of ham 3
    1.75, //price of turkey 4
    2.00, //price of roast beef 5
    0.50, //price of american cheese 6
    0.75, //price of swiss cheese 7
    0.25, //price of lettuce 8
    0.50, //price of tomato 9
    0.25, //price of mayo 10

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