#include "sponge_MASK.h"           
#include "sponge_PIX.h"

float heroX, heroY, heroSpeed= 1;

boolean isLevelDrawn;
boolean heroDir; 

int heroFrame;
int heroW;
int heroH;

int healthX = 100;
int healthY = 200;
int healthW = 60;
int healthH = 5;

Metro heroFrameTimer = Metro(250); // A prototype for a Metro timer

void initHero(){
  heroX=(20);
  heroY= (screenH/2+20);
  heroSpeed = 0.5;
  isLevelDrawn=false;
  heroDir=true;
  heroFrame=0;
  heroW=32;
  heroH=32;
}

void drawHero(){
 
  float nextX = heroX + (joystickBuffer[1] * heroSpeed);
  float nextY = heroY + (joystickBuffer[0] * heroSpeed);

  if(checkMove(curMode,nextX,nextY,heroW,heroH)==true){
    heroX=nextX;
    heroY=nextY;
  }
 

  if(joystickBuffer[1]==1){
   heroDir=true;
  }else if (joystickBuffer[1] == -1){
    heroDir=false;
  }

  if(joystickBuffer[1]==1 && heroDir == true){
    if(heroFrameTimer.check()){
      heroFrame=(heroFrame + 1)%3;
      heroFrame=heroFrame +1;
    }
    heroFrame=0;
  }
  if(joystickBuffer[1]==-1 && heroDir == false){
     if (heroFrameTimer.check()) {
      heroFrame = (heroFrame + 1) % 7;
      if (heroFrame < 5) {heroFrame = 5;}
    heroFrame=7;
  }
  }
  if(buttonBuffer[3]==1 && heroDir==true){
   heroFrame=3; 
  }
   if(buttonBuffer[3]==1 && heroDir==false){
    heroFrame=4;
      if (heroFrameTimer.check()) {
    heroFrame= (heroFrame-1)%4; 
   if (heroFrame<8){heroFrame=4;}
  }
  }



   tft.setClipRect(heroX-1, heroY-1, heroW+4, heroH+4);
   drawLevel(1);
   tft.drawRGBBitmap(heroX,heroY, sponge_PIX[heroFrame], sponge_MASK[heroFrame],heroW, heroH);
   tft.updateScreen();
   

}
