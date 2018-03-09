// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "particle.h"

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      48

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  Serial.begin(115200);
  Serial.setTimeout(2147483646); //infinte timeout

  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {

  char frame_chars[NUMPIXELS*4+10] = {'\0'};
  String frameString;
  String parsedVal = String();
  boolean done = false;
  unsigned int led_idx = 0;

  int startIdx = 0;
  int endIdx = 0;

  int r;
  int g;
  int b;

  Serial.readBytesUntil('\n', frame_chars, NUMPIXELS*4+10);
  frameString = String(frame_chars);

  //Clear whole strip
  for(int i=0;i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); // Dark
  }
  
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one
  for(int i=0;i<NUMPIXELS && done == false;i++){

    //get R
    startIdx = endIdx;
    endIdx = frameString.indexOf(',', startIdx+1);


    if(startIdx < endIdx){
      parsedVal = frameString.substring(startIdx, endIdx);
      r = parsedVal.toInt();
    } else {
      done = true;
      break;
    }

    endIdx++;

    //get g
    startIdx = endIdx;
    endIdx = frameString.indexOf(',', startIdx+1);

    if(startIdx < endIdx){
      parsedVal = frameString.substring(startIdx, endIdx);
      g = parsedVal.toInt();
    } else {
      done = true;
      break;
    }

    endIdx++;

    
    //get b
    startIdx = endIdx;
    endIdx = frameString.indexOf(',', startIdx+1);

    if(startIdx < endIdx){
      parsedVal = frameString.substring(startIdx, endIdx);
      b = parsedVal.toInt();
    } else {
      done = true;
      break;
    }


    endIdx++;
    
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(r,g,b)); // Moderately bright green color.

  }

  pixels.show(); // This sends the updated pixel color to the hardware.

}
