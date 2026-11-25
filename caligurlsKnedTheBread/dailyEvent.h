// dailyEvent
// Holds one event's name, announcement, and rule settings.
// Defaults = Normal Day; each event only overrides what it changes.
//
// Members:
//   name, announcement
//   customerMultiplier, payMultiplier   - Black Friday
//   sandwichesPerOrder                  - BOGO
//   minMeats                            - Meat Mountain
//   scrambleText                        - Drunk Day
//   allOrNothing                        - Health Inspector
//   doubleOneBill                       - Bazaar Bills
//
// Functions:
//   isNormalDay()      - true if no event is active
//   getAnnouncement()  - returns "NAME: rule" for the shift start

#ifndef DAILYEVENT_H
#define DAILYEVENT_H

#include <string>

class dailyEvent {
public:
    // ---- Text shown to the player ----
    std::string name = "NORMAL DAY";
    std::string announcement = "No surprises today.";

    // ---- Rule settings (these defaults ARE the Normal Day) ----
    int    customerMultiplier = 1;     // Black Friday sets this to 2
    double payMultiplier = 1.0;   // Black Friday sets this to 0.5
    int    sandwichesPerOrder = 1;     // BOGO sets this to 2
    int    minMeats = 0;     // Meat Mountain sets this to 3
    bool   scrambleText = false; // Drunk Day sets this to true
    bool   allOrNothing = false; // Health Inspector sets this to true
    bool   doubleOneBill = false; // Bazaar Bills sets this to true

    // Builds a Normal Day.
    dailyEvent() = default;

    // Builds a named event. The rule settings start at Normal Day values;
    // the caller then changes only the one(s) this event affects.
    dailyEvent(const std::string& eventName, const std::string& eventAnnouncement);

    // True when every rule setting is still at its Normal Day value.
    bool isNormalDay() const;

    // "NAME: rule", e.g. "HEALTH INSPECTOR: One wrong item = no credit!"
    std::string getAnnouncement() const;
};

#endif