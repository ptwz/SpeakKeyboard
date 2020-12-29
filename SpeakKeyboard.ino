// Talkie library
// Copyright 2011 Peter Knight
// This code is released under GPLv2 license.

//
// Welcome to the Talkie library examples.
//
// Talkie is a speech synthesiser that works from a fixed vocabulary.
//
// There are hundreds of words in the 'Vocabulary' examples.
//

/**
 *  | | | |
 *  1 2 3 4
 * 
 * 1 Data
 * 2 IRQ
 * 3 GND
 * 4 5+V
 */

/*
 * Voice PWM output pins for different ATmegas:
 *  ATmega328 (Uno and Nano): non inverted at pin 3, inverted at pin 11.
 *  ATmega2560: non inverted at pin 6, inverted at pin 7.
 *  ATmega32U4 (Leonardo): non inverted at pin 10, inverted at pin 9.
 *  ATmega32U4 (CircuitPlaygound): only non inverted at pin 5.
 *
 *  As default both inverted and not inverted outputs are enabled to increase volume if speaker is attached between them.
 *  Use Talkie Voice(true, false); if you only need not inverted pin or if you want to use SPI on ATmega328 which needs pin 11.
 *
 *  The outputs can drive headphones directly, or add a simple audio amplifier to drive a loudspeaker.
 */
#include <Arduino.h>
   
#include <PS2Keyboard.h>
const int DataPin = 8;
const int IRQpin =  2;

PS2Keyboard keyboard;

#include "Talkie.h"
#include "male.h"

Talkie voice;

void setup() {
    delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
//    voice.doNotUseUseInvertedOutput();
#if defined(TEENSYDUINO)
    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH); //Enable Amplified PROP shield
#endif

    
}

void loop() {
    if (keyboard.available()) {
       
   
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    switch (c){
      case 'a':
        voice.say(burst_num001);
        break;
      case 'b':
        voice.say(burst_num002);
        break;
      case 'c':
        voice.say(burst_num003);
        break;
      case 'd':
        voice.say(burst_num004);
        break;
      case 'e':
        voice.say(burst_num005);
        break;
      case 'f':
        voice.say(burst_num006);
        break;
      case 'g':
        voice.say(burst_num007);
        break;
      case 'h':
        voice.say(burst_num008);
        break;
      case 'i':
        voice.say(burst_num009);
        break;
      case 'j':
        voice.say(burst_num010);
        break;
      case 'k':
        voice.say(burst_num011);
        break;
      case 'l':
        voice.say(burst_num012);
        break;
      case 'm':
        voice.say(burst_num013);
        break;
      case 'n':
        voice.say(burst_num014);
        break;
      case 'o':
        voice.say(burst_num015);
        break;
      case 'p':
        voice.say(burst_num016);
        break;
      case 'q':
        voice.say(burst_num017);
        break;
      case 'r':
        voice.say(burst_num018);
        break;
      case 's':
        voice.say(burst_num019);
        break;
      case 't':
        voice.say(burst_num020);
        break;
      case 'u':
        voice.say(burst_num021);
        break;
      case 'v':
        voice.say(burst_num022);
        break;
      case 'w':
        voice.say(burst_num023);
        break;
      case 'x':
        voice.say(burst_num024);
        break;
      case 'y':
        voice.say(burst_num025);
        break;
      case 'z':
        voice.say(burst_num026);
        break;

    }
    if (c == PS2_ENTER) {
      Serial.println();
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
    } else {
      
      // otherwise, just print all normal characters
      Serial.print(c);
    }
  }
}
