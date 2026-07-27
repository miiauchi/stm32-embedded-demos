# fatfs-storage

Mounting a FAT32 filesystem on a USB flash drive from the STM32L476G-DISCO and
doing real file I/O with the FatFs library — reading a file, recursively walking
the directory tree, and writing the results back to the drive.

## What it shows
- Mounting a USB mass-storage device with `f_mount` over the USB Host stack
- Reading a file (`f_open` / `f_read` / `f_close`) and signaling success on an LED
- A **recursive directory scan** (`f_opendir` / `f_readdir`) that descends into
  subdirectories and collects every full file path
- Writing the collected listing to `DIRLIST.TXT` (`f_open` with
  `FA_WRITE | FA_CREATE_ALWAYS`, then `f_write`)

## Behavior
On a mounted drive, the board reads a target text file (green LED = success, red
= failure), then builds a complete path listing of the drive and writes it to
`DIRLIST.TXT` in the root. Pulling the drive and opening it on a PC confirms the
read and write both worked.

## Hardware
- STM32L476G-DISCO with USB OTG FS (host mode)
- FAT32-formatted USB flash drive

## Dependencies
Uses the CubeMX-generated FATFS + USB Host middleware (`USBHFatFS`, `USBHPath`,
`MyFile`, `rfilename`, `rtext`). This directory holds the file-operation logic.

## Files
```
Core/Src/main.c     # mount check, then read + scan + write sequence
Core/Src/fs_ops.c   # file read, recursive directory scan, listing writer
Core/Inc/fs_ops.h   # file-operations interface
```
