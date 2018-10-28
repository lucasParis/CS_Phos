project Phos
===

USB Serial Protocol for Led Controllers
---
There is one led controller per side of the led pilar.
Each controller is being streamed frames 60 times a second of the leds' brightness by USB serial.
The protocol for the serial transmition consists of a __start byte of 255__ followed by a __list of 3564 bytes of brightness values between 0 and 254__.
These brightness values correspond to each pixel of the strip in series. The strips are arranged in 9 colomns, each with 11 modules of 36pixels long -i.e. 396 leds per colomn.
The data is listed one colomn after the other, starting and the top of the left colomn and making it's way down and then to the next colomn.

Assembly
---
ribbon cables
power




TouchDesigner patch
---




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


PCB changes, version 2
---

BOMs
---
