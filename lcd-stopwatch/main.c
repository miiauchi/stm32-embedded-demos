/* USER CODE BEGIN Includes */
#include "display.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
volatile bool on = true;
volatile bool pressed_center = false;
volatile bool pressed_left = false;
volatile int minutes = 0;
volatile int seconds = 0;
/* USER CODE END PV */

/* ... in main(), after peripheral init ... */
/* USER CODE BEGIN 2 */
	BSP_LCD_GLASS_Init();
/* USER CODE END 2 */

/* USER CODE BEGIN WHILE */
	while (1)
	{
		if(pressed_left) {                 // reset
			minutes = 0;
			seconds = 0;
			pressed_left = !pressed_left;
			display_test(minutes, seconds);
		}
		if(on) {                           // running: tick once per second
			display_test(minutes, seconds);
			seconds++;
			if(seconds > 60) {
				seconds = 0;
				minutes++;
				if(minutes > 99) {
					minutes = 0;
					seconds = 0;
				}
			}
			HAL_Delay(1000);
		}
		if(pressed_center) {               // pause / resume
			on = !on;
			pressed_center = !pressed_center;
			display_test(minutes, seconds);
		}
	/* USER CODE END WHILE */
	}
