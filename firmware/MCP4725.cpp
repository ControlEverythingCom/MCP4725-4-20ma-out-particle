#include "MCP4725.h"

void MCP4725::setAddress(int jumper){
    if(jumper){
        address = address + 1;
    }
}

bool MCP4725::setOutput(int16_t raw){    
    byte MSB = raw >> 4;
    
    byte LSB = (raw & 15) << 4;
    
    if (!Wire.isEnabled()) {
        Wire.begin();
    }
    Wire.beginTransmission(address);
    Wire.write(writeDACCommand);
    Wire.write(MSB);
    Wire.write(LSB);
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }
    return false;
}

bool MCP4725::setOutputMa(float ma){
    if(ma > 20 || ma < 4){
        return 0;
    }
    int16_t raw = ma/mAPerStep;
    setOutput(raw);
}