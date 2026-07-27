#include "main.h"
#include "stm32l476g_discovery.h"
#include "stm32l476g_discovery_glass_lcd.h"

volatile int seccount = 0;
volatile int mincount = 0;
volatile int tenth = 0;

/* Render MM:SS across LCD digit positions 3-6.
 * The colon is the double-point on the minutes-ones digit. */
void display_test(int min, int sec) {
	unsigned char minten = min / 10 + '0';
	unsigned char minone = min % 10 + '0';
	unsigned char secten = sec / 10 + '0';
	unsigned char secone = sec % 10 + '0';

	BSP_LCD_GLASS_DisplayChar(&minten, POINT_OFF, DOUBLEPOINT_OFF, LCD_DIGIT_POSITION_3);
	BSP_LCD_GLASS_DisplayChar(&minone, POINT_OFF, DOUBLEPOINT_ON,  LCD_DIGIT_POSITION_4);
	BSP_LCD_GLASS_DisplayChar(&secten, POINT_OFF, DOUBLEPOINT_OFF, LCD_DIGIT_POSITION_5);
	BSP_LCD_GLASS_DisplayChar(&secone, POINT_OFF, DOUBLEPOINT_OFF, LCD_DIGIT_POSITION_6);
}
