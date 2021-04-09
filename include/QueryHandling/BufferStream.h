class BufferStream;

#pragma once
#include "IStream.h"
#include <string>
#include <queue>

class BufferStream: public IStream {
public:
    bool hasData() const override;
    std::string extractString() override;
    void appendString(const std::string&) override;
    void update() override;
protected:
    std::string buffer = "";
    std::queue<std::string> queue;
};