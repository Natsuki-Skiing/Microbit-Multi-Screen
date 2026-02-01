#include <cstdint>
typedef struct __attribute__((packed)){
  uint8_t microbitID;
  uint8_t x;
  uint8_t y;
  uint8_t value;
} Packet;
