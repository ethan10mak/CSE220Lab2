#include "compulsory_miss.h"
#include <iostream>

#include <unordered_set>
#include <cstdint>

static std::unordered_set<Addr> accessedLines;

uint64_t getCacheLineAddress(Addr address) {
    return address >> 6;
}

void initialize_cache_tracker() {
    accessedLines.clear();
}

int access_address(Addr address) {
    uint64_t lineAddress = getCacheLineAddress(address);

    if (accessedLines.find(lineAddress) == accessedLines.end()) {
        accessedLines.insert(lineAddress);
        return false;
    }
    else
    {
        return true;
    }
}
