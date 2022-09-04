/** Inputs.ino
 * Sets port 7 on bank B to INPUT_PULLUP and copies its
 * state to the built-in LED on the board
 */

#include <mcp23017.h>

#define MCP_ADDR (0)

MCP23017 mcp(MCP_ADDR);

void setup(void)
{
    pinMode(LED_BUILTIN, OUTPUT);

    mcp.start();
    mcp.pinMode(GPB7, INPUT_PULLUP);
}

void loop(void)
{
    byte mcp_input = mcp.digitalRead(GPB7);
    digitalWrite(LED_BUILTIN, mcp_input);
}
