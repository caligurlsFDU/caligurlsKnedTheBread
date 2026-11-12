#pragma once

/// @class orderGenerator
/// @brief Builds random orders using the riddle guide's sentence template and order size limits
/// Stateful class, one instance created when the program starts


/// Members:
/// -const ingredientBook& book - reference to the ingredientBook
/// -std::mt19937 rng - random number engine, seeded once per new game
/// -std::set<std::string> usedSignatures - orders already given this shift
/// -MEAT_MAX 3, CHEESE_MAX 2, VEGGIE_MAX 2, CONDIMENT_MAX 1 - order size limits (all minimums are 0)

/// Methods:
/// -orderGenerator(const ingredientBook& book) - stores the reference
/// -void startNewGame() - seeds rng from the clock, then calls startNewShift()
/// -void startNewShift() - clears usedSignatures
/// -order generateOrder() - builds one random order not yet given this shift
/// -std::vector<PickedItem> pickFromCategory(Category category, int count) - picks count different ingredients
/// -std::string buildSentence(const std::vector<PickedItem>& items) const - turns picks into the order sentence
/// -int randomBetween(int low, int high) - random int, both ends included



#include <random>
#include <set>
#include <string>
#include <vector>
#include "ingredientBook.h"
#include "order.h"
#include "category.h"
#include "ingredientData.h"


class orderGenerator {
public:
    explicit orderGenerator(const ingredientBook& book);

    void startNewGame();
    void startNewShift();
    order generateOrder();

private:
    std::vector<PickedItem> pickFromCategory(Category category, int count);
    std::string buildSentence(const std::vector<PickedItem>& items) const;
    int randomBetween(int low, int high);

    static constexpr int MEAT_MAX = 3;
    static constexpr int CHEESE_MAX = 2;
    static constexpr int VEGGIE_MAX = 2;
    static constexpr int CONDIMENT_MAX = 1;

    static constexpr int BREAD_CHANCE = 100;
    static constexpr int MEAT_CHANCE = 100;
    static constexpr int CHEESE_CHANCE = 100;
    static constexpr int VEGGIE_CHANCE = 50;
    static constexpr int CONDIMENT_CHANCE = 20;

    const ingredientBook& book;
    std::mt19937 rng;
    std::set<std::string> usedSignatures;
};