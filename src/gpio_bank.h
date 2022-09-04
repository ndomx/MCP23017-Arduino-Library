#ifndef MCP23017_GPIO_BANK_H_
#define MCP23017_GPIO_BANK_H_

#include <Arduino.h>

struct GPIO_Bank
{
    public:
    GPIO_Bank(const uint8_t id) : reg_mask(id)
    {
        ports = 0;
        ddr = 0;
        pull_ups = 0;
    }

    const uint8_t reg_mask;
    uint8_t ports;
    uint8_t ddr;
    uint8_t pull_ups;
};

#endif // MCP23017_GPIO_BANK_H_