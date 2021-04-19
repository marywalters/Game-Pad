//
// Mary Walters || March 2021
// CRT 360 Advanced Prototyping || GamePad
int curMode = -1;

#include "frames.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "status.h"
#include "interaction.h"
#include "hero.h"
#include "enemy.h"
#include "fight.h"
#include "modes.h"

void setup() {
  Serial.begin(9600);
initScreen();
initControls();
initHero();
initNeighbors();
//randomSeed =(analogRead(8));

}

void loop() {
checkFrameRate();
getControls();
runMode();
//updateHead(0);
//drawEnemy();
Serial.println(heroX);
tft.updateScreen();
}
