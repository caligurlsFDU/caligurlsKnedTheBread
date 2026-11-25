#include "eventManager.h"
#include <iostream>

eventManager::eventManager() : rng(std::random_device{}()) {
    buildEventList();
}

void eventManager::buildEventList() {
    // Each event starts as a Normal Day, then changes only its own rule(s).

    dailyEvent bogo("BOGO", "Every customer orders 2 sandwiches but only pays for 1!");
    bogo.sandwichesPerOrder = 2;
    specialEvents.push_back(bogo);

    dailyEvent meat("MEAT MOUNTAIN", "Competitive eaters want BEEFY sandwiches (3+ meats)!");
    meat.minMeats = 3;
    specialEvents.push_back(meat);

    dailyEvent drunk("DRUNK DAY", "It's the 4th of July... good luck reading these orders!");
    drunk.scrambleText = true;
    specialEvents.push_back(drunk);

    dailyEvent inspector("HEALTH INSPECTOR", "One wrong item = no credit for the whole sandwich!");
    inspector.allOrNothing = true;
    specialEvents.push_back(inspector);

    dailyEvent bills("BAZAAR BILLS", "Tariffs hit! One cost on tonight's bill is doubled.");
    bills.doubleOneBill = true;
    specialEvents.push_back(bills);

    dailyEvent friday("BLACK FRIDAY", "Twice the customers, half the pay. Keep up!");
    friday.customerMultiplier = 2;
    friday.payMultiplier = 0.5;
    specialEvents.push_back(friday);
}

void eventManager::rollEvent(int shiftNumber) {
    // Replacing currentEvent wipes out last shift's event = the reset.
    currentEvent = dailyEvent();   // Normal Day

    // Shift 1 is always a Normal Day so new players can learn.
    if (shiftNumber <= 1) {
        return;
    }

    // Roll 0-99. 0-24 (25 numbers) = Normal Day.
    std::uniform_int_distribution<int> percent(0, 99);
    if (percent(rng) < 25) {
        return;
    }

    // Otherwise pick one of the 6 events, each equally likely.
    std::uniform_int_distribution<int> pick(0, static_cast<int>(specialEvents.size()) - 1);
    currentEvent = specialEvents[pick(rng)];
}

const dailyEvent& eventManager::getCurrentEvent() const {
    return currentEvent;
}

void eventManager::announceEvent() const {
    std::cout << "\n==============================\n";
    std::cout << "  " << currentEvent.getAnnouncement() << "\n";
    std::cout << "==============================\n\n";
}

void eventManager::forceEvent(int index) {
    if (index <= 0 || index > static_cast<int>(specialEvents.size())) {
        currentEvent = dailyEvent();   // anything out of range = Normal Day
    }
    else {
        currentEvent = specialEvents[index - 1];
    }
}