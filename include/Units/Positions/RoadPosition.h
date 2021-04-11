#pragma once
#include "Units/Positions/Position.h"

class RoadPosition: public Position {
public:
    RoadPosition(Direction& direction_, bool isForward_, int index_);
    std::unique_ptr<Position> next() const override;
    std::unique_ptr<UnitSquad> extractUnitSquad() override;
    bool containsUnitSquad() const override;
    void setUnitSquad(std::unique_ptr<UnitSquad> unitSquad) override;
    bool isFreeToSet() const override;

private:
    int index;
};