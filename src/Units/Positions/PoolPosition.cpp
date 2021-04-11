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
    if (isForward && iterator == ...) { //TODO LeftPool.end() - 1
        return std::make_unique<RoadPosition>(direction, isForward, 0);
    }
    if (!isForward && iterator == ...) { //TODO RightPool.begin()
        return std::make_unique<RoadPosition>(direction, isForward, direction.size() - 1);
    }
    return std::make_unique<PoolPosition>(direction, isForward, iterator + getShift());
}

std::unique_ptr<UnitSquad> PoolPosition::extractUnitSquad() {
    if (...) { //TODO RightPool.Contains(iterator). Tip: https://stackoverflow.com/questions/6302706/check-whether-iterator-belongs-to-a-list
        //TODO return RightPool.extract(iterator)
    } else {
        //TODO return LeftPool.extract(iterator)
    }
}

bool PoolPosition::containsUnitSquad() const {
    return true;
}

void PoolPosition::setUnitSquad(std::unique_ptr<UnitSquad> unitSquad) {
    if (...) { //TODO RightPool.Contains(iterator). Tip: https://stackoverflow.com/questions/6302706/check-whether-iterator-belongs-to-a-list
        //TODO RightPool.set(uE, iterator)
    } else {
        //TODO LeftPool.set(uE, iterator)
    }
}

bool PoolPosition::isFreeToSet() const {
    return true;
}