#include<string>
/// @enum Ingredient
/// @brief The 10 ingredients, numbered 1-10 to match the Shift 1 guide
///   INVALID = 0, INGREDIENT_1 = 1, INGREDIENT_2 = 2, ... INGREDIENT_10 = 10
///   (swap in the real names - e.g. HAM = 6, AMERICAN_CHEESE = 7)
///   INVALID returned whenever input doesn't match an ingredient

/// @class IngredientList
/// @brief Defines the 10 ingredients the player can pick from


/// Stateless class, all methods are static, no constructor (avoid that issue faced in C++ Nim workshop!)
///   (call directly - e.g. IngredientList::getIngredientName(Ingredient::HAM))


/// Methods:
///  -string getIngredientName(Ingredient) - returns the display name, e.g. HAM -> "ham"
///  -bool isValidIngredient(Ingredient) - true if anything other than INVALID
///  -string getIngredientListText() - returns the numbered list plus "0. Remove an ingredient" (Shift 1 only)
///  -Ingredient fromNumber(int) - Shift 1: returns the matching enum for 1-10, otherwise INVALID
///  -string sanitize(string) - Shift 2+: trims spaces and lowercases
///  -Ingredient fromText(string) - Shift 2+: sanitizes, then matches against the lowercase names;
///       returns INVALID if misspelled or a number

class ingredients
{
public:
	static std::string getIngredientName(int ingredientNumber);
	static bool isValidIngredient(int ingredientNumber);
	static std::string getIngredientListText();
};
