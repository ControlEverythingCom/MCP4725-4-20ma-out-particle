// This #include statement was automatically added by the Particle IDE.
#include "MCP4725.h"

MCP4725 mcp4725;

int setOutput(String data);
int setRaw(String data);

void setup() {
    //Particle function to set output in ma.  Pass a ma argument to this function like 4.00
    Particle.function("SetOutput", setOutput);
    //Particle function to set output to a raw 12 bit value(0-4095).
    Particle.function("SetRaw", setRaw);
    //Address jumper is not installed so pass 0 to setAddress function during setup.
    mcp4725.setAddress(0);

}

void loop() {

}

int setOutput(String data){
    if(mcp4725.setOutputMa(data.toFloat())){
        return 1;
    }
    return 0;
}
int setRaw(String data){
    if(mcp4725.setOutput(data.toInt())){
        return 1;
    }else{
        return 0;
    }
}