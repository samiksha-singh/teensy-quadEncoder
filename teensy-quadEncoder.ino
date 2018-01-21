/* Encoder Library - TwoKnobs Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

 //reads encoder

#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knobLeft(5, 6);
Encoder knobRight(7, 8);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("TwoKnobs Encoder Test:");
}

long positionLeft  = -999;
long positionRight = -999;
long newLeft, newRight;
float movedCMS;

void loop() {
  
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  if (newLeft != positionLeft || newRight != positionRight) {
    Serial.print("Left = ");
    Serial.print(newLeft);
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
   movedCMS= distanceMoved(newLeft);
    Serial.print("The distance moved: ");
    Serial.print(movedCMS);
    Serial.println("Cms");
    positionLeft = newLeft;
    positionRight = newRight;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    knobLeft.write(0);
    knobRight.write(0);
  }
}

//48 ticks =1 revolution
//1 revolution = 13.188cms
//48 ticks= 13.188cms
// 1 tick= 13.188/48 cms= 0.27475cms
float distanceMoved(long newLeft)
{ //long leftTicks;
  float cmsMoved= 0;
  cmsMoved= newLeft*0.27475;
  
  return cmsMoved;
 
  
}
   

