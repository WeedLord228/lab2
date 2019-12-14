#include <Servo.h>
#include "button.h"

#define PIN_SERVO 9
#define PIN_BUTTON 8

Button button(PIN_BUTTON);

Servo servo;
int servoPosition = 0;
int previous = 0;


void setup() {
 servo.attach(PIN_SERVO);
 servo.write(servoPosition);
}

void loop() {
  if(button.wasPressed())
  {
    setPos(90);
    moveSmoothly();
    delay(3000);
    setPos(0);
    moveSmoothly();
  }
}

void moveSmoothly()
{
  if(servoPosition > previous){
    for(int i =previous; i < servoPosition; i++)
    {
      servo.write(i);
      delay(20);
    }
  }
  if(servoPosition < previous){
    for(int i = previous; i > servoPosition; i--)
    {
      servo.write(i);
      delay(20);
    }
}
}


void setPos(int pos)
{
  previous = servoPosition;
  servoPosition = pos;
}
