# OpenFly

OpenFly is hobby I started to create my own ALTIMETER for paragliding. It has hardware and software.

## Circuits

This is the hardware. It has plans for a PCB (printed circuit board). I created
the plan using [EasyEDA](https://easyeda.com/editor) which is a free online tool.

You can print your own using PCBWay, LCSC, JLCPCB, etc.  You just upload the Gerber file, pay a few dollars and wait 2 weeks.  Usually it is the same price
to print up to 10.

You will need these components

- Atmega32u4 3.3V ProMicro 8Mhz [link](https://www.amazon.com/dp/B0C5QWNHFS)
- BMP 390 barometer and temperature [link](https://www.amazon.com/dp/B08SQ7RCSV)
- GY-271 magnetic compass [link](https://www.amazon.com/dp/B0CFLPKTP1)
- Piezo buzzer 3V 12mm x 9.5mm  [link](https://www.amazon.com/dp/B0DHRWCP34)
- OLED 128x64, I2C (or IIC, top or side pins) [link](https://www.amazon.com/dp/B0C4S5TNXW)
- EC11 rotary encoder with switch [link](https://www.amazon.com/dp/B0C6Q67V97)
- 7mm mini momentary buttons (3 of them) [link](https://www.amazon.com/dp/B07YDHP3HS)
- Micro-B USB data cable [link](https://www.amazon.com/dp/B0BLJMCQVY)
- USB battery 5000mah or more [link](https://www.amazon.com/dp/B0FHQ9LPF2)
- Plastic box for playing cards (96x68x21mm) [link](https://www.amazon.com/dp/B09DYYZ2D8)

For each component, you should make sure the PINS match the schematic. however notice the OLED is reversed because it is mounted to the back of the PCB

You will also need the following tools

- soldering iron, and practice using it
- laptop, with VSCode installed, and Platformio extension.

## Schematic and PCB wire plan

![Schematic](Circuits/EasyEDA/Schematic_Altimeter1_2026-02-15.png)

![PCB wire layout](Circuits/EasyEDA/PCB-2026-02-15-160922.png)

## My first prototype, using perf board

![mockup-front](Circuits/EasyEDA/mockup-front.png)

![mockup-back](Circuits/EasyEDA/mockup-back.png)


## Arduino

This is all the code. Just plug in your promicro and use "Platformio - Upload".

TODO -- I'll finish this documentation later.