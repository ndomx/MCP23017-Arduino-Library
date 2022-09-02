#ifndef MCP23017_LIB_H_
#define MCP23017_LIB_H_

#include "Arduino.h"
#include "Wire.h"

#define IOCON (0x05)

#define IODIRA (0x00)
#define IPOLA (0x01)
#define GPINTENA (0x02)
#define DEFVALA (0x03)
#define INTCONA (0x04)
#define GPPUA (0x06)
#define INTFA (0x07)
#define INTCAPA (0x08)
#define GPIOA (0x08)
#define OLATA (0x0A)

#define IODIRB (0x10)
#define IPOLB (0x11)
#define GPINTENB (0x12)
#define DEFVALB (0x13)
#define INTCONB (0x14)
#define GPPUB (0x16)
#define INTFB (0x17)
#define INTCAPB (0x18)
#define GPIOB (0x18)
#define OLATB (0x1A)

#endif // MCP23017_LIB_H_