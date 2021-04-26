int score = 0;
int giantScore = 0;

// Check to See if Hero & Enemies Collide
boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH){
  boolean canMove = true;                                // Assume a move can be made
  boolean xMin = false; if(hX < eX + eW){xMin = true;}    // Does the xMin collide?
  boolean xMax = false; if(hX + hW > eX){xMax = true;}    // Does the xMax collide?
  boolean yMin = false; if(hY < eY + eH){yMin = true;}    // Does the yMin collide?
  boolean yMax = false; if(hY + hH > eY){yMax = true;}    // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canMove = false;}
  return canMove;
}

void fight(){
  bool canFight = checkCollide(heroX, heroY, heroW, heroH, enemyX, enemyY, enemyW,enemyH);

  Serial.println(heroHealth);
  
  if(canFight){
    if(buttonBuffer[2] == 1){
        enemyHealth -= 1;
        updateHead(1);

      if(enemyHealth <= 0){
        score++;
        enemyStatus = false;
        tft.setClipRect(enemyX - 2, enemyY - 2, enemyW + 4, enemyH + 4);
        drawLevel(curMode);
        tft.updateScreen();

        enemyX = 0;
        enemyY = 0;
      }
    }
  }
  else if (checkCollide && !canFight){animateSting(); heroHealth--;updateHead(2);}
}

// Check to See if Hero & Enemies Collide
boolean checkCollideGiant(int hX, int hY, int hW, int hH, int gX, int gY, int gW, int gH){
  boolean canMoveGiant = true;                                // Assume a move can be made
  boolean xMin = false; if(hX < gX + gW){xMin = true;}    // Does the xMin collide?
  boolean xMax = false; if(hX + hW > gX){xMax = true;}    // Does the xMax collide?
  boolean yMin = false; if(hY < gY + gH){yMin = true;}    // Does the yMin collide?
  boolean yMax = false; if(hY + hH > gY){yMax = true;}    // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canMoveGiant = false;}
  return canMoveGiant;
}

void fightGiant(){
  bool canFightGiant = checkCollideGiant(heroX, heroY, heroW, heroH, giantX, giantY, giantW,giantH);

  Serial.println(enemyHealth);
  
  if(canFightGiant){
    if(buttonBuffer[2] == 1){
        giantHealth -= 1;
        updateHead(1);

      if(enemyHealth <= 0){
//score++;
        giantStatus = false;
        tft.setClipRect(giantX - 2, giantY - 2, giantW + 4, giantH + 4);
        drawLevel(curMode);
        tft.updateScreen();
      }
    }
  }
  else if (checkCollideGiant && !canFightGiant){heroHealth--;updateHead(2);
       drawLevel(curMode);
       tft.updateScreen();}
}
