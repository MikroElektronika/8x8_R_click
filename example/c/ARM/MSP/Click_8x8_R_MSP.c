/*
Example for 8x8_R Click

    Date          : Jan 2018.
    Author        : MikroE Team

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : vCANT_FIND_VERSION

---

Description :

The application is composed of three sections :

- System Initialization - Intializes CS pin as output and SPI module
- Application Initialization - Driver intialization and default configration
of the 8x8 click board and settings speed scroll as Midium speed and refresh display.
- Application Task - (code snippet) - Shows one byte, then scrolls the string and image, every 1 sec.

*/

#include "Click_8x8_R_types.h"
#include "Click_8x8_R_config.h"

uint8_t demoString[11]={ ' ','-','M','i','k','r','o','E','-',' ',0 };
uint8_t demoImgOn[8]={0x08, 0x1c, 0x36, 0x22, 0x08, 0x1c, 0x36, 0x22};
uint8_t demoImgOff[8]={0xf7, 0xe3, 0xc9, 0xdd, 0xf7, 0xe3, 0xc9, 0xdd};
char demoChar = 'R';

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_C8X8R_SPI_CFG[0] );
    Delay_100ms();
}

void applicationInit()
{
    c8x8r_spiDriverInit( (T_C8X8R_P)&_MIKROBUS1_GPIO, (T_C8X8R_P)&_MIKROBUS1_SPI );

    c8x8r_writeCmd(_C8X8R_DECODE_MODE_REG, _C8X8R_NO_DECODE);
    c8x8r_writeCmd(_C8X8R_INTENSITY_REG,   _C8X8R_INTENSITY_15);
    c8x8r_writeCmd(_C8X8R_SCAN_LIMIT_REG,  _C8X8R_DISPLAY_DIGIT_0_7);
    c8x8r_writeCmd(_C8X8R_SHUTDOWN_REG,    _C8X8R_NORMAL_OPERATION);
    
    c8x8r_setSpeedScroll(_C8X8R_SPEED_MEDIUM);
    c8x8r_displayRefresh();
    Delay_100ms();
}

void applicationTask()
{
    c8x8r_displayByte(demoChar);
    Delay_ms( 1000 );
    c8x8r_displayString(&demoString[0]);
    Delay_ms( 1000 );
    c8x8r_displayImage(&demoImgOn[0]);
    Delay_ms( 500 );
    c8x8r_displayImage(&demoImgOff[0]);
    Delay_ms( 1000 );
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
