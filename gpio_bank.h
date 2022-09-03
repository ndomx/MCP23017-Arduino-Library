#ifndef MCP23017_GPIO_BANK_H_
#define MCP23017_GPIO_BANK_H_

#include "Arduino.h"
#include "Wire.h"

struct GPIO_Bank
{
    public:
    GPIO_Bank(const uint8_t id);

    void config(const uint8_t mode, const uint8_t mask);

    void write(const uint8_t mask);
    uint8_t read(const uint8_t mask);
    uint8_t read(void);

    private:
    const uint8_t _reg_mask;
    uint8_t _ports;
    uint8_t _ddr;
    uint8_t _pull_ups;

    void write_reg(const uint8_t reg, uint8_t value);
    uint8_t read_reg(const uint8_t reg);
};

#endif // MCP23017_GPIO_BANK_H_