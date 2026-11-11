#include "orderGenerator.h" 

#include <random>     
#include <chrono>
#include <set>
#include <string>
#include <vector>     
#include <algorithm> 

///@brief Builds random orders using the riddle guide's sentence template and order size limits
/// Stateful class, one instance created when the program starts


/// Methods:
orderGenerator::orderGenerator(const ingredientBook& book)
    : book(book)
{
    startNewGame();
}

void orderGenerator::startNewShift()
{
    usedSignatures.clear();
}

void orderGenerator::startNewGame()
{
    rng.seed(static_cast<unsigned>(
        std::chrono::steady_clock::now().time_since_epoch().count()));
    startNewShift();
}

int orderGenerator::randomBetween(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high);
    return dist(rng);
}

//seeds rng from the clock, then calls startNewShift()
/// -void startNewShift() - clears usedSignatures
/// -Order generateOrder() - builds one random order not yet given this shift
/// -std::vector<PickedItem> pickFromCategory(Category category, int count) - picks count different ingredients
/// -std::string buildSentence(const std::vector<PickedItem>& items) const - turns picks into the order sentence