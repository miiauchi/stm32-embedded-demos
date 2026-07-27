# ir-remote-receiver

A consumer IR remote receiver on the STM32L476G-DISCO. A hardware timer samples
the IR input pin, and a custom parser decodes the NEC protocol into 32-bit button
codes that drive the onboard LEDs and segment LCD.

## What it shows
- Timer-driven (TIM7) sampling of an IR demodulator output into a 700-sample buffer
- NEC protocol decoding by pulse-width: short high runs -> 0 bits, long runs -> 1 bits
- Mapping decoded 32-bit codes to remote buttons
- Driving the glass LCD (via BSP) to display the pressed button for one second

## How it works
`captureIR()` runs on every TIM7 interrupt, filling `irdat[]` starting from the
first low sample. Once full, `parseIRCode()` walks the samples, measuring each
high pulse's length and shifting a 0 or 1 into the result accordingly, producing
the button's NEC code.

## Hardware
- STM32L476G-DISCO (glass LCD, onboard LEDs)
- IR receiver/demodulator module on PD0 (TIM7 sampling)
- NEC-protocol remote

## Files
```
Core/Src/main.c          # dispatch loop: parse code -> show button
Core/Src/ir.c            # timer-driven capture + NEC decode
Core/Inc/ir.h            # capture/parse interface
Core/Src/display.c       # button labels on the glass LCD
Core/Inc/display.h       # display interface
Core/Inc/ir_codes.h      # NEC button code definitions
Core/Src/stm32l4xx_it.c  # TIM7 ISR hook
```
