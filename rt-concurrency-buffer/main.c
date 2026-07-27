/* USER CODE BEGIN Includes */
#include "buffer.h"
/* USER CODE END Includes */

/* ... CubeMX peripheral init (TIM3, TIM6, GPIO joystick, NVIC) ... */

/* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim3);   // 10 ms enqueue tick
	HAL_TIM_Base_Start_IT(&htim6);   // 48 ms dequeue tick
/* USER CODE END 2 */

/* --- Project 1: snapshot taken inside the joystick ISR --- */
/* while (1) { } — buffer runs entirely on interrupts */

/* --- Project 2: joystick disabled; snapshot taken in the main loop, */
/*     guarded by a critical section so an ISR can't corrupt the copy --- */
/* USER CODE BEGIN WHILE */
	while (1)
	{
		__disable_irq();
		addToSnapshot();
		__enable_irq();
		HAL_Delay(1000);
	/* USER CODE END WHILE */
	}
