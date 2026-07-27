# STM32 Embedded Demos

Bare-metal firmware demos for the **STM32L476** (ARM Cortex-M4), written in C.
Each demo targets a single peripheral or concept from my embedded systems
coursework and personal exploration — small, readable, and self-contained.

## Demos
- **cubemx-workflow** — STM32CubeMX project setup and HAL code-generation workflow
- **gpio-led-control** — GPIO digital output driving LEDs <!-- TODO: mention buttons/interrupts if used -->
- **lcd-stopwatch** — stopwatch on an LCD, driven by hardware timers
- **led-strip-spi** — driving an addressable LED strip over SPI
- **rt-concurrency-buffer** — real-time concurrency / buffering <!-- TODO: e.g. ring buffer, producer–consumer, interrupt-driven — describe in one line -->

## Hardware
- STM32L476 <!-- TODO: specify Nucleo-L476RG / Discovery / custom board -->

## Toolchain
<!-- TODO: fill in what you actually use -->
- STM32CubeIDE / STM32CubeMX (or `arm-none-eabi-gcc` + `make`)
- ST-LINK for flashing/debugging

## Layout
```
/cubemx-workflow
/gpio-led-control
/lcd-stopwatch
/led-strip-spi
/rt-concurrency-buffer
```

## Building
<!-- TODO: 2-3 lines on how to build/flash a demo -->
```
# example
make
st-flash write build/demo.bin 0x8000000
```
