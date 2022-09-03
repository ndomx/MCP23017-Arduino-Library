#ifndef MCP23017_CONSTANTS_H_
#define MCP23017_CONSTANTS_H_

/** Registers */
#define MCP23017_IOCON (0x0A) // I/O Expander Configuration Register

#define MCP23017_IODIR (0x00) // I/O Direction Register
#define MCP23017_IPOL (0x02) // Input Polarity Port Register
#define MCP23017_GPINTEN (0x04) // Interrupt-On-Change Pins
#define MCP23017_DEFVAL (0x06) // Default Value Register
#define MCP23017_INTCON (0x08) // Interrupt-On-Change Control Register
#define MCP23017_GPPU (0x0C) // GPIO Pull-Up Resistor Register
#define MCP23017_INTF (0x0E) // Interrupt Flag Register
#define MCP23017_INTCAP (0x10) // Interrupt Captured Value For Port Register
#define MCP23017_GPIO (0x12) // General Purpose I/O Port Register
#define MCP23017_OLAT (0x14) // Output Latch Register

/** Bit definitions */
// IOCON
#define IOCON_INTPOL (1) // IOCON bit 1
#define IOCON_ODR (2) // IOCON bit 2
#define IOCON_HAEN (3) // IOCON bit 3
#define IOCON_DISSLW (4) // IOCON bit 4
#define IOCON_SEQOP (5) // IOCON bit 5
#define IOCON_MIRROR (6) // IOCON bit 6
#define IOCON_BANK (7) // IOCON bit 7

// GPIO
#define GPA0 (0) // GPIO port 0, bank A
#define GPA1 (1) // GPIO port 1, bank A
#define GPA2 (2) // GPIO port 2, bank A
#define GPA3 (3) // GPIO port 3, bank A
#define GPA4 (4) // GPIO port 4, bank A
#define GPA5 (5) // GPIO port 5, bank A
#define GPA6 (6) // GPIO port 6, bank A
#define GPA7 (7) // GPIO port 7, bank A

#define GPB0 (0) // GPIO port 0, bank B
#define GPB1 (1) // GPIO port 1, bank B
#define GPB2 (2) // GPIO port 2, bank B
#define GPB3 (3) // GPIO port 3, bank B
#define GPB4 (4) // GPIO port 4, bank B
#define GPB5 (5) // GPIO port 5, bank B
#define GPB6 (6) // GPIO port 6, bank B
#define GPB7 (7) // GPIO port 7, bank B

#endif // MCP23017_CONSTANTS_H_