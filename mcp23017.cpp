#include "mcp23017.h"
#include "mcp23017_constants.h"

MCP23017::MCP23017(const uint8_t address) : _address(address | 0x20), _bank_a(BANK_A), _bank_b(BANK_B)
{
    Wire.begin();
    write_reg(IOCON, (1 << _SEQOP));
}

MCP23017::~MCP23017(void)
{
    Wire.end();
}

void MCP23017::config_bank(const uint8_t bank_id, const uint8_t mode, const uint8_t mask)
{
    auto& bank = pick_bank(bank_id);
    switch (mode)
    {
        case OUTPUT: config_output(bank, mask); break;
        case INPUT: config_input_hiz(bank, mask); break;
        case INPUT_PULLUP: config_input_pullup(bank, mask); break;
    }
}

void MCP23017::config_bank(const uint8_t bank_id, const uint8_t mode)
{
    config_bank(bank_id, mode, 0xFF);
}

void MCP23017::config_banks(const uint8_t mode, const uint8_t mask)
{
    config_bank(BANK_A, mode, mask);
    config_bank(BANK_B, mode, mask);
}

void MCP23017::config_banks(const uint8_t mode)
{
    config_banks(mode, 0xFF);
}

void MCP23017::write_bank(const uint8_t bank_id, const uint8_t level, const uint8_t mask)
{
    auto& bank = pick_bank(bank_id);

    if (level)
    {
        bank.ports |= mask;
    }
    else
    {
        bank.ports &= ~mask;
    }

    write_reg(GPIO | bank.reg_mask, bank.ports);
}

void MCP23017::write_bank(const uint8_t bank_id, const uint8_t level)
{
    write_bank(bank_id, level, 0xFF);
}

uint8_t MCP23017::read_bank(const uint8_t bank_id, const uint8_t mask)
{
    auto& bank = pick_bank(bank_id);
    uint8_t ports = read_reg(GPIO | bank.reg_mask);

    return ports & mask;
}

uint8_t MCP23017::read_bank(const uint8_t bank_id, const uint8_t mask)
{
    return read_bank(bank_id, 0xFF);
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

void MCP23017::config_output(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr &= ~mask;
    write_reg(IODIR | bank.reg_mask, bank.ddr);
}

void MCP23017::config_input_hiz(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr |= mask;
    bank.pull_ups &= ~mask;
    
    write_reg(GPPU | bank.reg_mask, bank.pull_ups);
    write_reg(IODIR | bank.reg_mask, bank.ddr);
}

void MCP23017::config_input_pullup(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr |= mask;
    bank.pull_ups |= mask;
    
    write_reg(GPPU | bank.reg_mask, bank.pull_ups);
    write_reg(IODIR | bank.reg_mask, bank.ddr);
}
