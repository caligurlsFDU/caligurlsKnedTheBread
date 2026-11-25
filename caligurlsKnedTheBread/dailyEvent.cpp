#include "dailyEvent.h"

dailyEvent::dailyEvent(const std::string& eventName, const std::string& eventAnnouncement)
    : name(eventName), announcement(eventAnnouncement) {
    // Every rule setting keeps its default (Normal Day) value from the header.
}

bool dailyEvent::isNormalDay() const {
    return customerMultiplier == 1
        && payMultiplier == 1.0
        && sandwichesPerOrder == 1
        && minMeats == 0
        && !scrambleText
        && !allOrNothing
        && !doubleOneBill;
}

std::string dailyEvent::getAnnouncement() const {
    return name + ": " + announcement;
}