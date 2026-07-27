# gpio-led-control

Bare-metal (register-level) GPIO control on the STM32L476G-DISCO board. Drives
the onboard red (PB2) and green (PE8) LEDs directly through the RCC and GPIO
registers — no HAL — and blinks them using a calibrated software delay.

## What it shows
- Enabling GPIO port clocks via `RCC->AHB2ENR`
- Configuring pins through `MODER`, `OTYPER`, `PUPDR`
- Setting / clearing / toggling outputs via the `ODR` register
- A software delay loop (`delaymicro`) calibrated by measuring real blink timing

## Timing note
The `delaymicro()` loop was calibrated empirically: at 80 MHz, each iteration is
~4 CPU cycles (~50 ns), so ~10,000,000 iterations gives a 0.5 s delay. Verified
by video-timing 10 blink cycles and averaging — landed at ~0.502 s, within 5%.

## Hardware
- STM32L476G-DISCO
- Red LED → PB2, Green LED → PE8

## Dependencies
Uses a course-provided `SysClock.h` / `System_Clock_Init()` to bring the system
clock to 80 MHz, plus CMSIS device header `stm32l476xx.h`.

## Files
```
Core/Src/main.c   # blink loop
Core/Src/leds.c   # register-level LED driver + delay
Core/Inc/leds.h   # LED driver interface
```
