#include "shiftState.h"

shiftState::shiftState() 
{
    isFirstShift = true;
}

bool shiftState::getIsFirstShift() const
{
    return isFirstShift;
}

void shiftState::endFirstShift() 
{
    isFirstShift = false;
}
