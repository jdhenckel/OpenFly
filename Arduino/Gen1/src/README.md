
## memory


If you run out of memory you can run this...

    c:\users\jdhen\.platformio\packages\toolchain-atmelavr\bin\avr-nm --size-sort -C .pio\build\leonardo\firmware.elf

and the LARGEST offenders will be at the bottom of the list.