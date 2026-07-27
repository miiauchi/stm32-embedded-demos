# STM32 Embedded Demos

Bare-metal firmware demos for the **STM32L476** (ARM Cortex-M4), written in C.
Each demo isolates a single peripheral or concept — small, readable, and
self-contained — drawn from my real-time embedded systems coursework and
hardware projects.

## Demos
- **cubemx-workflow** — STM32CubeMX / CubeIDE project setup: clock configuration,
  pin muxing, and HAL code generation — the clean starting template the other demos build on
- **gpio-led-control** — GPIO fundamentals: driving LEDs from digital outputs,
  with button / joystick input handled via external (NVIC) interrupts
- **lcd-stopwatch** — a stopwatch driven by hardware timers and timer interrupts,
  displayed on a character LCD (start / stop / reset)
- **led-strip-spi** — driving an addressable SK9822 RGB LED strip over SPI,
  including color and animation patterns
- **rt-concurrency-buffer** — real-time, non-blocking firmware: multiple tasks
  serviced from a cooperative main loop without blocking delays, using an
  interrupt-driven buffer
- **adc-sampling** — sampling an analog input (e.g. potentiometer) with the ADC
  and driving output in response
- **uart-comms** — serial send / receive over UART with a host terminal

## Hardware
- STM32L476 <!-- TODO: confirm board — Nucleo-L476RG / Discovery / custom -->

## Toolchain
- STM32CubeIDE with the HAL library <!-- TODO: switch to Keil uVision here if that's what you used -->
- ST-LINK for flashing and debugging

## Layout
```
/cubemx-workflow
/gpio-led-control
/lcd-stopwatch
/led-strip-spi
/rt-concurrency-buffer
/adc-sampling
/uart-comms
```

## Building
Open the demo's project in STM32CubeIDE and flash via ST-LINK, or build from the
command line:
```
make
st-flash write build/demo.bin 0x8000000
```
