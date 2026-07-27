# lcd-stopwatch

A minutes:seconds stopwatch on the STM32L476G-DISCO's onboard segment LCD,
controlled by the joystick. Demonstrates driving the glass LCD through ST's
board support package (BSP) and using interrupts for start/stop/reset input.

## What it shows
- Driving the DISCO glass LCD via `BSP_LCD_GLASS_DisplayChar`
- Rendering MM:SS across digit positions 3-6, using the double-point as a colon
- Converting integer time values to display characters
- Joystick input over EXTI interrupts that set flags read by the main loop
  (center = pause/resume, left = reset)

## Controls
- **Center press** → pause / resume
- **Left press** → reset to 00:00

## Hardware
- STM32L476G-DISCO (onboard segment glass LCD + joystick)

## Files
```
Core/Src/main.c          # stopwatch loop + control flags
Core/Src/display.c       # MM:SS rendering on the glass LCD
Core/Inc/display.h       # display interface
Core/Src/stm32l4xx_it.c  # joystick ISR hooks
```
