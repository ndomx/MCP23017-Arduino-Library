#include "mcp23017.h"
#include "mcp23017_constants.h"

MCP23017::MCP23017(const uint8_t address) : _address(address | 0x20)
{
    Wire.begin();

    _bank_a = 0;
    _bank_b = 0;

    // Disable sequential reading
    write_reg(IOCON, (1 << _SEQOP));
}

MCP23017::~MCP23017(void)
{
    Wire.end();
}

void MCP23017::config_bank(const uint8_t bank, const uint8_t mode)
{
    const uint8_t reg = (bank == BANK_A) ? IODIRA : IODIRB;
    const uint8_t opmode = (mode == OUTPUT) ? 0 : 1;

    write_reg(reg, opmode);
}

void MCP23017::config_banks(const uint8_t mode)
{
    config_bank(BANK_A, mode);
    config_bank(BANK_B, mode);
}

void MCP23017::write_port(const uint8_t bank, const uint8_t port, bool state)
{
    uint8_t& _bank = (bank == BANK_A) ? _bank_a : _bank_b;

    if (state)
    {
        _bank |= (1 << port);
    }
    else
    {
        _bank &= ~(1 << port);
    }

    const uint8_t reg = (bank == BANK_A) ? GPIOA : GPIOB;
    write_reg(reg, _bank);
}

bool MCP23017::read_port(const uint8_t bank, const uint8_t port)
{
    uint8_t& _bank = (bank == BANK_A) ? _bank_a : _bank_b;
    const uint8_t reg = (bank == BANK_A) ? GPIOA : GPIOB;
    
    _bank = read_reg(reg);
    return (_bank >> port) & 0b1;
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