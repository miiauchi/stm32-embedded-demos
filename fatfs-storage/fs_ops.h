#ifndef fs_ops_h
#define fs_ops_h

#include "fatfs.h"

void    FS_FileOperations(void);
FRESULT scan_files(char* path);
FRESULT write_dirlist(char* path, char* list);

#endif
