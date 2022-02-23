/* 
   drv8847.h
   Arduino library for the TI DRV8847 motor driver
   Ali Khan - Use this code at your own risk/peril
 */


#ifndef drv8847_h
#define drv8847_h

#if (ARDUINO >= 100)

#include "Arduino.h"

#else

#include  "WProgram.h"

#endif

class drv8847 {

public:

drv8847();          // default Constructor
drv8847 (uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t); // Constructor that sets pins nSLEEP MODE nFAULT IN1 IN2 IN3 IN4

// Methods
void begin();                          // Setup hardware
void Bridge_mode_Sel(bool mode1, bool mode2, bool mode3);               // Bridge Mode Selection

void Sleep_mode();           //Sleep mode
   
void Motor1_Coast();         //Motor coast (fast decay)
void Motor2_Coast();         //Motor coast (fast decay)

void Motor1_Reverse();       //Reverse direction motor #1
void Motor2_Reverse();       //Reverse direction motor #2

void Motor1_Forward();       //Forward direction motor #1
void Motor2_Forward();       //Forward direction motor #2

void Motor1_Brake  ();       //Motor brake (slow decay)
void Motor2_Brake  ();       //Motor brake (slow decay)

private:
// private properties and method
bool _check_valid(); //check that Pin configuration is set before doing anything
uint8_t _nSLEEP, _MODE, _nFAULT, _IN1, _IN2, _IN3, _IN4; 
void Reverse(uint8_t nSLEEP,uint8_t INA,uint8_t INB);
void Brake  (uint8_t nSLEEP,uint8_t INA,uint8_t INB);       //Motor brake (slow decay)
void Forward(uint8_t nSLEEP,uint8_t INA,uint8_t INB);
void Coast(uint8_t nSLEEP,uint8_t INA,uint8_t INB);  
};
#endif
