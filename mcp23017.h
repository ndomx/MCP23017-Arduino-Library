#ifndef MCP23017_LIB_H_
#define MCP23017_LIB_H_

#include "Arduino.h"
#include "Wire.h"

#include "gpio_bank.h"

class MCP23017
{
    public:
    MCP23017(const uint8_t address);
    ~MCP23017();

    void config_bank(const uint8_t bank_id, const uint8_t mode, const uint8_t mask);
    void config_bank(const uint8_t bank_id, const uint8_t mode);

    void config_banks(const uint8_t mode, const uint8_t mask);
    void config_banks(const uint8_t mode);

    void write_bank(const uint8_t bank_id, const uint8_t level, const uint8_t mask);
    void write_bank(const uint8_t bank_id, const uint8_t level);

    uint8_t read_bank(const uint8_t bank_id, const uint8_t mask);
    uint8_t read_bank(const uint8_t bank_id);

    private:
    const uint8_t _address;

    GPIO_Bank _bank_a;
    GPIO_Bank _bank_b;

    void write_reg(const uint8_t reg, uint8_t value);
    uint8_t read_reg(const uint8_t reg);
};

#endif // MCP23017_LIB_H_