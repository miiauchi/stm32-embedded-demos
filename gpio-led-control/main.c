#include "stm32l476xx.h"
#include "SysClock.h"
#include "leds.h"

int main(void){

	System_Clock_Init(); // Switch System Clock = 80 MHz

	portB_en();
	portE_en();

	red_on();
	green_on();
	delaymicro(5000000 * 2); // large count to time it, then derived the ratio for 0.5 s
	red_off();

	while(1) { // actual blinking
		delaymicro(5000000 * 2);
		red_tog();
		green_tog();
	}
}
