#include "Units/Positions/PoolPosition.h"
#include "Units/Positions/RoadPosition.h"

RoadPosition::RoadPosition(Direction& direction_, bool isForward_, int index_): Position(direction_, isForward_), index(index_) {}

std::unique_ptr<Position> RoadPosition::next() const {
    if (isForward && index + 1 == direction.size()) {
        return std::make_unique<PoolPosition>(direction, isForward, ...); //TODO RightPool.begin()
    }
    if (!isForward && index == 0) {
        return std::make_unique<PoolPosition>(direction, isForward, ...); //TODO LeftPool.end() - 1
    }
    return std::make_unique<RoadPosition>(direction, isForward, index + getShift());
}

std::unique_ptr<UnitSquad> RoadPosition::extractUnitSquad() {
    // TODO: return direction.extract(index);
}

bool RoadPosition::containsUnitSquad() const {
    //TODO: return direction.isAnyone(index)
}

void RoadPosition::setUnitSquad(std::unique_ptr<UnitSquad> unitSquad) {
    // TODO: direction.set(uE, index)
}

bool RoadPosition::isFreeToSet() const {
    //TODO: return !direction.isAnyone(index)
}
