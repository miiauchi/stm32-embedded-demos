#include "main.h"
#include "fatfs.h"
#include "fs_ops.h"
#include <string.h>
#include <stdio.h>

/* Buffers / FatFs objects declared in the CubeMX-generated FATFS app files:
 *   USBHFatFS, USBHPath, MyFile, rtext[], rfilename */
extern char dirlist[];   /* accumulates the recursive scan output */

/* Part 1: mount the drive, read a text file, signal success on the green LED */
void FS_FileOperations(void) {
	FRESULT res;          /* FatFs common result code */
	uint32_t bytesread;   /* file read count */

	/* Register the file system object to the FatFs module */
	if(f_mount(&USBHFatFS, (TCHAR const*)USBHPath, 0) == FR_OK) {
		/* Open the text file with read access */
		if(f_open(&MyFile, rfilename, FA_READ) == FR_OK) {
			res = f_read(&MyFile, rtext, sizeof(rtext) - 1, &bytesread);
			if((bytesread > 0) && (res == FR_OK)) {
				f_close(&MyFile);
				HAL_GPIO_WritePin(LD_G_GPIO_Port, LD_G_Pin, GPIO_PIN_SET);
				return;
			}
		}
	}
	HAL_GPIO_WritePin(LD_R_GPIO_Port, LD_R_Pin, GPIO_PIN_SET);
}

/* Part 2: recursively walk `path`, appending every file's full path to dirlist */
FRESULT scan_files(char* path) {
	FRESULT res;
	DIR dir;
	int i;
	static FILINFO fno;

	res = f_opendir(&dir, path);
	if(res == FR_OK) {
		while(1) {
			res = f_readdir(&dir, &fno);
			if (res != FR_OK || fno.fname[0] == 0) {
				break;
			}
			if (fno.fattrib & AM_DIR) {              /* recurse into subdirectory */
				i = strlen(path);
				sprintf(&path[i], "/%s", fno.fname);
				res = scan_files(path);
				if (res != FR_OK) {
					break;
				}
				path[i] = 0;                         /* restore path on the way back up */
			}
			else {                                   /* record the file path */
				sprintf(dirlist + strlen(dirlist), "%s/%s\n", path, fno.fname);
			}
		}
		f_closedir(&dir);
	}
	return res;
}

/* Write the collected directory listing to a file (e.g. DIRLIST.TXT) */
FRESULT write_dirlist(char* path, char* list) {
	FIL OutFile;
	FRESULT res = FR_DISK_ERR;
	uint32_t byteswritten;

	if (f_open(&OutFile, path, FA_WRITE | FA_CREATE_ALWAYS) == FR_OK) {
		res = f_write(&OutFile, list, strlen(list), &byteswritten);
		if (res == FR_OK) {
			f_close(&OutFile);
		}
	}
	return res;
}
