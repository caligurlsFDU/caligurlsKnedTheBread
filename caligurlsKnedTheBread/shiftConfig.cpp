#include "shiftConfig.h"

///Returns the total number of playable shifts.
int shiftConfig::getTotalShifts()
{
	return 3;
}

/** Returns how many customers are in the given shift.
   Shift 1 has 3, shift 2 has 4, and shift 3 has 5.
   Returns 0 if the shift number is not valid. */
int shiftConfig::getCustomerCount(int shift)
{
	switch (shift)
	{
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 5;
	default:
		return 0;
	}
}

/// Returns true if the shift number can be played (1 to the total number of shifts).
bool shiftConfig::isValidShift(int shift)
{
	return shift >= 1 && shift <= getTotalShifts();
}