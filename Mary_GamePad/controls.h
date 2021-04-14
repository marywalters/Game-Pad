#include <Bounce2.h>

int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins[] = {0, 1, 2, 3};
int buttonBuffer[] = {0, 0, 0, 0};

int joystickPins[] = {A0, A1};
int joystickBuffer[] = {0, 0};
int joystickX;
int joystickY;

Metro statusTimer = Metro(250);

void initControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}

void getControls() {
  for (int i = 0; i < 4; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      buttonBuffer[i] = 0;
    } else if (buttons[i].fell()) {
      buttonBuffer[i] = 1;
    }

  }
  int joyStatusY = analogRead(joystickPins[0]);
  int joyStatusX = analogRead(joystickPins[1]);


  if (joyStatusY < 300) {
    joystickBuffer[0] = -1;
  } else if (joyStatusY > 700) {
    joystickBuffer[0] = 1;
  } else {
    joystickBuffer[0] = 0;
  }
  if (joyStatusX < 300) {
    joystickBuffer[1] = 1;
  } else if (joyStatusX > 700) {
    joystickBuffer[1] = -1;
  } else {
    joystickBuffer[1] = 0;
  }

  if (statusTimer.check()) {
    //  Serial.println(joystickBuffer[0]);
    //  Serial.println(joystickBuffer[1]);
    //    Serial.println(buttonBuffer[0]);
  }
}
