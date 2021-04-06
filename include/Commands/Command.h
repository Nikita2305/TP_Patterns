class Command;

#pragma once
#include <vector>
#include "Units/Unit.h"

class Command{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};
