#include "ingredientBook.h"

//constructor calls loadIngredients() to fill the list
ingredientBook::ingredientBook() 
{
    loadIngredients();
}

// adds all 10 ingredients real name, ingredient category, and code words to allIngredients vector
// clears the vector first so calling this twice can't create duplicates
void ingredientBook::loadIngredients()
{
    allIngredients.clear();

    allIngredients.push_back({ "White Bread", Category::Bread,
        { "pale stuff", "ghost-colored slices", "plain pasty slices" } });

    allIngredients.push_back({ "Wheat Bread", Category::Bread,
        { "brown grainy slices", "healthy-looking brown slices" } });

    allIngredients.push_back({ "Ham", Category::Meat,
    { "pig", "oink-oink meat", "pink pork" } });

	allIngredients.push_back({ "Turkey", Category::Meat,
		{ "gobbler", "Thanksgiving bird", "gobble-gobble bird" } });

    allIngredients.push_back({ "Roast Beef", Category::Meat,
    { "moo meat", "slow-cooked cow" } });

	allIngredients.push_back({ "American Cheese", Category::Cheese,
	{ "Uncle Sam's cheese", "stars-and-stripes slice", "melty orange square" } });

	allIngredients.push_back({ "Swiss Cheese", Category::Cheese,
	{ "holey cheese", "Alpine cheese" } });

	allIngredients.push_back({ "Lettuce", Category::Veggie,
		{ "green rabbit food", "crunchy leaves", "leafy greens" } });

    allIngredients.push_back({ "Tomato", Category::Veggie,
    { "red seedy slice", "secret fruit" } });

	allIngredients.push_back({ "Mayo", Category::Condiment,
	{ "creamy eggy spread", "eggy sandwich glue" } });
}

//returns a list of pointers to all ingredients in a given category
//pointers point to IngredientData objects in allIngredients vector
std::vector<const IngredientData*> ingredientBook::getByCategory(Category category) const
{
	std::vector<const IngredientData*> result;
	for (const auto& ingredient : allIngredients)
	{
		if (ingredient.category == category)
		{
			result.push_back(&ingredient);
		}
	}
	return result;
}
