// Analog eBrake-Handbrake
// PIN A0 to 10k pot output - Throttle Axis
// Use with Arduino ProMicro.
// Tested and working in DiRT RALLY + ASSETTO CORSA
// by AMSTUDIO
// 20.1.2017

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
                   JOYSTICK_TYPE_JOYSTICK, 0, 0,
                   false, false, false, false, false, false,
                   true, false, false, false, false);

void setup()
{
  //Serial.begin(9600);
  pinMode(A2, INPUT);
  Joystick.begin();
  Joystick.setRudderRange(0, 255);
}

// const int pinToButtonMap = A2;

int last;

void loop()
{
  int pot = analogRead(A2);
  int mapped;
  mapped = map(pot, 450, 650, 0, 255);
  //Serial.println(mapped);

  if(mapped > 50)
  {
    Joystick.setRudder(mapped);
  }
  else
  {
    Joystick.setRudder(0);
    // if (last != 255)
    // {
    //   Joystick.setRudder(mapped);
    // }
  }
  //Serial.print("Mapped:");
  
  //Serial.println(pot);
  delay(10);
}
