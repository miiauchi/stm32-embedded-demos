# rt-concurrency-buffer

A circular (FIFO) buffer on the STM32L476G-DISCO shared safely across multiple
interrupt sources — the core embedded challenge of moving data between ISRs and
the main context without corruption.

## What it shows
- A fixed-size circular buffer with wrap-around (`% 64`) head/tail indices
- Three concurrent interrupt sources touching shared state:
  - **TIM3 (10 ms)** — enqueues a running counter
  - **TIM6 (48 ms)** — dequeues up to 4 oldest elements
  - **Joystick (EXTI0)** — snapshots the live buffer into `Snapshot[]`
- Two different approaches to concurrency safety (below)

## Two safety strategies
**Project 1 — interrupt priority.** All three interrupts share equal NVIC
priority, so the Cortex-M4 never lets one preempt another. Combined with each
ISR touching a distinct part of the structure (TIM3 writes the tail, TIM6 moves
the head, the joystick only reads), the snapshot runs in a non-nested context
and stays consistent without explicit locks.

**Project 2 — critical section.** With the joystick disabled, the snapshot moves
into the main loop and runs every second. Because a timer ISR could now fire
mid-copy, the copy is wrapped in `__disable_irq()` / `__enable_irq()` (setting
PRIMASK) so no maskable interrupt can modify the buffer during the snapshot.

## Hardware
- STM32L476G-DISCO (TIM3, TIM6, joystick-center on EXTI0)

## Files
```
Core/Src/main.c          # start timers; Project 2 critical-section snapshot loop
Core/Src/buffer.c        # circular buffer + snapshot logic
Core/Inc/buffer.h        # buffer interface
Core/Src/stm32l4xx_it.c  # ISR hooks (TIM3 enqueue, TIM6 dequeue, joystick snapshot)
```
