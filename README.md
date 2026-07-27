# STM32 Embedded Demos

Firmware demos for the **STM32L476G-DISCO** (ARM Cortex-M4), written in C from my
Real-Time Embedded Systems coursework (ECEN 121). Each demo isolates one
peripheral or concept, and together they span the full range of how you work with
an STM32 — from toggling registers directly, to the HAL library, to building on
ST's USB Host and FatFs middleware.

## Range (why this repo)
- **Bare-metal / register-level** — direct `RCC` and `GPIO` register access via
  CMSIS, no HAL (see `gpio-led-control`)
- **HAL / CubeMX** — peripheral setup and drivers through the HAL layer
  (timers, SPI, LCD, interrupts)
- **Middleware integration** — USB Host + HID and a FatFs filesystem on top of
  the generated stack

## Demos
- **cubemx-workflow** — the base CubeMX/CubeIDE project template (clock config,
  pin muxing, HAL setup) the HAL demos build on
- **gpio-led-control** — bare-metal register-level GPIO: driving the onboard LEDs
  with a calibrated software delay, no HAL
- **lcd-stopwatch** — an MM:SS stopwatch on the onboard segment LCD (via BSP),
  with joystick-driven start/stop/reset over EXTI interrupts
- **led-strip-spi** — a bit-banged SPI driver for an APA102/SK9822 addressable
  LED strip, with a rainbow animation
- **rt-concurrency-buffer** — a circular FIFO buffer shared safely across TIM3,
  TIM6, and joystick interrupts, using both interrupt-priority and critical-section
  (`__disable_irq`) strategies
- **ir-remote-receiver** — a consumer IR receiver: TIM7 samples the IR input and a
  custom parser decodes the NEC protocol into 32-bit button codes
- **usb-mouse-to-led** — a USB HID host that reads a USB mouse and maps its motion
  and clicks to a moving, color-cycling spot on the LED strip
- **fatfs-storage** — mounting a FAT32 USB drive and doing real file I/O with FatFs,
  including a recursive directory scan written back to the drive

## Hardware
- STM32L476G-DISCO (onboard LEDs, segment glass LCD, joystick, USB OTG FS)
- APA102 / SK9822 LED strip, IR receiver module, USB mouse, USB flash drive
  (per demo)

## Toolchain
- Early demos build against CMSIS device headers (`stm32l476xx.h`) with a
  course-provided `SysClock` for the 80 MHz clock
- HAL/middleware demos are STM32CubeIDE / CubeMX projects (`.ioc` + generated code)
- Flashed and debugged over the onboard ST-LINK

## Skills shown
GPIO, timers, EXTI/NVIC interrupts, bit-banged SPI, interrupt-safe concurrency,
protocol decoding (NEC IR), USB Host / HID, and FAT filesystem I/O.
