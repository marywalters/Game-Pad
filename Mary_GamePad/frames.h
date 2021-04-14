#include <Metro.h>          // This adds the Metro library to your sketch
Metro frameTimer = Metro(1000); // A prototype for a Metro timer
int frameRate;

void checkFrameRate(){
   frameRate++; 
  if(frameTimer.check( )){
    Serial.println(frameRate); 
    frameRate=0;
  }
}
