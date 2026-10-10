#include<string>

class IngredientList
{
/// @class IngredientList
/// @brief Defines the 10 ingredients the player can pick from
/// Stateless class, all methods are static, no constructor (avoid that issue faced in C++ Nim workshop!)
///   (call directly - e.g. IngredientList::getIngredientName(3))
/// Methods:
///  -string getIngredientName(int) - returns the name for numbers 1-10
///  -bool isValidIngredient(int) - true if 1-10
///  -string getIngredientListText() - returns the numbered list plus "0. Remove an ingredient"

public:
	static std::string getIngredientName(int ingredientNumber);
	static bool isValidIngredient(int ingredientNumber);
	static std::string getIngredientListText();
};
