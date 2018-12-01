/*
Example for C8x8R Click

    Date          : Dec 2017.
    Author        : MikroE Team

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Intializes CS pin as output and SPI module
- Application Initialization - Driver intialization and default configration
of the 8x8 click board.
- Application Task - (code snippet) - Sequential writing of provided string 
each one second.


*/

#include "Click_C8x8R_types.h"
#include "Click_C8x8R_config.h"

uint8_t demoString[13]={ ' ', '-', '-', 'M', 'i', 'k', 'r', 'o', 'E', '-', '-', ' ', 0 };

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS2, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS2, &_C8X8R_SPI_CFG[0] );
    Delay_100ms();
}

void applicationInit()
{
    c8x8r_spiDriverInit( (T_C8X8R_P)&_MIKROBUS2_GPIO, (T_C8X8R_P)&_MIKROBUS2_SPI );

    c8x8r_writeReg(_C8X8R_DECODE_MODE_REG, _C8X8R_NO_DECODE);
    c8x8r_writeReg(_C8X8R_INTENSITY_REG,   _C8X8R_INTENSITY_15);
    c8x8r_writeReg(_C8X8R_SCAN_LIMIT_REG,  _C8X8R_DISPLAY_DIGIT_0_7);
    c8x8r_writeReg(_C8X8R_SHUTDOWN_REG,    _C8X8R_NORMAL_OPERATION);
    Delay_100ms();
}

void applicationTask()
{
    c8x8r_displayWord(&demoString[0]);
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}