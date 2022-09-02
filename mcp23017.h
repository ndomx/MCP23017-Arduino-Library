#ifndef MCP23017_LIB_H_
#define MCP23017_LIB_H_

#include "Arduino.h"
#include "Wire.h"

#define BANK_A (0)
#define BANK_B (1)

class MCP23017
{
    public:
    MCP23017(const uint8_t address);
    ~MCP23017();

    void config_bank(const uint8_t bank, const uint8_t mode);
    void config_banks(const uint8_t mode);

    private:
    const uint8_t _address;

    void write_reg(const uint8_t reg, uint8_t value);
    uint8_t read_reg(const uint8_t reg);
};

#endif // MCP23017_LIB_H_