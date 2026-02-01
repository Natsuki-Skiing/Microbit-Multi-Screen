#include "MicroBit.h"
#include "packetStruct.h"
#include <vector>
#include <string>
#include <cstdint>
class slave{
    private:
        uint8_t id;
        PacketBuffer buffer;
        uint16_t drawDelayMs;
        uint8_t screenBuffer[5][5] = {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
        };

        void setValue(uint8_t x, uint8_t y , uint8_t value);
        void onData(MicroBitEvent);
        void slave::displayeTask();
    public:
        void drawBuffer();
        void listenForUpdate();
        slave(uint8_t id,uint16_t drawDelayMs);
};