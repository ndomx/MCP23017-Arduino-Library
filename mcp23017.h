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

    void write_port(const uint8_t bank, const uint8_t port, bool state);
    bool read_port(const uint8_t bank, const uint8_t port);

    private:
    const uint8_t _address;

    uint8_t _bank_a;
    uint8_t _bank_b;

    void write_reg(const uint8_t reg, uint8_t value);
    uint8_t read_reg(const uint8_t reg);
};

#endif // MCP23017_LIB_H_