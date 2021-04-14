#include "intro_PIX.h"

 int initIntro;
 boolean isFirstLevel,isSecondLevel,isThirdLevel,isFourthLevel,isFifthLevel,isSixthLevel;

void initModes(){
  initIntro=false;
  isFirstLevel=false;
  isSecondLevel = false;
  isThirdLevel = false;
  isFourthLevel = false; 
  isFifthLevel = false;
  isSixthLevel = false;
}


 void introScreen(){
 if(initIntro==false){
  tft.setClipRect(0,0,screenW, screenH);
  tft.drawRGBBitmap(0,0,intro_PIX[0],320,240); 
  tft.updateScreen();
  initIntro=true; 
}
if(buttonBuffer[0]==1){curMode=0;}

 }
 

void firstLevel(){
 if(isFirstLevel==false){
  tft.setClipRect(0,0,screenW, screenH);
   drawLevel(0);
 tft.updateScreen();
 isFirstLevel=true;
  updateHead(0);
  statusBar(healthX, healthY, healthW, healthH);
 }
 drawHero();
 drawEnemy();
  //drawLevel(0);

  
  


if(interaction[curMode][curTile] == 0x02 && buttonBuffer[1]==1){curMode = 1; isFirstLevel = false; heroX=10; heroY=120;}

}






void secondLevel(){
 if(isSecondLevel==false){
  tft.setClipRect(0,0,screenW, screenH);
   drawLevel(1);
 tft.updateScreen();
 isSecondLevel=true;
 }
 drawLevel(1);
 drawHero(); 
 
if(interaction[curMode][curTile] == 0x09 && buttonBuffer[1]==1){curMode =2; isSecondLevel = false; heroX=150; heroY=160;}
if(interaction[curMode][curTile] == 0x03 && buttonBuffer[1]==1){curMode = 4; isSecondLevel = false; heroX=160; heroY=120;}
}



void thirdLevel(){
 if(isThirdLevel==false){
 tft.setClipRect(0,0,screenW, screenH);
 drawLevel(2);
 tft.updateScreen();
 isThirdLevel=true;
 }
 drawLevel(2);
 drawHero(); 
if(interaction[curMode][curTile] == 0x07 && buttonBuffer[1]==1){curMode = 1; isThirdLevel = false; heroX=160; heroY=120;}
if(interaction[curMode][curTile] == 0x1A && buttonBuffer[1]==1){curMode = 5; isThirdLevel = false; heroX=160; heroY=120;}
}



void fourthLevel(){
 if(isFourthLevel==false){
  tft.setClipRect(0,0,screenW, screenH);
   drawLevel(3);
 tft.updateScreen();
 isFourthLevel=true;
 }
 drawLevel(3);
 drawHero(); 
 if(interaction[curMode][curTile] == 0x06 && buttonBuffer[1]==1){curMode = 1; isFourthLevel = false; heroX=10; heroY=120;}
}



void fifthLevel(){
 if(isFifthLevel==false){
  tft.setClipRect(0,0,screenW, screenH);
   drawLevel(4);
 tft.updateScreen();
 isFifthLevel=true;
 }
 drawLevel(4);
 drawHero(); 
 if(interaction[curMode][curTile] == 0x02 && buttonBuffer[1]==1){curMode = 1; isFifthLevel = false; heroX=10; heroY=120;}

}


void sixthLevel(){
 if(isSixthLevel==false){
  tft.setClipRect(0,0,screenW, screenH);
   drawLevel(5);
 tft.updateScreen();
 isSixthLevel=true;
 }
 drawLevel(5);
 drawHero(); 
isFirstLevel=false;
}


    
void runMode(){
 switch(curMode){
 case -1: introScreen(); break;
 case 0: firstLevel( ); break;
 case 1: secondLevel( ); break;
 case 2: thirdLevel( ); break;
 case 3: fourthLevel( ); break;
 case 4: fifthLevel( ); break; 
 case 5: sixthLevel ( ); break; 
 
}
}
