# cubemx-workflow

The base STM32CubeMX/CubeIDE project template that every other demo in this
repo builds on. It sets up the system clock and a single GPIO output, then
blinks the onboard LED — a minimal "known-good" starting point to verify the
toolchain, clock tree, and flashing setup before layering on peripherals.

## What it shows
- STM32CubeMX project configuration: clock tree, pin muxing, HAL code generation
- System clock brought up to **80 MHz** (MSI → PLL)
- A single GPIO push-pull output (PA5 / LD2)
- The `HAL_Init` → `SystemClock_Config` → peripheral-init → main-loop structure
  reused across the other demos

## Hardware
- STM32L476RG (Nucleo-L476RG) <!-- TODO: confirm your board -->
- Onboard user LED **LD2** on **PA5**

## Behavior
The LED toggles every 500 ms (~1 Hz blink). If it blinks, your clock config,
build, and flash path are all working.

## CubeMX configuration
Reproduce the `.ioc` with:
- MCU: **STM32L476RGTx**
- **PA5** → `GPIO_Output`
- Clock config: MSI → PLL → **80 MHz** SYSCLK
- Toolchain/IDE: **STM32CubeIDE**

## Build & flash
Open the project in STM32CubeIDE and flash over ST-LINK, or from the command line:
