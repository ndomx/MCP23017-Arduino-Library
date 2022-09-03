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
// IODIR
#define MCP23017_IODIR0 (0) // IODIR bit 0
#define MCP23017_IODIR1 (1) // IODIR bit 1
#define MCP23017_IODIR2 (2) // IODIR bit 2
#define MCP23017_IODIR3 (3) // IODIR bit 3
#define MCP23017_IODIR4 (4) // IODIR bit 4
#define MCP23017_IODIR5 (5) // IODIR bit 5
#define MCP23017_IODIR6 (6) // IODIR bit 6
#define MCP23017_IODIR7 (7) // IODIR bit 7

// IPOL
#define MCP23017_IPOL0 (0) // IPOL bit 0
#define MCP23017_IPOL1 (1) // IPOL bit 1
#define MCP23017_IPOL2 (2) // IPOL bit 2
#define MCP23017_IPOL3 (3) // IPOL bit 3
#define MCP23017_IPOL4 (4) // IPOL bit 4
#define MCP23017_IPOL5 (5) // IPOL bit 5
#define MCP23017_IPOL6 (6) // IPOL bit 6
#define MCP23017_IPOL7 (7) // IPOL bit 7

// GPINTEN
#define MCP23017_GPINT0 (0) // GPINTEN bit 0
#define MCP23017_GPINT1 (1) // GPINTEN bit 1
#define MCP23017_GPINT2 (2) // GPINTEN bit 2
#define MCP23017_GPINT3 (3) // GPINTEN bit 3
#define MCP23017_GPINT4 (4) // GPINTEN bit 4
#define MCP23017_GPINT5 (5) // GPINTEN bit 5
#define MCP23017_GPINT6 (6) // GPINTEN bit 6
#define MCP23017_GPINT7 (7) // GPINTEN bit 7

// DEFVAL
#define MCP23017_DEFVAL0 (0) // DEFVAL bit 0
#define MCP23017_DEFVAL1 (1) // DEFVAL bit 1
#define MCP23017_DEFVAL2 (2) // DEFVAL bit 2
#define MCP23017_DEFVAL3 (3) // DEFVAL bit 3
#define MCP23017_DEFVAL4 (4) // DEFVAL bit 4
#define MCP23017_DEFVAL5 (5) // DEFVAL bit 5
#define MCP23017_DEFVAL6 (6) // DEFVAL bit 6
#define MCP23017_DEFVAL7 (7) // DEFVAL bit 7

// INTCON
#define MCP23017_IOC0 (0) // INTCON bit 0
#define MCP23017_IOC1 (1) // INTCON bit 1
#define MCP23017_IOC2 (2) // INTCON bit 2
#define MCP23017_IOC3 (3) // INTCON bit 3
#define MCP23017_IOC4 (4) // INTCON bit 4
#define MCP23017_IOC5 (5) // INTCON bit 5
#define MCP23017_IOC6 (6) // INTCON bit 6
#define MCP23017_IOC7 (7) // INTCON bit 7

// IOCON
#define MCP23017_INTPOL (1) // IOCON bit 1
#define MCP23017_ODR (2) // IOCON bit 2
#define MCP23017_HAEN (3) // IOCON bit 3
#define MCP23017_DISSLW (4) // IOCON bit 4
#define MCP23017_SEQOP (5) // IOCON bit 5
#define MCP23017_MIRROR (6) // IOCON bit 6
#define MCP23017_BANK (7) // IOCON bit 7

// GPPU
#define MCP23017_GPPU0 (0) // GPPU bit 0
#define MCP23017_GPPU1 (1) // GPPU bit 1
#define MCP23017_GPPU2 (2) // GPPU bit 2
#define MCP23017_GPPU3 (3) // GPPU bit 3
#define MCP23017_GPPU4 (4) // GPPU bit 4
#define MCP23017_GPPU5 (5) // GPPU bit 5
#define MCP23017_GPPU6 (6) // GPPU bit 6
#define MCP23017_GPPU7 (7) // GPPU bit 7

// INTF
#define MCP23017_INTF0 (0) // INTF bit 0
#define MCP23017_INTF1 (1) // INTF bit 1
#define MCP23017_INTF2 (2) // INTF bit 2
#define MCP23017_INTF3 (3) // INTF bit 3
#define MCP23017_INTF4 (4) // INTF bit 4
#define MCP23017_INTF5 (5) // INTF bit 5
#define MCP23017_INTF6 (6) // INTF bit 6
#define MCP23017_INTF7 (7) // INTF bit 7

// INTCAP
#define MCP23017_INTCAP0 (0) // INTCAP bit 0
#define MCP23017_INTCAP1 (1) // INTCAP bit 1
#define MCP23017_INTCAP2 (2) // INTCAP bit 2
#define MCP23017_INTCAP3 (3) // INTCAP bit 3
#define MCP23017_INTCAP4 (4) // INTCAP bit 4
#define MCP23017_INTCAP5 (5) // INTCAP bit 5
#define MCP23017_INTCAP6 (6) // INTCAP bit 6
#define MCP23017_INTCAP7 (7) // INTCAP bit 7

// GPIO
#define MCP23017_GP0 (0) // GPIO bit 0
#define MCP23017_GP1 (1) // GPIO bit 1
#define MCP23017_GP2 (2) // GPIO bit 2
#define MCP23017_GP3 (3) // GPIO bit 3
#define MCP23017_GP4 (4) // GPIO bit 4
#define MCP23017_GP5 (5) // GPIO bit 5
#define MCP23017_GP6 (6) // GPIO bit 6
#define MCP23017_GP7 (7) // GPIO bit 7

// OLAT
#define MCP23017_OL0 (0) // OLAT bit 0
#define MCP23017_OL1 (1) // OLAT bit 1
#define MCP23017_OL2 (2) // OLAT bit 2
#define MCP23017_OL3 (3) // OLAT bit 3
#define MCP23017_OL4 (4) // OLAT bit 4
#define MCP23017_OL5 (5) // OLAT bit 5
#define MCP23017_OL6 (6) // OLAT bit 6
#define MCP23017_OL7 (7) // OLAT bit 7

#endif // MCP23017_CONSTANTS_H_