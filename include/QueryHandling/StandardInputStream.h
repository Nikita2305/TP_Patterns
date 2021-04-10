class StandardInputStream;

#pragma once
#include "QueryHandling/BufferStream.h"

class StandardInputStream: public BufferStream {
    void update() override;
};