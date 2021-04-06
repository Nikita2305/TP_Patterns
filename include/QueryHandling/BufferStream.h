class BufferStream;

#pragma once
#include "IStream.h"
#include <string>
#include <queue>

class BufferStream: public IStream {
public:
    bool hasQuery() const override;
    std::string popFirst() override;
    void pushBack(const std::string&) override;
    void update() override;
protected:
    std::string buffer = "";
    std::queue<std::string> queue;
};