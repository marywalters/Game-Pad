// 
// Mary Walters || March 2021
// CRT 360 Advanced Prototyping || GamePad

#include <Metro.h>          // This adds the Metro library to your sketch
#include "frame.h"
#include "screen.h"



void setup() {
   Serial.begin(9600);
   initScreen();
}

void loop() {
    checkFrame();
    //screenTest();
}
