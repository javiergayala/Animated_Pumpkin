/*
    Animated Pumpkin

    A series of eye and mouth animations to facilitate the creation of an
    animated pumpkin or Jack O'Lantern

    The circuit:
    * Arduino Pro Mini 328 - 5V/15MHz (https://www.sparkfun.com/products/11113)
    * 3 x LinkSprite MAX7219 8x8 Red Dot LED Matrix Kit (http://store.linksprite.com/max7219-8x8-red-dot-led-matrix-kit/)
    * 3 x 5-pin 0.1" Jumper Wire similar to https://www.sparkfun.com/products/10365 (length will vary based on need)
    * 4xAA Battery Holder similar to https://www.sparkfun.com/products/552
    * 1 x Foam Pumpkin

    Created 25 October 2013
    By Javier Ayala

*/

#include <avr/pgmspace.h>
#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Max72xxPanel.h"
#include "eyes.h"
#include "mouths.h"

#define lEye 0       // Left Eye Cursor Location
#define rEye 16      // Right Eye Cursor Locaiton
#define mouth 8      // Mouth Cursor Location
#define pinCS 10     // Attach CS to this pin, DIN to MOSI (11) and CLK to SCK (13) (cf http://arduino.cc/en/Reference/SPI )
#define hDisplays 3  // Number of horizontal displays in the LED Matrix
#define vDisplays 1  // Number of vertical displays in the LED Matrix
#define numLoops 20  // Number of times to loop each animation before moving on to the next
#define brightness 3 // LED Brightness Value (0=dimmest, 15=brightest)

long previousMillis = 0;         // Placeholder variable for the last time the animation was started
long interval = 80;              // milliseconds between animation frames
int loopCounter[] = {0, 0};      // Loop Counter array for the {eye, mouth}
int frame[] = {0, 0};            //Array to hold anim current frame.  1st is Eyes, 2nd is Mouth
int animDirection[] = {-1, -1};  // Array to hold anim direction. 1st is Eyes, 2nd is Mouth
int eyeChoice = 0;               // Which eye animation we are on
int mouthChoice = 0;             // Which mouth animatino we are on

Max72xxPanel matrix = Max72xxPanel(pinCS, hDisplays, vDisplays); // Initialize the matrices

void setup() {
    matrix.setIntensity(brightness); // Value is set using the "brightness" definition
    // Set the orientation for the eye and mouth matrices
    matrix.setRotation(0, 0);
    matrix.setRotation(1, 2);
    matrix.setRotation(2, 0);
}

void loop() {
    unsigned long currentMillis = millis();
    // Initialize the array to hold how long each animation is. First array value is Eyes, second is Mouth
    int animLength[] = {0, 0};
    if (currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;  // Save the last time we ran a new animation
        matrix.fillScreen(LOW);  // Blank out the matrices
        // Determine which eye/mouth we need to use, then use drawBitmap to draw the matrices
        switch (eyeChoice) {
            case 0:
                // Determine how long the animation is. First array value is Eyes, second is Mouth
                animLength[0] = sizeof(evil_eye_anim) / 2 - 1;
                matrix.drawBitmap(lEye, 0, (uint8_t*)pgm_read_word(&(evil_eye_anim[frame[0]])), 8, 8, HIGH);
                matrix.drawBitmap(rEye, 0, (uint8_t*)pgm_read_word(&(evil_eye_anim[frame[0]])), 8, 8, HIGH);
                break;
            case 1:
                // Determine how long the animation is. First array value is Eyes, second is Mouth
                animLength[0] = sizeof(circle_eye_anim) / 2 - 1;
                matrix.drawBitmap(lEye, 0, (uint8_t*)pgm_read_word(&(circle_eye_anim[frame[0]])), 8, 8, HIGH);
                matrix.drawBitmap(rEye, 0, (uint8_t*)pgm_read_word(&(circle_eye_anim[frame[0]])), 8, 8, HIGH);
                break;
        }
        switch (mouthChoice) {
            case 0:
                // Determine how long the animation is. First array value is Eyes, second is Mouth
                animLength[1] = sizeof(chomp_anim) / 2 - 1;
                matrix.drawBitmap(mouth, 0, (uint8_t*)pgm_read_word(&(chomp_anim[frame[1]])), 8, 8, HIGH);
                break;
            case 1:
                animLength[1] = sizeof(evilgrin_anim) / 2 - 1;
                matrix.drawBitmap(mouth, 0, (uint8_t*)pgm_read_word(&(evilgrin_anim[frame[1]])), 8, 8, HIGH);
                break;
            case 2:
                animLength[1] = sizeof(beak_anim) / 2 - 1;
                matrix.drawBitmap(mouth, 0, (uint8_t*)pgm_read_word(&(beak_anim[frame[1]])), 8, 8, HIGH);
                break;
        }
        matrix.write();  // Activate the bitmap that was drawn on each matrix
        // Below for/if loops are to facilitate the loops and making sure that the counters for the frames stay within
        // proper numeric ranges
        for (int i=0; i < 2; i++) {
            if (frame[i] == animLength[i] || frame[i] == 0) {
                animDirection[i] *= -1;
                loopCounter[i]++;
            }
            frame[i] += animDirection[i];
        }
        if (loopCounter[0] == numLoops) {
            loopCounter[0] = 0;
            frame[0] = 0;
            if (eyeChoice == 0) {
                eyeChoice = 1;
            } else {
                eyeChoice = 0;
            }
        }
        if (loopCounter[1] == numLoops) {
            loopCounter[1] = 0;
            frame[1] = 0;
            if (mouthChoice == 0) {
                mouthChoice = 1;
            } else if (mouthChoice == 1) {
                mouthChoice = 2;
            } else {
                mouthChoice = 0;
            }
        }
    }
}
