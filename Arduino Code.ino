/**
 * Code for Arduino. After uploading allow for few minute wait period
 * before activiating feeder via Apple device
 *
 * The AccelStepper Library can be found on the Arduino IDE.
 **/

#include <AccelStepper.h>

#define FULLSTEP 4
AccelStepper myStepper(FULLSTEP, 8, 10, 9, 11);
int motorMoving = 0;                        // 1 if motor is moving


void setup() {
  Serial.begin(115200);                     // testing purposes
  Serial2.begin(9600);                      // ESP32 connection

	// Motor speed setup
	myStepper.setMaxSpeed(1000.0);
	myStepper.setAcceleration(50.0);
	myStepper.setSpeed(200);
}

void loop() {
if (Serial2.available() > 0 ) {             // checks if message from ESP32
  Serial.println("success");                // testing purposes
  Serial2.readString();                     // reads communication from ESP32
  myStepper.move(2038);                     // ~2038 for 360 degrees
  motorMoving = 1;
}
// Rotates Stepper Motor
  while (motorMoving == 1) {
    myStepper.run();                        
    Serial.println("moving");               // testing purposes
    if (myStepper.distanceToGo() == 0) {    // checks if steps remaining
      motorMoving = 0;
      Serial.println("done");               // testing purposes
    }
  }
}
