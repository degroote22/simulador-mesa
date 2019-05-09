// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN 4

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 144

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup()
{
    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined(__AVR_ATtiny85__)
    if (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);
#endif
    // End of trinket special code

    pixels.begin(); // This initializes the NeoPixel library.
}

int decode(int i, int j)
{
    int column = i * 12;
    int row = i % 2 == 0 ? j : 11 - j;
    return column + row;
}

void light(int i, int j, int r, int g, int b)
{
    int n = decode(i, j);
    pixels.setPixelColor(n, pixels.Color(r, g, b)); // Moderately bright green color.
    pixels.show();                                  // This sends the updated pixel color to the hardware.
    delay(16);
}

void reset()
{
    for (int i = 0; i < 12 * 12; i++)
    {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
}

// custom code
// #include "custom.c"

#define _MAX 12
#define STEP 15

int max = _MAX;
int step = 0;
int i = 0;
int r = 50;
int g = 50;
int b = 50;

void loop_colors()
{
    if (g < 240)
    {
        g++;
    }
}

void _light(int i, int j)
{
    loop_colors();
    light(i, j, r, g, b);
}

void effect1()
{
    if (max == 0)
    {
        reset();
        max = _MAX;
        step = 0;
        i = 0;
        r = 50;
        g = 50;
        b = 50;
    }
    // down
    if (step == 0)
    {
        if (i < max)
        {
            _light(i, _MAX - max);
            i++;
        }
        else
        {
            i = 1;
            step = (step + 1) % 4;
        }
    }

    // right
    if (step == 1)
    {

        if (i < max - (_MAX - max))
        {
            _light(max - 1, i + (_MAX - max));
            i++;
        }
        else
        {
            i = 1;
            step = (step + 1) % 4;
        }
    }

    if (step == 2)
    {

        if (i < max - (_MAX - max))
        {
            _light(max - i - 1, max - 1);
            i++;
        }
        else
        {
            i = 1;
            step = (step + 1) % 4;
        }
    }

    if (step == 3)
    {

        if (i < max - (_MAX - max) - 1)
        {
            _light(_MAX - max, max - 1 - i);
            i++;
        }
        else
        {

            max = max - 1;
            i = (_MAX - max);
            step = (step + 1) % 4;
        }
    }
}

void loop()
{
    effect1();
}