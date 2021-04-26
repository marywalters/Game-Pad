#include "sponge_MASK.h"
#include "sponge_PIX.h"

#define heroW 32
#define heroH 32

float heroX = 150;
float heroY = 120;

float heroSpeed = .5;
int heroDir;
int heroFrame = 0;
Metro heroFrameTimer = Metro(100);

Metro positionPrintTimer = Metro(50);

bool heroMove = false;

int heroHealth = 3;

void moveHero() {
  float nextX = heroX + (heroSpeed * float(joystickBuffer[0]));
  float nextY = heroY + (heroSpeed * float(joystickBuffer[1]));

  if(checkMove(curMode, nextX, nextY, heroW, heroH)){
    heroX = nextX;
    heroY = nextY;
  }

  if (joystickBuffer[0] == 0 && joystickBuffer[1] == 0) {
    heroMove = false;
  }
  else {
    heroMove = true;
  }
  //tracks which way the character is moving
  if (joystickBuffer[0] == -1) {
    heroDir = false;
  }
  if (joystickBuffer[0] == 1) {
    heroDir = true;
  }
}

void animateHero(){
  if(heroFrameTimer.check()){

heroFrame++;

    //is the joystick being touched?
    if (heroMove) {

      //moving right animation
      if (heroDir) {
        if (heroFrame > 7 || heroFrame < 1) {
          heroFrame = 1;
        }

      }
      //moving left animation
      else {
        if (heroFrame > 20 || heroFrame < 16) {
          heroFrame = 16;
        }

      }
    
        if (buttonBuffer[2] == 1) {
          if(heroDir){heroFrame = 13;}
            else if (!heroDir){heroFrame = 10; }}
    }
    //Standng Still Animation
    else {
      if (heroFrame > 1) {
        heroFrame = 0;
      }
    }
      
  }
}

void drawHero() {
  moveHero();
  animateHero();
  
  tft.setClipRect(heroX - 2, heroY - 2, heroW + 4, heroH + 4);
  tft.drawRGBBitmap(heroX, heroY, sponge_PIX[heroFrame], sponge_MASK[heroFrame], heroW, heroH);

//  if (positionPrintTimer.check()) {
//    Serial.print(heroX);
//    Serial.print("\t");
//    Serial.print(heroY);
//    Serial.println();
//  }
}
