![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# 8x8 R Click

- **CIC Prefix**  : C8X8R
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Dec 2017.

---

### Software Support

We provide a library for the 8x8 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2323/8x8-r-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library provides generic functions for controlling the click board.

Key functions :

- ```void c8x8r_writeReg(uint8_t Reg, uint8_t Value);``` - Function for writing data to a register.
- ```void c8x8r_writeText(uint8_t *pStr, uint8_t nLenght);``` - Scrols provided text

**Examples Description**

The application is composed of three sections :

- System Initialization - Intializes CS pin as output and SPI module
- Application Initialization - Driver intialization and default configration of the 8x8 click board.
- Application Task - (code snippet) - Sequential writing of provided string each one second.


```.c
void applicationTask()
{
    c8x8r_displayWord(&demoString[0]);
    Delay_1sec();
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2323/8x8-r-click) page.

Other mikroE Libraries used in the example:

- Conversions
- C_String
- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
