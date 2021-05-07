#include "Units/Positions/PoolPosition.h"
#include "Units/Positions/RoadPosition.h"

std::list<std::unique_ptr<UnitSquad>>::iterator operator+(std::list<std::unique_ptr<UnitSquad>>::iterator iter, int shift) {
    if (shift < 0) {
        for (int i = 0; i < -shift; i++) {
            --iter;
        }
    } else {
        for (int i = 0; i < shift; i++) {
            ++iter;
        }
    }
    return iter;
}

PoolPosition::PoolPosition(Direction& direction_, bool isForward_, const std::list<std::unique_ptr<UnitSquad>>::iterator& iterator_):
    Position(direction_, isForward_), iterator(iterator_) {}

std::unique_ptr<Position> PoolPosition::next() const {
    if (isForward && iterator == --direction.getLeftPool().end()) {
        return std::make_unique<RoadPosition>(direction, isForward, 0);
    }
    if (!isForward && iterator == direction.getRightPool().begin()) {
        return std::make_unique<RoadPosition>(direction, isForward, direction.size() - 1);
    }
    return std::make_unique<PoolPosition>(direction, isForward, iterator + getShift());
}

std::unique_ptr<UnitSquad> PoolPosition::extractUnitSquad() {
    if (direction.getRightPool().contains(iterator)) {
        return direction.getRightPool().extract(iterator);
    } else {
        return direction.getLeftPool().extract(iterator);
    }
}

bool PoolPosition::containsUnitSquad() const {
    return true;
}

void PoolPosition::setUnitSquad(std::unique_ptr<UnitSquad> unitSquad) {
    if (direction.getRightPool().contains(iterator)) { // TODO: case of begin == end // sosyot. Solution seems like bool isRight as a field of PoolPosition
        direction.getRightPool().set(std::move(unitSquad), iterator);
    } else {
        direction.getLeftPool().set(std::move(unitSquad), iterator);
    }
}

bool PoolPosition::isFreeToSet() const {
    return true;
}