# AVR ATmega_Drivers
This is an ATmega Drivers for the NTI Automotive Embedded Systems 4-month Internship. This project was written in C using Microchip Studio and Proteus 8 Professional.

## Demonstration

I used Proteus 8 Professional and Eta32 ATMEL AVR Development Kit in order to simulate AVR Atmega32. 

## System Functionality
- This repository contains drivers for the AVR ATmega32 microcontroller. The drivers are divided into three directories:
  
- MCAL: (Microcontroller Abstraction Layer) It abstracts away the low-level hardware details of the MCU, providing a higher-level interface for working with hardware peripherals. The drivers included in this directory are:
- [DIO DRIVER](https://github.com/RoqaiaWagih/ATmega_Drivers/tree/DRIVERS/MCAL)
  
- HAL: (Hardware Abstraction Layer). It provides an even higher-level interface for working with commonly used hardware peripherals. The drivers included in this directory are:
- [LCD DRIVER](https://github.com/RoqaiaWagih/ATmega_Drivers/tree/DRIVERS/HAL/LCD)
- [SEVEN SEGMENT DRIVER](https://github.com/RoqaiaWagih/ATmega_Drivers/tree/DRIVERS/HAL/SSD)
  
- Utils: This directory contains commonly used macros and standard types used by the drivers.
## Details & Program Flow Chart
- You can find system details and program flow chart in the project documentation
### MCAL(Microcontroller Abstraction Layer)
#### DIO DRIVER:
The DriverVoid module provides a set of functions for configuring and manipulating digital Input/Output (DIO) pins and ports on an AVR microcontroller. It includes functions to set pin direction, pin value, get pin value, toggle pin value, set port direction, set port value, get port value, toggle port value, and activate pull-up resistance on a port.
### HAL(Hardware Abstraction Layer)
#### LCD DRIVER
The LCD driver is designed to interface with an LCD (Liquid Crystal Display) using two ports (Port A and Port B) for data communication. It includes functions for initializing the LCD, writing data and commands, positioning the cursor, clearing the display, and displaying numbers and strings.

#### 7-segment 
The 7-Segment Display Driver is designed to interface with a 7-segment display, allowing the display of numeric digits from 0 to 9. The driver supports both common cathode and common anode 7-segment displays

## References
- Eta32 ATMEL AVR Development Kit datasheet
- ATmega32A datasheet
