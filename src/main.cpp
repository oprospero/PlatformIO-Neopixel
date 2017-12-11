#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

#define DATA_PIN 6
const int numOfLeds=60;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numOfLeds, DATA_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
    strip.begin();

    //Insure we don't pull to much power.
    strip.setBrightness(3);

    // Turn led on one by one
    for(int x=0;x<numOfLeds;x++){
        strip.setPixelColor(x,255,0,0);
        strip.show();
        delay(20);
    }
    for(int x=0;x<numOfLeds;x++){
        strip.setPixelColor(x,0,255,0);
        strip.show();
        delay(20);
    }
    for(int x=0;x<numOfLeds;x++){
        strip.setPixelColor(x,0,0,255);
        strip.show();
        delay(20);
    }
    strip.show();

    for(int x=0;x<numOfLeds;x++){
        strip.setPixelColor(x,0,0,0);
    }
    strip.show();
}
void loop() {
    int previous, current = 0;
    for(int x=numOfLeds - 1; x >= 0; x--){
        strip.setPixelColor(previous,0,0,0);
        int i = random(0,numOfLeds);
        int g = random(0,255);
        int r = random(0,255);
        int b = random(0,255);
        strip.setPixelColor(i,g,r,b);
        strip.show();
        delay(150);
        previous = current;
        current = i;
    }
    for(int x=0;x<numOfLeds;x++){
        int g = random(0,255);
        int r = random(0,255);
        int b = random(0,255);
        strip.setPixelColor(x,g,r,b);
        strip.show();
        delay(25);
        strip.setPixelColor(x,0,0,0);
    }

    for(int x=numOfLeds - 1; x >= 0; x--){
        int g = random(0,255);
        int r = random(0,255);
        int b = random(0,255);
        strip.setPixelColor(x,g,r,b);
        strip.show();
        delay(25);
        strip.setPixelColor(x,0,0,0);
    }


    for(int x=numOfLeds - 1; x >= 0; x--){
        int i = random(0,numOfLeds);
        int g = random(0,255);
        int r = random(0,255);
        int b = random(0,255);
        strip.setPixelColor(i,g,r,b);
        strip.show();
        delay(75);
        strip.setPixelColor(i,0,0,0);
    }


}
