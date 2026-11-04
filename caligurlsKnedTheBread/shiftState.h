#pragma once

/// @class shiftState 
/// @brief Tracks whether the player is still in Shift 1 (the tutorial shift with the guide) 
/// Stateful class, one instance created when the program starts 
/// -bool isFirstShift - set to true when the program starts 
/// -bool getIsFirstShift() - returns isFirstShift
/// -void endFirstShift() - sets isFirstShift to false; called once at the end of Shift 1

class shiftState
{
private:
	bool isFirstShift;

public:
	shiftState();
	bool getIsFirstShift() const;
	void endFirstShift();
};

