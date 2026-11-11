#pragma once
/// @class order
/// @brief One customer order: the sentence shown to the player plus its hidden answer
/// Created by orderGenerator; one per customer


/// Members:
/// -std::string displayText - the sentence shown to the player (code words only)
/// -std::vector<PickedItem> items - the chosen ingredients (the answer key)
/// Methods:
/// -std::string getDisplayText() const - returns displayText
/// -std::string getSignature() const - sorted real names joined, used to detect repeats
/// /// -const std::vector<PickedItem>& getItems() const - returns items (the answer key)

#include <string>
#include <vector>
#include "ingredientData.h"


class order {
public:
    order(std::string displayText, std::vector<PickedItem> items);

    std::string getDisplayText() const;
    std::string getSignature() const;
    const std::vector<PickedItem>& getItems() const;

private:
    std::string displayText;
    std::vector<PickedItem> items;
};
