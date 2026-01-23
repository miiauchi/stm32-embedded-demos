#include "stm32l476xx.h"
#include "SysClock.h"
#include "leds.h"
int main(void){
  System_Clock_Init(); // Switch System Clock = 80 MHz
  portB_en();
  portE_en();
  red_on();
  green_on();
  delaymicro(5000000 * 2); //500k * 40 = big # so we can time it, figured out ratio for .5s
  red_off();
  while(1) {
    delaymicro(5000000 * 2);
    red_tog();
    green_tog();
  }
}
