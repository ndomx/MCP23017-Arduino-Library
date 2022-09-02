#ifndef MCP23017_LIB_H_
#define MCP23017_LIB_H_

#include "Arduino.h"
#include "Wire.h"

#define IOCON (0x0A)

#define IODIRA (0x00)
#define IPOLA (0x02)
#define GPINTENA (0x04)
#define DEFVALA (0x06)
#define INTCONA (0x08)
#define GPPUA (0x0C)
#define INTFA (0x0E)
#define INTCAPA (0x10)
#define GPIOA (0x12)
#define OLATA (0x14)

#define IODIRB (0x01)
#define IPOLB (0x03)
#define GPINTENB (0x05)
#define DEFVALB (0x07)
#define INTCONB (0x09)
#define GPPUB (0x0D)
#define INTFB (0x0F)
#define INTCAPB (0x11)
#define GPIOB (0x13)
#define OLATB (0x15)

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
};

#endif // MCP23017_LIB_H_