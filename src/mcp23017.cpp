#include "mcp23017.h"

/** Public functions */

/**
 * Disconnects the board from the I2C bus
 * 
 * This function should be called after every instance of this class
 * is destroyed, and the user no longer wants to be connected to the
 * I2C bus.
 * 
 * @note This function is static
 */
void MCP23017::close(void)
{
    Wire.end();
}

/**
 * Run basic register setup
 * 
 * This function will connect the board to the I2C bus (if it wasn't
 * previously connected) and setup the IOCON register on the MCP23017
 * module to make it compatible with this library.
 * 
 * @note This must be called in every instance
 */
void MCP23017::start(void)
{
    Wire.begin();
    write_reg(MCP23017_IOCON, (1 << IOCON_SEQOP));
}

/**
 * Configures a bank with the specified I/O function
 * 
 * Configures a GPIO bank with the specified I/O function. The I/O function
 * is compatible with the Arduino syntax. The mask parameter allows the user
 * to configure only the pins that match the 1s in the mask. As an example,
 * the user wishes to only set the 7th port of the B bank as OUTPUT, they
 * should call config_bank(BANK_B, OUTPUT, (1 << 7))
 * 
 * @param bank_id Must be BANK_A or BANK_B
 * @param mode Must be OUTPUT, INPUT or INPUT_PULLUP
 * @param mask A mask representing which ports are to be configured
 */
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

/**
 * Configures a bank with the specified I/O function
 * 
 * Configures a GPIO bank with the specified I/O function. The I/O function
 * is compatible with the Arduino syntax.
 * 
 * @param bank_id Must be BANK_A or BANK_B
 * @param mode Must be OUTPUT, INPUT or INPUT_PULLUP
 */
void MCP23017::config_bank(const uint8_t bank_id, const uint8_t mode)
{
    config_bank(bank_id, mode, 0xFF);
}

/**
 * Configures all banks with the specified I/O function
 * 
 * Configures all GPIO banks with the specified I/O function. The I/O function
 * is compatible with the Arduino syntax. The mask parameter allows the user
 * to configure only the pins that match the 1s in the mask.
 * 
 * @see config_bank
 * @note mask bits from 0 to 7 will target bank A and bits from 8 to 15 will target bank B
 *
 * @param mode Must be OUTPUT, INPUT or INPUT_PULLUP
 * @param mask A mask representing which ports are to be configured
 */
void MCP23017::config_banks(const uint8_t mode, const uint16_t mask)
{
    config_bank(BANK_A, mode, (mask >> 0) & 0xFF);
    config_bank(BANK_B, mode, (mask >> 8) & 0xFF);
}

/**
 * Configures all banks with the specified I/O function
 * 
 * Configures all GPIO banks with the specified I/O function. The I/O function
 * is compatible with the Arduino syntax.
 *
 * @param mode Must be OUTPUT, INPUT or INPUT_PULLUP
 */
void MCP23017::config_banks(const uint8_t mode)
{
    config_banks(mode, 0xFFFF);
}

/**
 * Writes to the specified output bank
 * 
 * Writes the provided logic level to the specified bank. The mask parameter
 * allows the user to write only to certain ports instead of the whole bank.
 * If the nth bit of the mask is 1, then the nth port of the bank will be
 * written (the logic level depends on the level param).
 * 
 * @note This function will only write to ports configured as OUTPUT
 *
 * @param bank_id Must be BANK_A or BANK_B
 * @param level Must be HIGH or LOW
 * @param mask A mask representing which ports are to be written to
 */
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

/**
 * Writes to the specified output bank
 * 
 * Writes the provided logic level to the specified bank. This function
 * will write the logic value to every port on the bank.
 * 
 * @note This function will only write to ports configured as OUTPUT
 *
 * @param bank_id Must be BANK_A or BANK_B
 * @param level Must be HIGH or LOW
 */
void MCP23017::write_bank(const uint8_t bank_id, const uint8_t level)
{
    write_bank(bank_id, level, 0xFF);
}

/**
 * Toggles the outputs of a specified bank
 * 
 * Toggles the state of every output port in the specified bank. The mask
 * value allows the user to only update ports that match with the mask param.
 * If the nth bit of the mask is 1, then the nth port of the bank will be toggled.
 * 
 * @note This function will only write to ports configured as OUTPUT
 *
 * @param bank_id Must be BANK_A or BANK_B
 * @param mask A mask representing which ports are to be written to
 */
void MCP23017::toggle_bank(const uint8_t bank_id, const uint8_t mask)
{
    auto& bank = pick_bank(bank_id);
    bank.ports ^= mask;

    write_reg(MCP23017_GPIO | bank.reg_mask, bank.ports);
}

/**
 * Toggles the outputs of a specified bank
 * 
 * Toggles the state of every output port in the specified bank.
 * 
 * @note This function will only write to ports configured as OUTPUT
 *
 * @param bank_id Must be BANK_A or BANK_B
 */
void MCP23017::toggle_bank(const uint8_t bank_id)
{
    toggle_bank(bank_id, 0xFF);
}

/**
 * Reads the state of a bank
 * 
 * Reads the output port of the specified bank and returns its value.
 * The mask param allows the user to select which ports are of interest.
 * 
 * @note If the nth bit of the mask is 0, the nth bit of the output will be 0
 *
 * @param bank_id Must be BANK_A or BANK_B
 * @param mask A mask representing which ports to read
 * @return The state of every port in the bank
 */
uint8_t MCP23017::read_bank(const uint8_t bank_id, const uint8_t mask)
{
    auto& bank = pick_bank(bank_id);
    uint8_t ports = read_reg(MCP23017_GPIO | bank.reg_mask);

    return ports & mask;
}

/**
 * Reads the state of a bank
 * 
 * Reads the output port of the specified bank and returns its value.
 *
 * @param bank_id Must be BANK_A or BANK_B
 * @return The state of every port in the bank
 */
uint8_t MCP23017::read_bank(const uint8_t bank_id)
{
    return read_bank(bank_id, 0xFF);
}

/**
 * Configures a single port
 * 
 * This function works the same way as the native pinMode function. Supported 
 * gpio_id values range from 0 to 15. Values from 0 to 7 will address ports
 * in the A bank (GPA0 - GPA7) and values from 8 to 15 will address ports
 * in the B bank (GPB0 - GPB7).
 *
 * @param gpio_id Should be GPAn or GPBn (0 <= n < 8)
 * @param mode Must be OUTPUT, INPUT or INPUT_PULLUP
 */
void MCP23017::pinMode(const uint8_t gpio_id, const uint8_t mode)
{
    const uint8_t bank_id = (gpio_id < 0x8) ? BANK_A : BANK_B;
    const uint8_t mask = (1 << (gpio_id % 0x8));

    config_bank(bank_id, mode, mask);
}

/**
 * Writes to a single port
 * 
 * This function works the same way as the native digitalWrite function. 
 * Supported gpio_id values range from 0 to 15. Values from 0 to 7 will
 * address ports in the A bank (GPA0 - GPA7) and values from 8 to 15
 * will address ports in the B bank (GPB0 - GPB7).
 *
 * @param gpio_id Should be GPAn or GPBn (0 <= n < 8)
 * @param level Must be HIGH or LOW
 */
void MCP23017::digitalWrite(const uint8_t gpio_id, const uint8_t level)
{
    const uint8_t bank_id = (gpio_id < 0x8) ? BANK_A : BANK_B;
    const uint8_t mask = (1 << (gpio_id % 0x8));

    write_bank(bank_id, level, mask);
}

/**
 * Reads a single port
 * 
 * This function works the same way as the native digitalRead function. 
 * Supported gpio_id values range from 0 to 15. Values from 0 to 7 will
 * address ports in the A bank (GPA0 - GPA7) and values from 8 to 15
 * will address ports in the B bank (GPB0 - GPB7).
 * 
 * @note The specified port can be an OUTPUT
 *
 * @param gpio_id Should be GPAn or GPBn (0 <= n < 8)
 * @return Port's logic level
 */
uint8_t MCP23017::digitalRead(const uint8_t gpio_id)
{
    const uint8_t bank_id = (gpio_id < 0x8) ? BANK_A : BANK_B;
    const uint8_t mask = (1 << (gpio_id % 0x8));

    return read_bank(bank_id, mask);
}

/** Private functions */

/**
 * Writes to a MCP23017 register
 * 
 * Writes the specified value to a register. The reg param must be
 * a valid register address.
 * 
 * @see mcp23017.h for valid register names and addresses
 *
 * @param reg Register address
 * @param value Register's new value
 */
void MCP23017::write_reg(const uint8_t reg, uint8_t value)
{
    Wire.beginTransmission(_address);

    Wire.write(reg);
    Wire.write(value);

    Wire.endTransmission(true);
}

/**
 * Reads a MCP23017 register
 * 
 * Reads the specified register. The reg param must be
 * a valid register address.
 * 
 * @see mcp23017.h for valid register names and addresses
 *
 * @param reg Register address
 * @return Register's stored value
 */
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

/**
 * Configures a bank to be OUTPUT
 * 
 * Configures a GPIO bank with the OUTPUT function. This function will
 * write the appropriate registers to configure the bank as OUTPUT and
 * shouldn't be called directly. Instead use the config_bank function.
 * 
 * @see config_bank
 * 
 * @param bank Reference to a GPIO_Bank
 * @param mask A mask representing which ports are to be configured
 */
void MCP23017::config_output(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr &= ~mask;
    write_reg(MCP23017_IODIR | bank.reg_mask, bank.ddr);
}

/**
 * Configures a bank to be INPUT
 * 
 * Configures a GPIO bank with the INPUT function. This function will
 * write the appropriate registers to configure the bank as INPUT and
 * disable the pull-ups. This function shouldn't be called directly, 
 * instead use the config_bank function.
 * 
 * @see config_bank
 * 
 * @param bank Reference to a GPIO_Bank
 * @param mask A mask representing which ports are to be configured
 */
void MCP23017::config_input_hiz(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr |= mask;
    bank.pull_ups &= ~mask;
    
    write_reg(MCP23017_GPPU | bank.reg_mask, bank.pull_ups);
    write_reg(MCP23017_IODIR | bank.reg_mask, bank.ddr);
}

/**
 * Configures a bank to be INPUT_PULLUP
 * 
 * Configures a GPIO bank with the INPUT_PULLUP function. This function will
 * write the appropriate registers to configure the bank as INPUT_PULLUP and
 * enable the pull-ups. This function shouldn't be called directly, 
 * instead use the config_bank function.
 * 
 * @see config_bank
 * 
 * @param bank Reference to a GPIO_Bank
 * @param mask A mask representing which ports are to be configured
 */
void MCP23017::config_input_pullup(GPIO_Bank& bank, const uint8_t mask)
{
    bank.ddr |= mask;
    bank.pull_ups |= mask;
    
    write_reg(MCP23017_GPPU | bank.reg_mask, bank.pull_ups);
    write_reg(MCP23017_IODIR | bank.reg_mask, bank.ddr);
}
