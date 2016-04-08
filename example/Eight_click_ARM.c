#include "stdint.h"

sbit LED_EIGHT_CS at GPIOD_ODR.B13;

int main(void)
{
  uint8_t text_1[] = "MikroE ";
  uint8_t text_2[] = "Low ";
  uint8_t text_3[] = "Medium ";
  uint8_t text_4[] = "Highest ";
  uint8_t image[8] = { 0x00,
                       0x66,
                       0x66,
                       0x18,
                       0x5A,
                       0x24,
                       0x18,
                       0x00
                     };



  GPIO_Digital_Output( &GPIOD_BASE, _GPIO_PINMASK_13 );

  /*SPI3_Init_Advanced( _SPI_FPCLK_DIV128,
                        _SPI_MASTER | _SPI_8_BIT | _SPI_CLK_IDLE_LOW |
                        _SPI_FIRST_CLK_EDGE_TRANSITION | _SPI_MSB_FIRST |
                        _SPI_SS_DISABLE | _SPI_SSM_ENABLE |
                        _SPI_SSI_1,
                        &_GPIO_MODULE_SPI3_PC10_11_12 ); */
  Delay_ms(400);

  led_eight_init();
  Delay_ms(400);

  while(1)
  {
      led_eight_scroll_text( text_1, 10 );
      Delay_ms(500);
      led_eight_set_intensity( 1 );
      led_eight_scroll_text( text_2, 15 );
      Delay_ms(500);
      led_eight_set_intensity( 5 );
      led_eight_scroll_text( text_3, 10 );
      Delay_ms(500);
      led_eight_set_intensity( 15 );
      led_eight_scroll_text( text_4, 5 );
      Delay_ms(500);
      led_eight_display_image( image );
      Delay_ms(1500);
  }


    return 0;
}