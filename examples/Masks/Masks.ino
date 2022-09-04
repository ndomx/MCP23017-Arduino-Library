/** Masks.ino
 * Shows how to config the MCP23017 port expander
 * using banks instead of the common pinMode, digitalWrite
 * and digitalRead functions. This allows to configure and
 * read/write multiple ports with a single instruction
 */

#include <mcp23017.h>

#define MCP_ADDR (0)

#define GP2 (1 << 2)
#define GP3 (1 << 3)
#define GP5 (1 << 5)
#define GP7 (1 << 7)

MCP23017 mcp(MCP_ADDR);

void setup(void)
{
    mcp.start();

    // Config ports GPA7 & GPA5 in the same instruction
    mcp.config_bank(BANK_A, OUTPUT, GP7 | GP5);

    // Config port GPA3 & GPA2 as INPUT_PULLUP
    mcp.config_bank(BANK_A, INPUT_PULLUP, GP3 | GP2);

    // Config BANK B as OUTPUT
    mcp.config_bank(BANK_B, OUTPUT);
}

void loop(void)
{
    // Toggle GPA7
    mcp.toggle_bank(BANK_A, GP7);

    // Set GPA5 to GPA3 & GPA2
    byte bank_a = mcp.read_bank(BANK_A, GP3 | GP2);
    byte gpa5 = (bank_a & GP3) && (bank_a & GP2);
    mcp.write_bank(BANK_A, gpa5, GP5);

    // Toggle BANK B
    mcp.toggle_bank(BANK_B);

    delay(100);
}
