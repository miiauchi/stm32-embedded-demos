# led-strip-spi

A software (bit-banged) SPI driver for an APA102 / SK9822 addressable RGB LED
strip on the STM32L476G-DISCO. No SPI peripheral — the clock and data lines are
toggled directly in firmware, which makes the protocol explicit.

## What it shows
- Bit-banged SPI: 32 bits shifted out MSB-first, SCK toggled per bit
- The APA102/SK9822 frame format: a start frame, one 32-bit word per LED
  (`0xE0|brightness`, then B, G, R), and an end frame
- Building full 60-LED frames and addressing individual pixels
- A rainbow pattern across the first seven LEDs

## Color format
Each LED word is `0x[E0|brightness][BLUE][GREEN][RED]` — the high byte is `0xE0`
plus a 5-bit global brightness value; the remaining three bytes are the color
channels.

## Hardware
- STM32L476G-DISCO
- SCK → `SCK_Pin`, data → `SDO_Pin` (push-pull outputs)
- APA102 / SK9822 60-LED strip

## Files
```
Core/Src/main.c        # rainbow animation loop
Core/Src/ledstrip.c    # bit-banged SPI + frame/pixel helpers
Core/Inc/ledstrip.h    # color definitions + driver interface
```
