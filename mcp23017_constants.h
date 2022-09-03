#ifndef MCP23017_CONSTANTS_H_
#define MCP23017_CONSTANTS_H_

/** Registers */
#define IOCON (0x0A) // I/O Expander Configuration Register

#define IODIR (0x00) // I/O Direction Register
#define IPOL (0x02) // Input Polarity Port Register
#define GPINTEN (0x04) // Interrupt-On-Change Pins
#define DEFVAL (0x06) // Default Value Register
#define INTCON (0x08) // Interrupt-On-Change Control Register
#define GPPU (0x0C) // GPIO Pull-Up Resistor Register
#define INTF (0x0E) // Interrupt Flag Register
#define INTCAP (0x10) // Interrupt Captured Value For Port Register
#define GPIO (0x12) // General Purpose I/O Port Register
#define OLAT (0x14) // Output Latch Register

/** Bit definitions */
// IODIR
#define IODIR0 (0) // IODIR bit 0
#define IODIR1 (1) // IODIR bit 1
#define IODIR2 (2) // IODIR bit 2
#define IODIR3 (3) // IODIR bit 3
#define IODIR4 (4) // IODIR bit 4
#define IODIR5 (5) // IODIR bit 5
#define IODIR6 (6) // IODIR bit 6
#define IODIR7 (7) // IODIR bit 7

// IPOL
#define IPOL0 (0) // IPOL bit 0
#define IPOL1 (1) // IPOL bit 1
#define IPOL2 (2) // IPOL bit 2
#define IPOL3 (3) // IPOL bit 3
#define IPOL4 (4) // IPOL bit 4
#define IPOL5 (5) // IPOL bit 5
#define IPOL6 (6) // IPOL bit 6
#define IPOL7 (7) // IPOL bit 7

// GPINTEN
#define GPINT0 (0) // GPINTEN bit 0
#define GPINT1 (1) // GPINTEN bit 1
#define GPINT2 (2) // GPINTEN bit 2
#define GPINT3 (3) // GPINTEN bit 3
#define GPINT4 (4) // GPINTEN bit 4
#define GPINT5 (5) // GPINTEN bit 5
#define GPINT6 (6) // GPINTEN bit 6
#define GPINT7 (7) // GPINTEN bit 7

// DEFVAL
#define DEFVAL0 (0) // DEFVAL bit 0
#define DEFVAL1 (1) // DEFVAL bit 1
#define DEFVAL2 (2) // DEFVAL bit 2
#define DEFVAL3 (3) // DEFVAL bit 3
#define DEFVAL4 (4) // DEFVAL bit 4
#define DEFVAL5 (5) // DEFVAL bit 5
#define DEFVAL6 (6) // DEFVAL bit 6
#define DEFVAL7 (7) // DEFVAL bit 7

// INTCON
#define IOC0 (0) // INTCON bit 0
#define IOC1 (1) // INTCON bit 1
#define IOC2 (2) // INTCON bit 2
#define IOC3 (3) // INTCON bit 3
#define IOC4 (4) // INTCON bit 4
#define IOC5 (5) // INTCON bit 5
#define IOC6 (6) // INTCON bit 6
#define IOC7 (7) // INTCON bit 7

// IOCON
#define _INTPOL (1) // IOCON bit 1
#define _ODR (2) // IOCON bit 2
#define _HAEN (3) // IOCON bit 3
#define _DISSLW (4) // IOCON bit 4
#define _SEQOP (5) // IOCON bit 5
#define _MIRROR (6) // IOCON bit 6
#define _BANK (7) // IOCON bit 7

// GPPU
#define GPPU0 (0) // GPPU bit 0
#define GPPU1 (1) // GPPU bit 1
#define GPPU2 (2) // GPPU bit 2
#define GPPU3 (3) // GPPU bit 3
#define GPPU4 (4) // GPPU bit 4
#define GPPU5 (5) // GPPU bit 5
#define GPPU6 (6) // GPPU bit 6
#define GPPU7 (7) // GPPU bit 7

// INTF
#define INTF0 (0) // INTF bit 0
#define INTF1 (1) // INTF bit 1
#define INTF2 (2) // INTF bit 2
#define INTF3 (3) // INTF bit 3
#define INTF4 (4) // INTF bit 4
#define INTF5 (5) // INTF bit 5
#define INTF6 (6) // INTF bit 6
#define INTF7 (7) // INTF bit 7

// INTCAP
#define INTCAP0 (0) // INTCAP bit 0
#define INTCAP1 (1) // INTCAP bit 1
#define INTCAP2 (2) // INTCAP bit 2
#define INTCAP3 (3) // INTCAP bit 3
#define INTCAP4 (4) // INTCAP bit 4
#define INTCAP5 (5) // INTCAP bit 5
#define INTCAP6 (6) // INTCAP bit 6
#define INTCAP7 (7) // INTCAP bit 7

// GPIO
#define GP0 (0) // GPIO bit 0
#define GP1 (1) // GPIO bit 1
#define GP2 (2) // GPIO bit 2
#define GP3 (3) // GPIO bit 3
#define GP4 (4) // GPIO bit 4
#define GP5 (5) // GPIO bit 5
#define GP6 (6) // GPIO bit 6
#define GP7 (7) // GPIO bit 7

// OLAT
#define OL0 (0) // OLAT bit 0
#define OL1 (1) // OLAT bit 1
#define OL2 (2) // OLAT bit 2
#define OL3 (3) // OLAT bit 3
#define OL4 (4) // OLAT bit 4
#define OL5 (5) // OLAT bit 5
#define OL6 (6) // OLAT bit 6
#define OL7 (7) // OLAT bit 7

#endif // MCP23017_CONSTANTS_H_