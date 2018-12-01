/*
Example for C8x8R Click

    Date          : Dec 2017.
    Author        : MikroE Team

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

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

uint8_t demoSring[13]={ ' ', '-', '-', 'M', 'i', 'k', 'r', 'o', 'E', '-', '-', ' ' };

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_C8X8R_SPI_CFG[0] );
    Delay_100ms();
}

void applicationInit()
{
    c8x8r_spiDriverInit( (T_C8X8R_P)&_MIKROBUS1_GPIO, (T_C8X8R_P)&_MIKROBUS1_SPI );

    c8x8r_writeReg(_C8X8R_DECODE_MODE_REG, _C8X8R_NO_DECODE);
    c8x8r_writeReg(_C8X8R_INTENSITY_REG,   _C8X8R_INTENSITY_15);
    c8x8r_writeReg(_C8X8R_SCAN_LIMIT_REG,  _C8X8R_DISPLAY_DIGIT_0_7);
    c8x8r_writeReg(_C8X8R_SHUTDOWN_REG,    _C8X8R_NORMAL_OPERATION);
    Delay_100ms();
}

void applicationTask()
{
    c8x8r_displayWord(&demoSring[0]);
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