#include "enemy_MASK.h"
#include "enemy_PIX.h"
#include "giant_MASK.h"
#include "giant_PIX.h"

#define enemyW 32
#define enemyH 32
#define giantW 56
#define giantH 56

Metro enemyFrameTimer = Metro(100);
Metro enemyBrainTimer = Metro(1000);
Metro giantFrameTimer = Metro(100);
Metro giantBrainTimer = Metro(1000);

float enemyX = 0;
float enemyY = 0;

bool enemyStatus = true;
int enemyHealth = 3;

int enemyType = 0; 

float enemyXDir = 0;
float enemyYDir = 0;

int enemyFrame = 0; 

int enemySmart = 3;
float enemySpeed = 0.15;
//Giant
float giantX = 0;
float giantY = 0;

bool giantStatus = true;
int giantHealth = 15;

float giantXDir = 0;
float giantYDir = 0;

int giantFrame = 0; 

int giantSmart = 3;
float giantSpeed = 0.15;

void updateEnemyDir(){
  if(enemyBrainTimer.check()){
    int n = random(0, enemySmart);

    if(n == 0){
      enemyXDir = random(-1, 2);
      enemyYDir = random(-1, 2);
    } else {
      if(heroX < enemyX){ enemyXDir = -1;
      } else { enemyXDir = 1; }

      if(heroY < enemyX){ enemyYDir = -1;
      } else { enemyYDir = 1;  }
    }
  }
}
void updateGiantDir(){
  if(giantBrainTimer.check()){
    int n = random(0, giantSmart);

    if(n == 0){
      giantXDir = random(-1, 2);
      giantYDir = random(-1, 2);
    } else {
      if(heroX < giantX){ giantXDir = -1;
      } else { giantXDir = 1; }

      if(heroY < giantX){ giantYDir = -1;
      } else { giantYDir = 1;  }
    }
  }
}

void moveEnemy(){
  float nextX = enemyX + (enemyXDir * enemySpeed);
  float nextY = enemyY + (enemyYDir * enemySpeed);

  if(checkMove(curMode, nextX, nextY, enemyW, enemyH)){
    enemyX = nextX;
    enemyY = nextY;
  }
}
void moveGiant(){
  float nextGX = giantX + (giantXDir * giantSpeed);
  float nextGY = giantY + (giantYDir * giantSpeed);

  if(checkMove(curMode, nextGX, nextGY, giantW, giantH)){
    giantX = nextGX;
    giantY = nextGY;
  }
}


void animateEnemy(){
  if(enemyFrameTimer.check()){
     enemyFrame = 0 + ((enemyFrame + 1) % 4);
  }
}

void animateGiant(){
  if(giantFrameTimer.check()){
     giantFrame = 0 + ((giantFrame + 1) % 4);
  }
}

void animateSting(){
  if(enemyFrameTimer.check()){
     enemyFrame = 4 + ((enemyFrame + 1) % 6);
  }
}

void drawEnemy(){
  if(enemyStatus){
    updateEnemyDir();
    moveEnemy();
    animateEnemy();
      
    tft.setClipRect(enemyX - 2, enemyY - 2, enemyW + 4, enemyH + 4);
    drawLevel(curMode);
    tft.drawRGBBitmap(enemyX, enemyY, enemy_PIX[enemyFrame], enemy_MASK[enemyFrame], enemyW, enemyH);
    tft.updateScreen();
  }
}

void drawGiant(){
  if(giantStatus){
    updateGiantDir();
    moveGiant();
    animateGiant();
      
    tft.setClipRect(giantX - 2, giantY - 2, giantW + 4, giantH + 4);
    drawLevel(curMode);
    tft.drawRGBBitmap(giantX, giantY, giant_PIX[giantFrame], giant_MASK[giantFrame], giantW, giantH);
    tft.updateScreen();
  }
}
