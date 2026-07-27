/* USER CODE BEGIN Includes */
#include "fs_ops.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
char dirlist[4096];   /* accumulates the recursive scan output */
/* USER CODE END PV */

/* ... after MX_USB_HOST_Process() reports the drive is mounted ... */

/* USER CODE BEGIN 3 */
	/* Part 1: read a file from the drive */
	FS_FileOperations();

	/* Part 2: recursively list the drive, then write the listing back */
	char root[256] = "";
	if (scan_files(root) == FR_OK) {
		if (write_dirlist("DIRLIST.TXT", dirlist) == FR_OK) {
			HAL_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, GPIO_PIN_SET);
		}
	}
/* USER CODE END 3 */
