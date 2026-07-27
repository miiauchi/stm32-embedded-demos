#include "main.h"
#include "ledstrip.h"

/* Bit-bang 32 bits out the SPI port, MSB first.
 * SCK starts low and ends low; SDO carries the data bit. */
void spi32(unsigned int c) {
	int i;
	for(i = 0; i < 32; i++) {
		if(c & 0x80000000) {
			HAL_GPIO_WritePin(SDO_GPIO_Port, SDO_Pin, GPIO_PIN_SET);
		}
		else {
			HAL_GPIO_WritePin(SDO_GPIO_Port, SDO_Pin, GPIO_PIN_RESET);
		}
		HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET);
		c <<= 1;
	}
}

/* Send one full frame: start header, one color, end frame */
void
