/* USER CODE BEGIN Includes */
#include "ir.h"
#include "ir_codes.h"
#include "display.h"
#include <stdbool.h>
#include "stm32l476g_discovery.h"
#include "stm32l476g_discovery_glass_lcd.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
extern int flag;
extern int i;
/* USER CODE END PV */

/* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim7);   // IR sampling tick
	BSP_LCD_GLASS_Init();
/* USER CODE END 2 */

/* USER CODE BEGIN WHILE */
	while (1)
	{
		if(flag == 1){
			int num = parseIRCode();
			if(num == IR_A)      display_test(IR_A);
			if(num == IR_B)      display_test(IR_B);
			if(num == IR_C)      display_test(IR_C);
			if(num == IR_POWER)  display_test(IR_POWER);
			if(num == IR_UP)     display_test(IR_UP);
			if(num == IR_DOWN)   display_test(IR_DOWN);
			if(num == IR_LEFT)   display_test(IR_LEFT);
			if(num == IR_RIGHT)  display_test(IR_RIGHT);
			if(num == IR_CIRCLE) display_test(IR_CIRCLE);

			flag = 0;
			num = 0;
			i = 0;
			captureIR();
		}
	/* USER CODE END WHILE */
	}
