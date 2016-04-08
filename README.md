![mikroe_logo] 
# by [MikroElektronika]
![8x8_image] 
# A compact and easy solution for adding 8x8 RED LED display matrix to your design.
# More information about [8x8 click] is found here.
---
## Installation
>If installing from package, [Package manager] required to install to your IDE.  

## Looking for a [tutorial?][8x8 Tutorial]

### Example
```
#include "led_eight_hw.h"

sbit LED_EIGHT_CS at GPIOD_ODR.B13;

void eight_by_eight_Init(){
  GPIO_Digital_Output( &GPIOD_BASE, _GPIO_PINMASK_13 );                   //Initialize GPIO outputs

  SPI3_Init_Advanced( _SPI_FPCLK_DIV128,                                  //Initialize SPI bus communication
                        _SPI_MASTER | _SPI_8_BIT | _SPI_CLK_IDLE_LOW |
                        _SPI_FIRST_CLK_EDGE_TRANSITION | _SPI_MSB_FIRST |
                        _SPI_SS_DISABLE | _SPI_SSM_ENABLE |
                        _SPI_SSI_1,
                        &_GPIO_MODULE_SPI3_PC10_11_12 ); 
  Delay_ms(400);

  led_eight_init();                                                       //Initialize 8x8 led click board
  Delay_ms(400);

}

```

```
// Main function

void main() {
  
  eight_by_eight_Init();                                               

  while(1)
  {}
}
```

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [MikroElektronika]: <http://www.mikroe.com/>
   [mikroe_logo]: <http://www.mikroe.com/img/designs/beta/logo_small.png>
   [8x8 click]: <http://www.mikroe.com/click/8x8-r/>
   [8x8_image]: <http://www.mikroe.com/img/development-tools/accessory-boards/click/8x8-r/gallery/8x8_r_click_02.jpg>
   [8x8 Tutorial]: <http://learn.mikroe.com/led-matrices/>
   [Package Manager]: <http://www.mikroe.com/package-manager/>
