#include "drv8847.h"
 uint8_t IN1=1;
 uint8_t IN2=2;
 uint8_t IN3=3;
 uint8_t IN4=4;

drv8847 mydrv8847(200,0,0,IN1,IN2,IN3,IN4);

void setup() {
  // put your setup code here, to run once:
  mydrv8847.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Test code
  mydrv8847.Motor1_Forward(); // Start moving motor 1 forward
  delay(1000); // Wait 1 second
  mydrv8847.Motor2_Coast(); // Coast motor to a stop
  delay(1000); // Wait 1 second
  mydrv8847.Motor1_Reverse(); // Run motor 1 in reverse
  delay(1000); // Wait 1 second
  mydrv8847.Motor1_Brake(); // Brake Motor 1
  delay(1000); // Wait 1 second
}
