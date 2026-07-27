/* USER CODE BEGIN Includes */
#include "ledstrip.h"
/* USER CODE END Includes */

/* ... CubeMX init: GPIO for SCK_Pin / SDO_Pin as push-pull outputs ... */

/* USER CODE BEGIN WHILE */
	while (1)
	{
		move(START, RED,    END, 0);
		move(START, ORANGE, END, 1);
		move(START, YELLOW, END, 2);
		move(START, GREEN,  END, 3);
		move(START, BLUE,   END, 4);
		move(START, INDIGO, END, 5);
		move(START, VIOLET, END, 6);
		HAL_Delay(250);
	/* USER CODE END WHILE */
	}
