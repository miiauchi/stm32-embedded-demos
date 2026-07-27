/* USER CODE BEGIN PD */
/* Color palette (defined in the project base). Example:            */
/*   #define KPINK   (0x005050ff | KBRIGHT)                          */
/* KRED, KYELLOW, KPURPLE, KGREEN, KBLUE, KPINK, KWHITE, KORANGE ... */
/* SPOTFRAC tuned to 500 for a good movement-to-sensitivity balance  */
/* USER CODE END PD */

/* USER CODE BEGIN PV */
int flag = 0;
int arr[8] = {KRED, KYELLOW, KPURPLE, KGREEN, KBLUE, KPINK, KWHITE, KORANGE};
int i = 4;
/* USER CODE END PV */

/* USER CODE BEGIN WHILE */
	while (1)
	{
		setDot(colors, NUM_LEDS, spotLocation, arr[i]);   // draw the spot at its color

		MX_USB_HOST_Process();

		if (hUsbHostFS.gState == HOST_CLASS) {
			devType = USBH_HID_GetDeviceType(&hUsbHostFS);

			if (devType == HID_MOUSE) {
				mouseInfo = USBH_HID_GetMouseInfo(&hUsbHostFS);
				if (mouseInfo != NULL) {
					/* map horizontal mouse motion to spot position */
					spotLocation = spotUpdate(spotLocation, fixData(mouseInfo->x));

					/* left-click (press then release) cycles to the next color */
					if(mouseInfo->buttons[0] != 0) {
						if(flag == 0) {
							flag = 1;
						}
					}
					if(mouseInfo->buttons[0] != 1 && flag == 1) {
						i = (i + 1) % 8;
						flag = 0;
					}
				}
			}
		}
		else if (hUsbHostFS.gState == HOST_IDLE) {
			HAL_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_RESET);
		}
	/* USER CODE END WHILE */
	}
