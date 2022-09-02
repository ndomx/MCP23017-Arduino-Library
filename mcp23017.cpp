#include "mcp23017.h"
#include "mcp23017_constants.h"

MCP23017::MCP23017(const uint8_t address) : _address(address)
{
    Wire.begin();

    // Disable sequential reading
    write_reg(IOCON, (1 << _SEQOP));
}

MCP23017::~MCP23017(void)
{
    Wire.end();
}

void MCP23017::write_reg(const uint8_t reg, uint8_t value)
{
    Wire.beginTransmission(_address);

    Wire.write(reg);
    Wire.write(value);

    Wire.endTransmission(true);
}

uint8_t MCP23017::read_reg(const uint8_t reg)
{
    Wire.beginTransmission(_address);
    Wire.write(reg);

    // Send restart
    Wire.endTransmission(false);

    Wire.requestFrom(_address, 1, true);

    while (Wire.available() == 0);

    return Wire.read();
}