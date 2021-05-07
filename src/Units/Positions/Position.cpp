#include "Units/Positions/Position.h"

Position::Position(Direction& direction_, bool isForward_): direction(direction_), isForward(isForward_) {}

int Position::getShift() const {
    return (isForward ? 1 : -1);
}