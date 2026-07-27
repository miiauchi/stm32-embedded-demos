/* TIM7 → sample the IR input pin */
void TIM7_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */
	captureIR();
  /* USER CODE END TIM7_IRQn 1 */
}
