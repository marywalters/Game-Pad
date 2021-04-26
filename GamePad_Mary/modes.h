#include "intro_PIX.h"
#include "over_PIX.h"

bool initIntro = false;
bool initLvl0 = false;
bool initLvl1 = false;
bool initLvl2 = false;
bool initLvl3 = false;
bool initLvl4 = false;
bool initLvl5 = false;
bool initLvl6 = false;
bool initOver = false;

void introScreen() {
 if(initIntro==false){
  tft.setClipRect(0,0,screenW, screenH);
  tft.drawRGBBitmap(0,0,intro_PIX[0],320,240); 
  tft.updateScreen();
  initIntro=true; 
}

  for (int i = 0; i < 4; i++) {
    if (buttonBuffer[i]) {
      curMode = 0;
    }
  }
}

void level0() {             
  if (!initLvl0) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    
    displayHearts(0);
    updateHead(0);
    
    enemyX = 30;
    enemyY = 30;
    enemyStatus = true;
    initLvl0 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

    if(score == 1){curMode = 1; initLvl0 = false;}

}

void level1() {             
  if (!initLvl1) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();
    
    displayHearts(1);
    updateHead(0);

    enemyX = 100;
    enemyY = 40;
    enemyStatus = true;
    initLvl1 = true;
  }
  //score = 0;
  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  if(score == 3){curMode = 2; initLvl1 = false;}
}

void level2() {             
  if (!initLvl2) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts(0);
    updateHead(0);

    enemyX = 150;
    enemyY = 30;
    enemyStatus = true;
    initLvl2 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  if(score == 5){curMode = 3; initLvl2 = false;}

}

void level3() {             //Level Three
  if (!initLvl3) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts(0);
    updateHead(0);
    enemyX = 30;
    enemyY = 30;
    enemyStatus = true;
    initLvl3 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();
  
  if(score == 7){curMode = 4; initLvl3 = false;}

}

void level4() {             
  if (!initLvl4) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts(0);
    updateHead(0);

    enemyX = 30;
    enemyY = 30;
    enemyStatus = true;
    initLvl4 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();
  
  if(score == 9){curMode = 5; initLvl4 = false;}
}

void level5() {             
  if (!initLvl5) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts(0);
    updateHead(0);

    enemyX = 35;
    enemyY = 35;
    enemyStatus = true;
    initLvl5 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();
  
  if(score == 11){curMode = 6; initLvl5 = false;}
}

void level6() {             
  if (!initLvl6) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(curMode);
    tft.updateScreen();

    displayHearts(0);
    updateHead(0);

    enemyX = 70;
    enemyY = 30;
    enemyStatus = true;
    initLvl6 = true;
  }

  drawLevel(curMode);
  drawEnemy();
  drawHero();
  fight();

  if(score == 13){curMode = 7; initLvl6 = false;}
}
void resetGame(){
  initIntro = false;
  initLvl0 = false;
  initLvl1 = false;
  initLvl2 = false;
  initLvl3 = false;
  initLvl4 = false;
  initLvl5 = false;
  initLvl6 = false;
  initOver = false;

  heroHealth = 3;
  heroX = 150;
  heroY = 120;

  heroSpeed = 0.5;
  score = 0;
 
  enemyHealth = 3;
  enemyType = 0;
}
void overScreen() {
 if(initOver){
  tft.setClipRect(0,0,screenW, screenH);
  tft.drawRGBBitmap(0,0,over_PIX[0],320,240); 
  tft.updateScreen();
}

  for (int i = 0; i < 4; i++) {
    if (buttonBuffer[i]) {
      
      curMode = -1;
      resetGame();
    }
  }
}



void runMode() {
 // Serial.println(curMode);
  switch (curMode) {
    case -1: introScreen(); break;
    case 0: level0(); break;
    case 1: level1(); break;
    case 2: level2(); break;
    case 3: level3(); break;
    case 4: level4(); break;
    case 5: level5(); break;
    case 6: level6(); break;
    case 7: overScreen(); break;

  }
  if(heroHealth < -700){initOver = true; curMode=7;}
}
