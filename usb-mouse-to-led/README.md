# usb-mouse-to-led

A USB HID host on the STM32L476G-DISCO: plug in a standard USB mouse and its
motion drives a "spot" along an addressable LED strip, with mouse clicks cycling
the spot's color. Built on ST's USB Host middleware.

## What it shows
- Acting as a USB **host** (not device) using the STM32Cube USB Host stack
- Enumerating a HID mouse and polling it via `USBH_HID_GetMouseInfo`
- Handling the host state machine (`HOST_CLASS`, `HOST_IDLE`) each loop
- Mapping relative mouse X-motion to a position on the strip, with edge-case
  handling for negative movement (`fixData` sign-extends negative deltas)
- Press-then-release click detection to cycle through an 8-color palette

## Tuning
`SPOTFRAC` scales how far the spot moves per unit of mouse movement. It was tuned
to 500 to balance responsiveness against jitter.

## USB notes (from bring-up)
- Retrieved the mouse's Vendor ID / Product ID during enumeration
- Confirmed the number of active USB pipes and traced HID events through the host
  stack (`USBH_UsrLog`, `USBH_HID_GetMouseInfo`)

## Hardware
- STM32L476G-DISCO with USB OTG FS (host mode)
- USB mouse
- Addressable LED strip

## Dependencies
Relies on the CubeMX-generated USB Host + HID middleware, and project-provided
helpers: `setDot`, `spotUpdate`, `fixData`, the `colors[]` framebuffer, and the
`K*` color macros. This directory holds the application logic that ties them
together.

## Files
```
Core/Src/main.c   # USB host loop: read mouse -> move spot, cycle color on click
```
