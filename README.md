# androidRebootSwitch

This is USB Switch to reboot Android device by ATtiny85 (DigiSpark).
You can reboot Android device by just pushing button

# Prepare

## DigiSpark (ATtiny85) board

* Tact SW
  * ATtiny 85's Pin2 -- 10k ohm resistor --- GND.

## Software

1. Install Aruduino IDE
2. Preference -> Adittional Boards Manager URLs
3. Set ```http://digistump.com/package_digistump_index.json``` for 2
4. Tool -> Board -> Board Manager
5. Install ```Digistump AVR Boards by Digistumpと``` from 4
6. Tool -> Board
7. Choose ```Digispark (Default - 16.5mhz)``` on 6
8. Flash ```androidRebootSwitch.ino```
