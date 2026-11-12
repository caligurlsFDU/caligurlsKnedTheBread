#include "orderGenerator.h"
#include <chrono>
#include <algorithm>


// Constructor: stores a reference to the ingredientBook in the member book.
orderGenerator::orderGenerator(const ingredientBook& book) : book(book)
{
	startNewGame();
}

// Starts a new game by initializing the random number generator
// clears the list of previously generated orders
void orderGenerator::startNewGame()
{
	rng.seed(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
	startNewShift();
}

// clears used orders since it is only required to avoid duplicates within a single shift, not across the entire game
void orderGenerator::startNewShift()
{
	usedSignatures.clear();
}

// Generates a random order using the ingredient categories and their limits/probabilities
// checks that the order has not already been used during the current shift
// Builds the riddle sentence using buildSentence()
order orderGenerator::generateOrder()
{
    std::vector<PickedItem> items;

    // Required ingredients: one bread, one meat, and one cheese.
	// Including probability for required ingredients in case probability needs to be changed in the future

	// 100% chance of adding one bread.
	if (randomBetween(1, 100) <= BREAD_CHANCE)
	{
		std::vector<PickedItem> bread = pickFromCategory(Category::Bread, 1);
		items.insert(items.end(), bread.begin(), bread.end());
	}

	// 100% chance of adding one meat.
	if (randomBetween(1, 100) <= MEAT_CHANCE)
	{
		std::vector<PickedItem> meat = pickFromCategory(Category::Meat, 1);
		items.insert(items.end(), meat.begin(), meat.end());
	}

	// 100% chance of adding one cheese.
	if (randomBetween(1, 100) <= CHEESE_CHANCE)
	{
		std::vector<PickedItem> cheese = pickFromCategory(Category::Cheese, 1);
		items.insert(items.end(), cheese.begin(), cheese.end());
	}

    // 50% chance of adding one vegetable.
    if (randomBetween(1, 100) <= VEGGIE_CHANCE)
    {
        std::vector<PickedItem> veggie = pickFromCategory(Category::Veggie, 1);
        items.insert(items.end(), veggie.begin(), veggie.end());
    }

    // 20% chance of adding one condiment.
    if (randomBetween(1, 100) <= CONDIMENT_CHANCE)
    {
        std::vector<PickedItem> condiment = pickFromCategory(Category::Condiment, 1);
        items.insert(items.end(), condiment.begin(), condiment.end());
    }

    // Build the order and check whether it has already been used.
    order newOrder(buildSentence(items), items);
    std::string signature = newOrder.getSignature();

    if (usedSignatures.find(signature) != usedSignatures.end())
    {
        return generateOrder();
    }

    // Save the order so it cannot be repeated during this shift.
    usedSignatures.insert(signature);

    return newOrder;
}

// Returns a random integer between low and high
int orderGenerator::randomBetween(int low, int high)
{
	std::uniform_int_distribution<int> distribution(low, high);
	return distribution(rng);
}

// Selects a specified number of different ingredients from a category
// Randomly shuffles the available ingredients and takes the requested number
// assigns a random code word to each selected ingredient
std::vector<PickedItem> orderGenerator::pickFromCategory(Category category, int count)
{
	std::vector<const IngredientData*> list = book.getByCategory(category);
	std::shuffle(list.begin(), list.end(), rng);

	if (count > static_cast<int>(list.size()))
	{
		count = static_cast<int>(list.size());
	}

	std::vector<PickedItem> picked;
	for (int i = 0; i < count; i++)
	{
		int index = randomBetween(0, static_cast<int>(list[i]->codeWords.size()) - 1);
		picked.push_back({ list[i], list[i]->codeWords[index] });
	}
	return picked;
}

std::string orderGenerator::buildSentence(const std::vector<PickedItem>& items) const
{
	std::string sentence = "I would like a sandwich with ";
	for (size_t i = 0; i < items.size(); ++i)
	{
		sentence += items[i].codeWord;
		if (i < items.size() - 2)
		{
			sentence += ", ";
		}
		else if (i == items.size() - 2)
		{
			sentence += ", and ";
		}
	}
	sentence += ".";
	return sentence;
}