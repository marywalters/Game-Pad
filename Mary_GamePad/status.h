#include "head_MASK.h"           
#include "head_PIX.h"
boolean statusDrawn = false;

  void updateHead(int headStatus){
    tft.setClipRect(headW,headH, 88,88);
  tft.drawRGBBitmap(8, 200, head_PIX[headStatus], 88, 88);
  tft.updateScreen();
}

void statusBar(int statusX, int statusY, int statusW, int statusH){

  if(statusDrawn == false){
  tft.drawRect(statusX, statusY, statusW, statusH, 0x0000FF);
  tft.fillRect(statusX, statusY, statusW, statusH, 0x0000FF);
  tft.updateScreen();
  } 

  statusDrawn = true;
}
