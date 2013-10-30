# Animated Pumpkin

### Description

This Arduino sketch utilizes three 8x8 LED Matrixes to serve as the eyes and mouth of an LED animated Jack O'Lantern.  Stores various eye and mouth sprites in PROGMEM, and cycles through them.  The LED Matrixes are each connected to a LinkSprite LED Matrix Kit via a Serial Interface, and are daisy-chained together.

### Pinout

    LED Board       Arduino
    ---------       -------
    VCC             5V or VIN
    GND             GND
    DIN             PIN 11
    CS              PIN 10
    CLK             PIN 13

### Parts

* Arduino Pro Mini 328 - 5V/15MHz (https://www.sparkfun.com/products/11113)  
* 3 x LinkSprite MAX7219 8x8 Red Dot LED Matrix Kit (http://store.linksprite.com/max7219-8x8-red-dot-led-matrix-kit/)  
* 3 x 5-pin 0.1" Jumper Wire similar to https://www.sparkfun.com/products/10365 (length will vary based on need)  
* 1 x 4xAA Battery Holder similar to https://www.sparkfun.com/products/552  
* 1 x Foam Pumpkin  