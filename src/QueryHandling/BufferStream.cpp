#include "QueryHandling/BufferStream.h"

bool BufferStream::hasData() const {
    return (!queue.empty());
}

std::string BufferStream::extractString() {
    std::string ret = queue.front();
    queue.pop();
    return ret;
}

void BufferStream::appendString(const std::string& s) {
    queue.push(s);
}

void BufferStream::update() {}