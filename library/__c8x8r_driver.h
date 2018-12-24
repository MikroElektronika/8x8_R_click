/*
    __c8x8r_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __c8x8r_driver.h
@brief    8x8_R Driver
@mainpage 8x8_R Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   C8X8R
@brief      8x8_R Click Driver
@{

| Global Library Prefix | **C8X8R** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _C8X8R_H_
#define _C8X8R_H_

/** 
 * @macro T_C8X8R_P
 * @brief Driver Abstract type 
 */
#define T_C8X8R_P    const uint8_t*

/** @defgroup C8X8R_COMPILE Compilation Config */              /** @{ */

   #define   __C8X8R_DRV_SPI__                            /**<     @macro __C8X8R_DRV_SPI__  @brief SPI driver selector */
//  #define   __C8X8R_DRV_I2C__                            /**<     @macro __C8X8R_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __C8X8R_DRV_UART__                           /**<     @macro __C8X8R_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup C8X8R_VAR Variables */                           /** @{ */


extern const uint8_t _C8X8R_SPEED_FAST;
extern const uint8_t _C8X8R_SPEED_MEDIUM;
extern const uint8_t _C8X8R_SPEED_SLOW;

extern const uint8_t _C8X8R_DECODE_MODE_REG;
extern const uint8_t _C8X8R_INTENSITY_REG;
extern const uint8_t _C8X8R_SCAN_LIMIT_REG;
extern const uint8_t _C8X8R_SHUTDOWN_REG;
extern const uint8_t _C8X8R_DISPLAY_TEST_REG;
                                                                       
extern const uint8_t _C8X8R_NO_DECODE;
extern const uint8_t _C8X8R_DECODE_DIGIT_0;                                        
extern const uint8_t _C8X8R_DECODE_DIGIT_3_0;
extern const uint8_t _C8X8R_DECODE_DIGIT_7;

extern const uint8_t _C8X8R_INTENSITY_1;
extern const uint8_t _C8X8R_INTENSITY_3;
extern const uint8_t _C8X8R_INTENSITY_5;
extern const uint8_t _C8X8R_INTENSITY_7;
extern const uint8_t _C8X8R_INTENSITY_9;
extern const uint8_t _C8X8R_INTENSITY_11;
extern const uint8_t _C8X8R_INTENSITY_13;
extern const uint8_t _C8X8R_INTENSITY_15;
extern const uint8_t _C8X8R_INTENSITY_17;
extern const uint8_t _C8X8R_INTENSITY_19;
extern const uint8_t _C8X8R_INTENSITY_21;
extern const uint8_t _C8X8R_INTENSITY_23;
extern const uint8_t _C8X8R_INTENSITY_25;
extern const uint8_t _C8X8R_INTENSITY_27;
extern const uint8_t _C8X8R_INTENSITY_29;
extern const uint8_t _C8X8R_INTENSITY_31;

extern const uint8_t _C8X8R_DISPLAY_DIGIT_0;
extern const uint8_t _C8X8R_DISPLAY_DIGIT_0_1;
extern const uint8_t _C8X8R_DISPLAY_DIGIT_0_2;
extern const uint8_t _C8X8R_DISPLAY_DIGIT_0_3;
extern const uint8_t _C8X8R_DISPLAY_DIGIT_0_4; 
extern const uint8_t _C8X8R_DISPLAY_DIGIT_0_5;
extern const uint8_t _C8X8R_DISPLAY_DIGIT_0_6;
extern const uint8_t _C8X8R_DISPLAY_DIGIT_0_7;

extern const uint8_t _C8X8R_SHUTDOWN_MODE;
extern const uint8_t _C8X8R_NORMAL_OPERATION;

extern const uint8_t _C8X8R_DISPLAY_NORMAL_OPERATION;
extern const uint8_t _C8X8R_DISPLAY_TEST_MODE;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup C8X8R_INIT Driver Initialization */              /** @{ */

#ifdef   __C8X8R_DRV_SPI__
void c8x8r_spiDriverInit(T_C8X8R_P gpioObj, T_C8X8R_P spiObj);
#endif
#ifdef   __C8X8R_DRV_I2C__
void c8x8r_i2cDriverInit(T_C8X8R_P gpioObj, T_C8X8R_P i2cObj, uint8_t slave);
#endif
#ifdef   __C8X8R_DRV_UART__
void c8x8r_uartDriverInit(T_C8X8R_P gpioObj, T_C8X8R_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void c8x8r_gpioDriverInit(T_C8X8R_P gpioObj);
                                                                       /** @} */
/** @defgroup C8X8R_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function for sending the command
 *
 * @param[in] command         the command to be executed
 * @param[in] _data           data to be sent
 *
 */
void c8x8r_writeCmd(uint8_t command, uint8_t _data);

/**
 * @brief Function for refresh display
 *
 * The function switches off all LEDs
 */
void c8x8r_displayRefresh();

/**
 * @brief Function for settings speed scroll display string
 *
 * @param[in] speed        Speed that will be set
 *
 * Options:
      Fast speed (30ms per character),
      Medium speed (100ms per character) - default speed,
      Slow speed ( 200ms per character),
 */
void c8x8r_setSpeedScroll(uint8_t speed);

/**
 * @brief Function for displaying one character
 * 
 * @param[in] ch        Character to be displayed
 *
 */
void c8x8r_displayByte(char ch);

/**
 * @brief Scroll string function
 *
 * @param[in] pArray       Pointer to the string to be displayed
 *
 * Function that displays scrolled string with set speed.
   If the speed is not set before calling the function,
   default scroll speed is 100ms per character.
 */
void c8x8r_displayString(char *pArray);

/**
 * @brief Image display function
 *
 * @param[in] pArray       Pointer to the image to be displayed
 *
 * Function for displays the image.
   The image consists of eight elements (eight columns that build the image).
 */
void c8x8r_displayImage(uint8_t *pArray);





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_8x8_R_STM.c
    @example Click_8x8_R_TIVA.c
    @example Click_8x8_R_CEC.c
    @example Click_8x8_R_KINETIS.c
    @example Click_8x8_R_MSP.c
    @example Click_8x8_R_PIC.c
    @example Click_8x8_R_PIC32.c
    @example Click_8x8_R_DSPIC.c
    @example Click_8x8_R_AVR.c
    @example Click_8x8_R_FT90x.c
    @example Click_8x8_R_STM.mbas
    @example Click_8x8_R_TIVA.mbas
    @example Click_8x8_R_CEC.mbas
    @example Click_8x8_R_KINETIS.mbas
    @example Click_8x8_R_MSP.mbas
    @example Click_8x8_R_PIC.mbas
    @example Click_8x8_R_PIC32.mbas
    @example Click_8x8_R_DSPIC.mbas
    @example Click_8x8_R_AVR.mbas
    @example Click_8x8_R_FT90x.mbas
    @example Click_8x8_R_STM.mpas
    @example Click_8x8_R_TIVA.mpas
    @example Click_8x8_R_CEC.mpas
    @example Click_8x8_R_KINETIS.mpas
    @example Click_8x8_R_MSP.mpas
    @example Click_8x8_R_PIC.mpas
    @example Click_8x8_R_PIC32.mpas
    @example Click_8x8_R_DSPIC.mpas
    @example Click_8x8_R_AVR.mpas
    @example Click_8x8_R_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __c8x8r_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */