#include "MicroBit.h"
#include "packetStruct.h"
#include <unordered_map>
#include <string>
#include <cstdint>
#include "packetStruct.h"

struct SlaveScreen {
    uint8_t pixels[5][5];
};
class master{
    private:
        std::unordered_map<uint8_t,SlaveScreen> slaveStates;
};