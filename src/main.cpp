#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define COLOR_VARIATION 4
#define CONTRAST_WIDTH 64

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
int LEDs=60;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDs, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
    strip.begin();
    strip.setBrightness(3);

    for(int x=0;x<LEDs;x++){
        strip.setPixelColor(x,255,0,0);
        strip.show();
        delay(20);
    }
    for(int x=0;x<LEDs;x++){
        strip.setPixelColor(x,0,255,0);
        strip.show();
        delay(20);
    }
    for(int x=0;x<LEDs;x++){
        strip.setPixelColor(x,0,0,255);
        strip.show();
        delay(20);
    }
    strip.show();

    for(int x=0;x<LEDs;x++){
        strip.setPixelColor(x,0,0,0);
    }
    strip.show();
}
void loop() {
    int previous, current = 0;
    for(int x=LEDs - 1; x >= 0; x--){
        strip.setPixelColor(previous,0,0,0);
        int i = random(0,LEDs);
        int g = random(0,255);
        int r = random(0,255);
        int b = random(0,255);
        strip.setPixelColor(i,g,r,b);
        strip.show();
        delay(150);
        previous = current;
        current = i;
    }
    for(int x=0;x<LEDs;x++){
    int g = random(0,255);
    int r = random(0,255);
    int b = random(0,255);
        strip.setPixelColor(x,g,r,b);
        strip.show();
        delay(25);
        strip.setPixelColor(x,0,0,0);
    }

    for(int x=LEDs - 1; x >= 0; x--){
    int g = random(0,255);
    int r = random(0,255);
    int b = random(0,255);
        strip.setPixelColor(x,g,r,b);
        strip.show();
        delay(25);
        strip.setPixelColor(x,0,0,0);
    }


    for(int x=LEDs - 1; x >= 0; x--){
        int i = random(0,LEDs);
        int g = random(0,255);
        int r = random(0,255);
        int b = random(0,255);
        strip.setPixelColor(i,g,r,b);
        strip.show();
        delay(75);
        strip.setPixelColor(i,0,0,0);
    }

    // strip.setPixelColor(11, 255, 0, 255);
    // uint32_t magenta = strip.Color(255, 0, 255);
    // strip.setPixelColor(7, magenta);
    // uint32_t greenishwhite = strip.Color(0, 64, 0, 64);
    // strip.show();
    // uint32_t color = strip.getPixelColor(11);
    // uint16_t n = strip.numPixels();
    // for(int x=0;x<LEDs;x++){
    //     strip.setPixelColor(x,255,255,255);
    //     strip.show();
    //     delay(50);
    // }
    // strip.show();

}
