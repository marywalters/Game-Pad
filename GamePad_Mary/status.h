#include "hearts_MASK.h"
#include "hearts_PIX.h"
#include "head_MASK.h"           
#include "head_PIX.h"
int heartStartX = 20;
int heartDisplayBuffer = 2; 

  void updateHead(int headStatus){
  tft.setClipRect(198,190, 78,64);
  tft.drawRGBBitmap(200, 192, head_PIX[headStatus], headW, headH);
  tft.updateScreen();
}

void displayHearts(int pHealth) {
  tft.setClipRect(heartStartX, screenH - 35, heartStartX + (hearts_W*2) + (heartDisplayBuffer*2), hearts_H);
  tft.drawRGBBitmap(heartStartX, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
  tft.drawRGBBitmap(heartStartX + hearts_W + heartDisplayBuffer, screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
  tft.drawRGBBitmap(heartStartX + (hearts_W*2) + (heartDisplayBuffer*2), screenH - 35, hearts_PIX[0], hearts_MASK[0], hearts_W, hearts_H);
  tft.updateScreen();
}
