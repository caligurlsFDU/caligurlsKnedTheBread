#include "orderGenerator.h" 

#include <random>     
#include <chrono>
#include <set>
#include <string>
#include <vector>     
#include <algorithm> 

///@brief Builds random orders using the riddle guide's sentence template and order size limits
/// Stateful class, one instance created when the program starts


/// Members:
const IngredientBook& book //reference to the IngredientBook
std::mt19937 rng  //random number engine, seeded once per new game
std::setstd::string //usedSignatures - orders already given this shift
-MEAT_MAX 3, CHEESE_MAX 2, VEGGIE_MAX 2, CONDIMENT_MAX 1 - order size limits (all minimums are 0)

/// Methods:
OrderGenerator::OrderGenerator(const IngredientBook& book)
    : book(book)
{
    startNewGame(); 
}

/// -void startNewGame() - seeds rng from the clock, then calls startNewShift()
/// -void startNewShift() - clears usedSignatures
/// -Order generateOrder() - builds one random order not yet given this shift
/// -std::vector<PickedItem> pickFromCategory(Category category, int count) - picks count different ingredients
/// -std::string buildSentence(const std::vector<PickedItem>& items) const - turns picks into the order sentence
/// -int randomBetween(int low, int high) - random int, both ends included