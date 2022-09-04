# MCP23017-Arduino-Library

![release badge](https://img.shields.io/github/v/release/ndomx/MCP23017-Arduino-Library)
![license badge](https://img.shields.io/github/license/ndomx/MCP23017-Arduino-Library?style=flat-square)


This is a library to control MCP23017 I2C modules (product page [here](https://www.microchip.com/en-us/product/mcp23017)). The library provides full control of the module using familiar functions like `digitalWrite`, `digitalRead` and `pinMode`, as well as other functionalities.

> Note: The library does not support interrupts yet

## Usage
Begin by including the library files and declaring an instance of the `MCP23017` class.
~~~c++
#include <mcp23017.h>

#define MCP23017_ADDR (0x07) // I2C address of the module
MCP23017 mcp(MCP23017_ADDR);
~~~

Every instance of the `MCP23017` class must be initialized after created. This will setup the module so it's compatible with the library, and initializes the `Wire` library if needed. To do this, just call the `start()` function inside `setup()` or `loop()`

After the instance is initialized, Arduino functions can be used to configure the additional I/O ports. These ports will be labeled `GPAn` for ports in the _A_ bank, and `GPBn` for ports in the _B_ bank (`0 <= n < 8`). Below you'll find a basic example, and there are more examples in the [examples folder](https://github.com/ndomx/MCP23017-Arduino-Library/tree/master/examples).
~~~c++
// Blink a LED

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
~~~