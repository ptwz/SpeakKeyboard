// Talkie library
// Copyright 2011 Peter Knight
// This code is released under GPLv2 license.

/**
    | | | |
    1 2 3 4

   1 Data
   2 IRQ
   3 GND
   4 5+V
*/

/*
   Voice PWM output pins for different ATmegas:
    ATmega328 (Uno and Nano): non inverted at pin 3, inverted at pin 11.
    ATmega2560: non inverted at pin 6, inverted at pin 7.
    ATmega32U4 (Leonardo): non inverted at pin 10, inverted at pin 9.
    ATmega32U4 (CircuitPlaygound): only non inverted at pin 5.

    As default both inverted and not inverted outputs are enabled to increase volume if speaker is attached between them.
    Use Talkie Voice(true, false); if you only need not inverted pin or if you want to use SPI on ATmega328 which needs pin 11.

    The outputs can drive headphones directly, or add a simple audio amplifier to drive a loudspeaker.
*/
#include <Arduino.h>
#include <SD.h>
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library.

#include <PS2Keyboard.h>
const int DataPin = 8;
const int IRQpin =  2;


PS2Keyboard keyboard;

#include "male.h"
#include "female.h"

TMRpcm tmrpcm;   // create an object for use in this sketch

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin, PS2Keymap_German);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;   // don't do anything more if not
  }

}

void loop() {
  static char temp[20];
  if (keyboard.available()) {
    memset(temp, 0, sizeof(temp));

    // read the next key
    unsigned char c = keyboard.read();

    // Upper and lower case chars are treated especially
    if ((c >= 'a') && (c <= 'z')) {
      snprintf(temp, 19, "male_%c.wav", c);
    } else if ((c >= 'A') && (c <= 'Z')) {
      snprintf(temp, 19, "female_%c.wav", c);
    } else if ( (c >= PS2_F1) && (c <= PS2_F12) ) {
      snprintf(temp, 19, "piano_%d.wav", c - PS2_F1 + 1);
    } else if (c == PS2_o_DIAERESIS){
      snprintf(temp, 19, "male_oe.wav");
    } else if (c == PS2_u_DIAERESIS){
      snprintf(temp, 19, "male_ue.wav");
    } else if (c == PS2_a_DIAERESIS){
      snprintf(temp, 19, "male_ae.wav");
    } else if (c == PS2_PAGEDOWN) {
      tmrpcm.volume(0);
    } else if (c == PS2_PAGEUP) {
      tmrpcm.volume(1);
    } else if ( (c > 32) && (c < 128) ) {
      // otherwise, just try to say the characters
      snprintf(temp, 19, "male_%c.wav", c);
      Serial.println(temp);
    }
    if (strlen(temp) > 0) {
      Serial.println(temp);
      tmrpcm.play(temp);
    }
  }
}
