#include "Units/Positions/PoolPosition.h"
#include "Units/Positions/RoadPosition.h"

RoadPosition::RoadPosition(Direction& direction_, bool isForward_, int index_): Position(direction_, isForward_), index(index_) {}

std::unique_ptr<Position> RoadPosition::next() const {
    if (isForward && index + 1 == direction.size()) {
        return std::make_unique<PoolPosition>(direction, isForward, direction.getRightPool().begin());
    }
    if (!isForward && index == 0) {
        return std::make_unique<PoolPosition>(direction, isForward, --direction.getLeftPool().end());
    }
    return std::make_unique<RoadPosition>(direction, isForward, index + getShift());
}

std::unique_ptr<UnitSquad> RoadPosition::extractUnitSquad() {
    return direction.extract(index);
}

bool RoadPosition::containsUnitSquad() const {
    return !direction.isEmpty(index);
}

void RoadPosition::setUnitSquad(std::unique_ptr<UnitSquad> unitSquad) {
    direction.set(std::move(unitSquad), index);
}

bool RoadPosition::isFreeToSet() const {
    return direction.isEmpty(index);
}
