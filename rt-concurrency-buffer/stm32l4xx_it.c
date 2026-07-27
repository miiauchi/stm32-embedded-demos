/* Joystick center press → take a snapshot (Project 1) */
void EXTI0_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(JOY_CENTER_Pin);
  /* USER CODE BEGIN EXTI0_IRQn 1 */
	addToSnapshot();
  /* USER CODE END EXTI0_IRQn 1 */
}

/* TIM3 every 10 ms → enqueue Count */
void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */
	addToBuffer(count);
  /* USER CODE END TIM3_IRQn 1 */
}

/* TIM6 every 48 ms → dequeue up to 4 oldest */
void TIM6_DAC_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */
	if (count >= 4) {
		removeFromBuffer(4);
	}
	else if(count > 0 & count < 4) {
		removeFromBuffer(count);
	}
  /* USER CODE END TIM6_DAC_IRQn 1 */
}
