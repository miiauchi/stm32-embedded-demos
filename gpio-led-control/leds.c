#include "leds.h"
#include "stm32l476xx.h"

void portB_en() {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	GPIOB->MODER  &= GPIO_MODER_MODER2_0;
	GPIOB->OTYPER &= GPIO_OTYPER_ODR_2;
	GPIOB->PUPDR  &= GPIO_PUPDR_PUPDR2;
}

void portE_en() {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
	GPIOE->MODER  &= GPIO_MODER_MODER8_0;
	GPIOE->OTYPER &= GPIO_OTYPER_ODR_8;
	GPIOE->PUPDR  &= GPIO_PUPDR_PUPDR8;
}

void red_on()    { GPIOB->ODR |=  GPIO_ODR_ODR_2; }
void green_on()  { GPIOE->ODR |=  GPIO_ODR_ODR_8; }
void red_off()   { GPIOB->ODR &= ~GPIO_ODR_ODR_2; }
void green_off() { GPIOE->ODR &= ~GPIO_ODR_ODR_8; }
void red_tog()   { GPIOB->ODR ^=  GPIO_ODR_ODR_2; }
void green_tog() { GPIOE->ODR ^=  GPIO_ODR_ODR_8; }

void delaymicro(unsigned int x) {
	while(x != 0) {
		x--;
	}
}
