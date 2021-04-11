#pragma once
#include "Units/UnitSquad.h"
#include "GameObjects/Direction.h"
#include <memory>

class Position {
public:
    Position(Direction& direction_, bool isForward_);
    virtual std::unique_ptr<Position> next() const = 0;
    virtual std::unique_ptr<UnitSquad> extractUnitSquad() = 0;
    virtual bool containsUnitSquad() const = 0;
    virtual void setUnitSquad(std::unique_ptr<UnitSquad> unitSquad) = 0;
    virtual bool isFreeToSet() const = 0;
protected:
    Direction& direction;
    const bool isForward;
    int getShift() const;
};

