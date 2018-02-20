/**
 * @author     David Hickox
 * @license    This project is released under the CC by-nc-sa 4.0 license
 * @copyright  Copyright (c) 2017 David HIckox
 * @date       Jan 2017
 */

#include <FastLED.h>
#include "FastLED.h"

// Fixed definitions cannot change on the fly.
#define LED_DT 8                                              // Data pin to connect to the strip.
#define LED_CK 11                                             // Clock pin for WS2801 or APA102.
#define COLOR_ORDER BRG                                       // It's GRB for WS2812 and BGR for APA102.
#define LED_TYPE WS2812                                       // Using APA102, WS2812, WS2801. Don't forget to change LEDS.addLeds.
#define NUM_LEDS 50                                           // Number of LED's.
int j = 0;
int k = 0;
uint32_t colour = CRGB::Green;
int test = 2;
int style = 0;
uint8_t max_bright = 30;
char letter = ' ';
char letter1 = ' ';
char letter2 = ' ';
int stylesave = 0;

struct CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  delay(1000);                                                // Power-up safety delay.
  Serial.begin(57600);                                        // Initialize serial port for debugging.

  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // Use this for WS2812
  //  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // Use this for WS2812
  //  LEDS.addLeds<LED_TYPE, LED_DT, LED_CK, COLOR_ORDER>(leds, NUM_LEDS);  // Use this for WS2801 or APA102

  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, 500);               // FastLED Power management set at 5V, 500mA.

  Serial.println("made it through setup");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    if (letter == ' ') {
      Serial.println("serial was deamed avialable for letter");
      letter = Serial.read();
      Serial.println(letter);
      putchar (tolower(letter));
    }
  }
  if (letter == 'c')
  {
    /*set colour
       y = yellow
       b = blue
       r = red
       g = green
       l = lime green
       p = purple
       o = orange
       w = white
       n = brown
       k = black
    */
    colorpick();
  }
  else if (letter == 's')
  {
    /*set style
       s = solid
       t = twinkle
       r = rainbow (disregards colour)
       f = Firework
    */
    stylepick();
  }
  else if (letter == '2')
  {
    //used to disable test
    test = 2;
    letter = ' ';
  }
  else if (letter == '1')
  {
    //on for test
    test = 1;
    letter = ' ';
  }
  else if (letter == '0')
  {
    //off for test
    test = 0;
    letter = ' ';
  }
  if (style == 1)
  {
    solid();
  }
  else if (style == 2)
  {
    //twinkle()
  }
  else if (style == 3)
  {
    //rainbow()
  }
  else if (style == 4)
  {
    //firework()
  }
  if (test == 1)
  {
    teston();
  }
  if (test == 0)
  {
    testoff();
  }
}

void solid() {
  while (j <= 50 && j >= 0) {
    leds[j] = colour;
    j ++;
  }
  FastLED.show();
  j = 0;
  style = 0;
}

void twinkle() {
  Serial.println("here is where i would put my twinkle, if i had one");
}

void rainbow() {
  Serial.println("here is where i would put my rainbow, if i had one");
}

void firework() {
  Serial.println("here is where i would put my firework, if i had one");
}

void teston() {
  while (j <= 50 && j >= 0) {
    leds[j] = CRGB::White;
    Serial.println("teston");
    Serial.println(j);
    j ++;
  }
  FastLED.show();
  j = 0;
  test = 2;
}

void testoff() {
  while (k <= 50 && k >= 0) {
    leds[k] = CRGB::Black;
    Serial.println("testoff");
    Serial.println(k);
    k ++;
  }
  FastLED.show();
  k = 0;
  test = 2;
}

void colorpick() {
  if (Serial.available() > 0)
  {
    Serial.println("serial was deamed avialable for letter1");
    letter1 = Serial.read();
    putchar (tolower(letter1));
    Serial.println(letter1);
    if (letter1 == 'w')
    {
      colour = CRGB::White;
      Serial.println("Colour changed to White");
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'b')
    {
      colour = CRGB::Blue;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'y')
    {
      colour = CRGB::Yellow;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'r')
    {
      colour = CRGB::Red;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'g')
    {
      colour = CRGB::Green;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'l')
    {
      colour = CRGB::LimeGreen;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'p')
    {
      colour = CRGB::Purple;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'o')
    {
      colour = CRGB::Orange;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'k')
    {
      colour = CRGB::Black;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'n')
    {
      colour = CRGB::Brown;
      if (stylesave > 0)
      {
        style = stylesave;
      }
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == '|')
    {
      // this is used to extend the program colour selection past 1 diget
      letter2 = Serial.read();
      putchar (tolower(letter2));
      Serial.println("colour succesfully extended past one diget");
      letter = ' '; //if this is to be used these will have to be moved into the options to be cleared or the serial delay will cause them to be cleared before the operation is actualy complete
      letter1 = ' ';
    }
  }
  else
  {
    Serial.println("please choose a color");
  }
}

void stylepick() {
  if (Serial.available() > 0)
  {
    Serial.println("serial was deamed avialable for letter1");
    letter1 = Serial.read();
    putchar (tolower(letter1));
    Serial.println(letter1);
    if (letter1 == 's')
    {
      style = 1;
      stylesave = 1;
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 't')
    {
      style = 2;
      stylesave = 2;
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'r')
    {
      style = 3;
      stylesave = 3;
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'f')
    {
      style = 4;
      stylesave = 4;
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == 'o')
    {
      style = 0;
      stylesave = 0;
      letter = ' ';
      letter1 = ' ';
    }
    else if (letter1 == '|')
    {
      // this is used to extend the program colour selection past 1 diget
      letter2 = Serial.read();
      putchar (tolower(letter2));
      Serial.println("style succesfully extended past one diget");
      letter = ' '; //if this is to be used these will have to be moved into the options to be cleared or the serial delay will cause them to be cleared before the operation is actualy complete
      letter1 = ' ';
    }
  }
  else
  {
    Serial.println("please choose a color");
  }
}

