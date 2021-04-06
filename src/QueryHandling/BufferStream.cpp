#include "QueryHandling/BufferStream.h"

bool BufferStream::hasQuery() const {
    return (!queue.empty());
}

std::string BufferStream::popFirst() {
    auto ret = queue.front();
    queue.pop();
    return ret;
}

void BufferStream::pushBack(const std::string& s) {
    queue.push(s);
}

void BufferStream::update() {}