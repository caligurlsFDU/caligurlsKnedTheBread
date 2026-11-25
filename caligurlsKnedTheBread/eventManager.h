// eventManager
// Picks and stores the event for the current shift.
//
// Members:
//   specialEvents  - list of the 6 events
//   currentEvent   - the event for this shift only
//
// Functions:
//   rollEvent(shiftNumber) - shift 1 = Normal Day; after that,
//                            25% Normal Day, 75% random event
//   getCurrentEvent()      - returns the active event
//   announceEvent()        - prints the event before the first customer
//   forceEvent(index)      - TESTING ONLY: pick a specific event on purpose

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <random>
#include <vector>
#include "dailyEvent.h"

class eventManager {
public:
    eventManager();

    void rollEvent(int shiftNumber);
    const dailyEvent& getCurrentEvent() const;
    void announceEvent() const;

    // Testing helper: 0 = Normal Day, 1-6 = the special events in list order.
    void forceEvent(int index);

private:
    std::vector<dailyEvent> specialEvents;
    dailyEvent currentEvent;   // starts as a Normal Day
    std::mt19937 rng;          // random number generator

    void buildEventList();     // fills specialEvents with the 6 events
};

#endif