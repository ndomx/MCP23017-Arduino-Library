/** Outputs.ino
 * Sets port 7 on bank B to OUTPUT and toggles
 * its state every 250ms
 */

#include <mcp23017.h>

#define MCP_ADDR (0)

MCP23017 mcp(MCP_ADDR);

void setup(void)
{
    mcp.start();
    mcp.pinMode(GPB7, OUTPUT);
}

void loop(void)
{
    mcp.digitalWrite(GPB7, HIGH);
    delay(250);
    mcp.digitalWrite(GPB7, LOW);
    delay(250);
}
