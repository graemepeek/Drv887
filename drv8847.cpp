/* 
   drv8847.cpp
   Arduino library for the TI DRV8838 motor driver
   Ali Khan - Use this code at your own risk
   Version 1.1
   Date: 23/2/2022
   Change History: Initial Release
*/
#include "drv8847.h"

drv8847::drv8847();

drv8847::drv8847(uint8_t nSLEEP , uint8_t MODE, uint8_t nFAULT, uint8_t IN1, uint8_t IN2, uint8_t IN3, uint8_t IN4)
{
_nSLEEP = nSLEEP;   // Constructor that sets pins nSLEEP MODE nFAULT IN1 IN2 IN3 IN4
_MODE   = MODE  ;
_nFAULT = nFAULT;
_IN1    = IN1   ; // Inhibit/Enable Forward Motor #1
_IN2    = IN2   ; // Inhibit/Enable Reverse Motor #1
_IN3    = IN3   ; // Inhibit/Enable Forward Motor #2
_IN4    = IN4   ; // Inhibit/Enable Reverse Motor #2

}

void drv8847::begin()
{
  pinMode(_nSLEEP,OUTPUT);
  pinMode(_MODE,OUTPUT);
  pinMode(_nFAULT,OUTPUT);
  pinMode(_IN1,OUTPUT);
  pinMode(_IN2,OUTPUT);
  pinMode(_IN3,OUTPUT);
  pinMode(_IN4,OUTPUT);
}

void drv8847::Bridge_mode_Sel(bool mode1, bool mode2, bool mode3)
{
  if(mode1 == true)                       // 4 pin Mode
  {
  digitalWrite(_nSLEEP ,HIGH);  
  digitalWrite(_MODE    ,LOW);
  }

  else if( mode2 == true)                 // 2 pin Mode
  {
  digitalWrite(_nSLEEP ,HIGH);  
  digitalWrite(_MODE   ,HIGH);
  digitalWrite(_IN3    ,LOW);    
  }

  else if( mode3 == true)                 // parallel Mode
  {
  digitalWrite(_nSLEEP ,HIGH);  
  digitalWrite(_MODE   ,HIGH);
  digitalWrite(_IN3    ,HIGH);    
  }
  
}
/////////////////////////////
void drv8847:: Sleep_mode()
{
  digitalWrite(_nSLEEP,LOW);    
}
/////////////////////////////

void drv8847::Motor1_Coast()
{
  Coast(_nSLEEP,_IN1,_IN2);  
}

void drv8847::Motor2_Coast()
{
  Coast(_nSLEEP,_IN3,_IN4);  
}
void drv8847::Coast(uint8_t nSLEEP,uint8_t INA,uint8_t INB)
{
  digitalWrite(nSLEEP,HIGH);  
  digitalWrite(INA    ,LOW);  
  digitalWrite(INB    ,LOW);    
}
/////////////////////////////

void drv8847:: Motor1_Reverse()
{
  Reverse(_nSLEEP,_IN1,_IN2);   
}

void drv8847:: Motor2_Reverse()
{
  Reverse(_nSLEEP,_IN3,_IN4);  
}

void drv8847::Reverse(uint8_t nSLEEP,uint8_t INA,uint8_t INB)
{
  digitalWrite(nSLEEP,HIGH);  
  digitalWrite(INA ,LOW);  
  digitalWrite(INB ,HIGH);    
}
/////////////////////////////

void drv8847:: Motor1_Forward()
{
  Forward(_nSLEEP,_IN1,_IN2);
}

void drv8847:: Motor2_Forward()
{
  Forward(_nSLEEP,_IN3,_IN4);
}

void drv8847::Forward(uint8_t nSLEEP,uint8_t INA,uint8_t INB)
{
  digitalWrite(nSLEEP,HIGH);  
  digitalWrite(INA ,HIGH);  
  digitalWrite(INB ,LOW);  
}
/////////////////////////////

void drv8847:: Motor1_Brake()
{
  Brake(_nSLEEP,_IN1,_IN2);
}

void drv8847:: Motor2_Brake()
{
  Brake(_nSLEEP,_IN3,_IN4);
}

void drv8847::Brake(uint8_t nSLEEP,uint8_t INA, uint8_t INB)
{
  digitalWrite(nSLEEP,HIGH);  
  digitalWrite(INA   ,HIGH);  
  digitalWrite(INB   ,HIGH);   
}
/////////////////////////////
