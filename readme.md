Phos
===

USB Serial Protocol for Led Controllers
---
There is one led controller per side of the led pilar.
Each controller is being streamed frames 60 times a second of the leds' brightness by USB serial.
The protocol for the serial transmition consists of a __start byte of 255__ followed by a __list of 3564 bytes of brightness values between 0 and 254__.
These brightness values correspond to each pixel of the strip in series. The strips are arranged in 9 colomns, each with 11 modules of 36pixels long -i.e. 396 leds per colomn.
The data is listed one colomn after the other, starting and the top of the left colomn and making it's way down and then to the next colomn.
Serial baud is 2500000.

Arduino
---
- FastLED version 3.1.6
- Arduino 1.8.2
- Teensyloader 1.26


The best settings to avoid glitches in the apa102 data seems to be:
- teensy clock speed set to 144mhz
- fastled rate 3mhz

Serial baud is 2500000.

The _testCode_ firmware of prototype 2 loops 2 white leds through the strip.


Assembly
---
ribbon cables
power




TouchDesigner patch
---
### prototype 1
Test patch with internally generated patterns and UI to adjust patterns
### prototype 2
streaming patch, with syphon/spout input (to do).
- [ ] add syphon/spout input
- [ ] cleanup UI
- [ ] adapt test patterns from prototype 1
- [ ] add processing example code
- [ ] change total output for only 3 boxes, 1 side


Files
---
- prototype 1
  - Made in september 2018 for tests at the barbican
  - 1 box, 5 strips
- prototype 2
  - Made in October/November 2018
  - 3 boxes, 9 strips, 2 sides
  - custom pcbs version 1, with small changes needed
  - digikey BOMs


BOMs
---

#### BOM_leds_oneBoxSide_digikey

Bill of materials for 1 side of the box, includes power supply and connectors for 6 led breakout pcbs.
2 needed per box.


####  BOM_masterModule_digikey

Bill of materials for master module
