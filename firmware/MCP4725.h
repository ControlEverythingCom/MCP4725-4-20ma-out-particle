#include "spark_wiring_i2c.h"
#include "spark_wiring.h"
#include "spark_wiring_constants.h"

class MCP4725{
public:
    void setAddress(int jumper);
    bool setOutput(int16_t raw);
    bool setOutputMa(float ma);
    
private:
    int address = 96;
    int writeDACCommand = 64;
    double lower = 657.00;
    double mAPerStep = 4.00/lower;
};