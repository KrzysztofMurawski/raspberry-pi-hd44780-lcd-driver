# Simple API for HD44780 LCD 
This driver uses 4-bit parallel interface to communicate with the display. It provides easy to use instructions (put_text, lcd_clear) and simple setup manual.
Here are some usefull resources and datasheets related to the LMB162A / HD44780 display:
  - https://www.futurlec.com/LED/LCD16X2BLa.shtml
  - https://www.alldatasheet.net/datasheet-pdf/view/1132024/TOPWAY/LMB162A.html
    
## Hardware used
  - Raspberry Pi 4B
  - LMB162A display

## Connections


| LMB162A pin | RPi GPIO |
|-------------|---------|
| Vss | GND |
| V0 | between Vss and Vdd via potentiometer |
| Vdd | 5V |
| E | 22 |
| RW | 27 (optional) |
| RS | 17 |
| DB4 | 13 |
| DB5 | 6 |
| DB6 | 5 |
| DB7 | 16 |

# Usage
All the nececssary functions are located in the include/lcd.h file. There is a simple test (main.c) file provided that can be compiled using CMake
