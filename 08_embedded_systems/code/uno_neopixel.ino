
#include <Adafruit_NeoPixel.h>

/*
  WS2818 Neopixels
  These run with +5V and GND connected to the Power supply for the nessary
  current driver.  Only the Data lead is required to be connected to the 
  microcontroller

  Library:  Adafruit Neopixel
  Author:   Adafruit
  Example:  Adafruit - Arduino Library Use (https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use)
*/

const int LED_PIN = 8;      // Pin where Neopixel Data is connected
const int LED_COUNT = 8;    // Number of LEDs in strip

// assign the neopixel object -> strip
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();    // initialize the strip
  strip.show();     // send to the strip, the strip will not work without this command
}

void loop()
{
  // run the lights
  for (int i = 0; i < LED_COUNT; ++i)
  {
    strip.setPixelColor(i, 0, 32, 0);       // green
    strip.show();
    delay(200);
    strip.setPixelColor(i, 0, 0, 32);       // BLUE
    strip.show();
  }

  // fill all the lights with R-G-B (0x00~0xFF for intensity)
  strip.fill(0x4f0000,0,8);     // RED 1/4 intensity
  strip.show();
  delay(1000);
  strip.fill(0x004f00, 0, 8);   // GREEN 1/4 intensity
  strip.show();
  delay(1000);
  strip.clear();                // clear
  delay(1000);

  
  strip.setBrightness(64);      // set max brightness
  strip.show();
  // cycle the colors using Hue (Sat and Value kept constant)
  // cycles from RED to RED
  for (uint32_t i=0; i < 65536; i=i+16){
    uint32_t rgbcolor = strip.ColorHSV(i);
    strip.fill(rgbcolor);
    strip.show();
    delay(5);
  }

  // blank out all LEDs
  strip.fill(0x000000, 0, 8);
  delay(1000);

  // change brightness of the centre 3 LEDs
  for (int i = 0; i < 255; ++i)
  {
    uint32_t color = strip.Color(i, i, i);
    strip.fill(color, 2, 3);
    strip.show();
    delay(50);
  }

}