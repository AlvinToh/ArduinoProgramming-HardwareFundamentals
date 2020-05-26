#include <Adafruit_NeoPixel.h>

const int data_pin = 6;
const int num_pixels = 5;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(num_pixels, data_pin, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once

  // Initialize NeoPixels
  pixels.begin();
}

void loop() {
    for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
      for(int i=0; i<pixels.numPixels(); i++) { // For each pixel in strip...
        int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
        pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
      }
      pixels.show();
      delay(20);
    }
}
