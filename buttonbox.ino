// Still under development
// Buttons connected directly to arduino box
// Not using input matrix

#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  3, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering
;

// Constant that maps the physical pin to the joystick button.
const int pinTotoggle1Map = 0;
const int pinTotoggle2Map = 1;
const int pinToButtonMap = 2;

void setup() {
//  Serial.begin(9600);

  // Initialize Button Pins
  pinMode(0, INPUT_PULLUP );
  pinMode(1, INPUT_PULLUP );
  pinMode(A0, INPUT_PULLUP );

  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the button
int lastButtonState[3] = {0,0,0};

void loop() {

  // Read pin values for switch
  for (int index = 0; index < 2; index++)
  {
    int currentButtonState = !digitalRead(index);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  // Read pin values for button
//  for (int index = 2; index < 3; index++)
//  {
//    int currentButtonState = digitalRead(index);
//    if (currentButtonState != lastButtonState[index])
//    {
//      Joystick.setButton(index, currentButtonState);
//      lastButtonState[index] = currentButtonState;
//    }
//  }

//  if (digitalRead(A0) != 0)
//  {
      int currentButtonState = digitalRead(A0);
      if (currentButtonState != lastButtonState[2])
      {
        Joystick.setButton(2, currentButtonState);
        lastButtonState[2] = currentButtonState;
      }
//  }
  //  Serial.print("\ncurrent button state:");
  //  Serial.print(currentButtonState);
  //  Serial.print("\nlast button state:");
  //  Serial.print(lastButtonState);
  delay(10);
}
