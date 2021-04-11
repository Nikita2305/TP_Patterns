#pragma once
#include "Units/Positions/Position.h"
#include <list>

class PoolPosition: public Position {
public:
    PoolPosition(Direction& direction_, bool isForward_, const std::list<std::unique_ptr<UnitSquad>>::iterator& iterator_);
    std::unique_ptr<Position> next() const override;
    std::unique_ptr<UnitSquad> extractUnitSquad() override;
    bool containsUnitSquad() const override;
    void setUnitSquad(std::unique_ptr<UnitSquad> unitSquad) override;
    bool isFreeToSet() const override;

private:
    std::list<std::unique_ptr<UnitSquad>>::iterator iterator;
};