/* Joystick CENTER → pause / resume */
void EXTI0_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(JOY_CENTER_Pin);
  /* USER CODE BEGIN EXTI0_IRQn 1 */
	pressed_center = true;
  /* USER CODE END EXTI0_IRQn 1 */
}

/* Joystick LEFT → reset */
void EXTI1_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(JOY_LEFT_Pin);
  /* USER CODE BEGIN EXTI1_IRQn 1 */
	pressed_left = true;
  /* USER CODE END EXTI1_IRQn 1 */
}
