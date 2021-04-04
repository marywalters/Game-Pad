int frame = 0;
Metro timer = Metro(1000); // A prototype for a Metro timer

void checkFrame(){
  frame++;
  if(timer.check()){  
     Serial.println(frame);
     frame = 0;
  }
}
