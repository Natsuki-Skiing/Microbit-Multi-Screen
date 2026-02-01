#include "MicroBit.h"
#include <vector>
#include <string>
#include <cstdint>
#include "MicroMultiSlave.h"

MicroBit uBit;

slave::slave(uint8_t id,uint16_t drawDelayMs){
    this->id = id;
    
    this->drawDelayMs = drawDelayMs;
    this->buffer = PacketBuffer(sizeof(Packet)*5);



    uBit.init();
    uBit.radio.enable();
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, this, &slave::onData);
    
}

void slave::onData(MicroBitEvent e){
    PacketBuffer receivedBuffer = uBit.radio.datagram.recv();
    if (receivedBuffer.length() == sizeof(Packet)) {
        
        Packet* p = (Packet *)receivedBuffer.getBytes();
        if (p->microbitID != this->id) { 
           
            this->setValue(p->x, p->y, p->value);
            
        }
    }
}

void slave::setValue(uint8_t x ,uint8_t y ,uint8_t value){
    if((x <=4) && (y <=4) ){
        this->screenBuffer[x][y] = value;
    }
}


void slave::drawBuffer(){
    for(uint8_t x = 0; x <5; x++){
        for(uint8_t y = 0; y <5; y++){
            uBit.display.image.setPixelValue(x,y,this->screenBuffer[x][y]);
        }
    }
}

void slave::displayeTask(){
    while(true){
        this->drawBuffer();
        uBit.sleep(this->drawDelayMs);
    }
}


