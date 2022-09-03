#include "mcp23017.h"

void MCP23017::start(void)
{
    Wire.begin();
    write_reg(MCP23017_IOCON, (1 << IOCON_SEQOP));
}

void MCP23017::close(void)
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

    write_reg(MCP23017_GPIO | bank.reg_mask, bank.ports);
}

void MCP23017::write_bank(const uint8_t bank_id, const uint8_t level)
{
    write_bank(bank_id, level, 0xFF);
}

void MCP23017::toggle_bank(const uint8_t bank_id, const uint8_t mask)
{
    auto& bank = pick_bank(bank_id);
    bank.ports ^= mask;

    write_reg(MCP23017_GPIO | bank.reg_mask, bank.ports);
}

void MCP23017::toggle_bank(const uint8_t bank_id)
{
    toggle_bank(bank_id, 0xFF);
}

uint8_t MCP23017::read_bank(const uint8_t bank_id, const uint8_t mask)
{
    auto& bank = pick_bank(bank_id);
    uint8_t ports = read_reg(MCP23017_GPIO | bank.reg_mask);

    return ports & mask;
}

uint8_t MCP23017::read_bank(const uint8_t bank_id)
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

    Wire.requestFrom((uint8_t)_address, (uint8_t)1, (uint8_t)true);

    while (Wire.available() == 0);

    return Wire.read();
}

void MCP23017::config_output(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr &= ~mask;
    write_reg(MCP23017_IODIR | bank.reg_mask, bank.ddr);
}

void MCP23017::config_input_hiz(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr |= mask;
    bank.pull_ups &= ~mask;
    
    write_reg(MCP23017_GPPU | bank.reg_mask, bank.pull_ups);
    write_reg(MCP23017_IODIR | bank.reg_mask, bank.ddr);
}

void MCP23017::config_input_pullup(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr |= mask;
    bank.pull_ups |= mask;
    
    write_reg(MCP23017_GPPU | bank.reg_mask, bank.pull_ups);
    write_reg(MCP23017_IODIR | bank.reg_mask, bank.ddr);
}
