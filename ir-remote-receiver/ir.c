#include "main.h"
#include "stm32l4xx_it.h"
#include "ir.h"
#include <stdint.h>

#define IN_PIN GPIO_PIN_0
#define IR_PORT GPIOD
#define SAMPLE_COUNT 700
#define NEC_BITS 32
#define NEC_REPEAT_THRESHOLD 100

volatile int i = 0;
volatile int flag = 0;
volatile int irdat[SAMPLE_COUNT];
volatile int x[1] = {0};

/* Called from the TIM7 ISR: samples the IR pin into irdat[].
 * Starts capturing on the first low sample, stops once the buffer is full. */
void captureIR(void){
	if(flag){
		return;
	}
	int IRdata = HAL_GPIO_ReadPin(IR_PORT, IR_IN_Pin);

	if(i == 0 && IRdata == GPIO_PIN_RESET) {
		irdat[i++] = IRdata;
	}
	else if(i > 0 && i < SAMPLE_COUNT) {
		irdat[i++] = IRdata;
		if(i >= SAMPLE_COUNT) {
			flag = 1;
		}
	}
}

/* Decode the captured samples into a 32-bit NEC code by measuring the
 * width of each high pulse: short run -> 0 bit, long run -> 1 bit. */
int parseIRCode(void) {
	int counter = 0;
	int countArr = 0;
	int mask = 0x00000000;

	while(countArr != SAMPLE_COUNT){
		if(irdat[countArr] == 1){
			counter++;
		}
		else {
			if(counter < 8 && counter != 0){
				mask *= 2;
			}
			else if(counter > 8 && counter < 18 && counter != 0){
				mask *= 2;
				mask++;
			}
			counter = 0;
		}
		countArr++;
	}
	x[0] = mask;
	return mask;
}
