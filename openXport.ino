#include <stdio.h>
#include <string.h>
extern "C"
{
	#include "DS1302.h"
}
//ห้องนอน
int led = 6;
int led1 = 7;
//
//ห้องน้ำ
int led2 = 2;
//
//ห้องรับแขก
int led3 = 5;//Dimmer
int led4 = 8;
int led5 = 9;//Dimmer
int led10 = A3;
int led11 = A4;
//
//ห้องทำงาน
int led6 = 13;
int led7 = A0;
//
//ห้องครัว
int led8 = A1;
int led9 = A2;
//ที่จอดรถ
int led12 = A5;
//
//หน้าบ้าน
int relay  = 3;
int relay1 = 4;
//

String inputString="";
boolean stringComplete=false;
word Timer_Display = 0;
int cpmhour;
int cpmmin;
String RTC_String = "";
String RTC_Date = "";
String RTC_Month = "";
String RTC_Year = "";
String RTC_DOW = "";
String RTC_Hour = "";
String RTC_Min = "";
String RTC_Sec = "";

String SETSW_String ="";

char SWnumber;

String SWhourON = "";
String SWminON = "";
String SWhourOFF = "";
String SWminOFF = "";
String TimerSW_Loop = "";

boolean SW1_flag = 0;
boolean SW2_flag = 0;
boolean SW3_flag = 0;
boolean SW4_flag = 0;
boolean SW5_flag = 0;
boolean SW6_flag = 0;
boolean SW7_flag = 0;
boolean SW8_flag = 0;
boolean SW9_flag = 0;
boolean SW10_flag = 0;
boolean SW11_flag = 0;
boolean SW12_flag = 0;
boolean SW13_flag = 0;
boolean SW14_flag = 0;
boolean SW15_flag = 0;

boolean Timer1_flag = 0;
boolean Timer2_flag = 0;
boolean Timer3_flag = 0;
boolean Timer4_flag = 0;
boolean Timer5_flag = 0;
boolean Timer6_flag = 0;
boolean Timer7_flag = 0;
//B
boolean TimerB_flag = 0;
boolean TimerB1_flag = 0;
boolean TimerB2_flag = 0;
boolean TimerB3_flag = 0;
boolean TimerB4_flag = 0;
boolean TimerB5_flag = 0;
//
//T
boolean TimerT_flag = 0;
boolean TimerT1_flag = 0;
boolean TimerT2_flag = 0;
boolean TimerT3_flag = 0;
boolean TimerT4_flag = 0;
//
//S
boolean TimerS_flag = 0;
boolean TimerS1_flag = 0;
boolean TimerS2_flag = 0;
boolean TimerS3_flag = 0;
//
//C
boolean TimerC_flag = 0;
boolean TimerC1_flag = 0;
boolean TimerC2_flag = 0;
//
//O
boolean TimerO_flag = 0;
boolean TimerO1_flag = 0;
//
//P
boolean TimerP_flag = 0;
//

String SEThourON,SETminON;
String SEThourOFF,SETminOFF;
//
int SW1hourOn,SW1minOn,SW1hourOff,SW1minOff;
int SW2hourOn,SW2minOn,SW2hourOff,SW2minOff;
int SW3hourOn,SW3minOn,SW3hourOff,SW3minOff;
int SW4hourOn,SW4minOn,SW4hourOff,SW4minOff;
int SW5hourOn,SW5minOn,SW5hourOff,SW5minOff;
int SW6hourOn,SW6minOn,SW6hourOff,SW6minOff;
int SW7hourOn,SW7minOn,SW7hourOff,SW7minOff;
//B
int SWBhourOn,SWBminOn,SWBhourOff,SWBminOff;
int SWB1hourOn,SWB1minOn,SWB1hourOff,SWB1minOff;
int SWB2hourOn,SWB2minOn,SWB2hourOff,SWB2minOff;
int SWB3hourOn,SWB3minOn,SWB3hourOff,SWB3minOff;
int SWB4hourOn,SWB4minOn,SWB4hourOff,SWB4minOff;
int SWB5hourOn,SWB5minOn,SWB5hourOff,SWB5minOff;
//

//T
int SWThourOn,SWTminOn,SWThourOff,SWTminOff;
int SWT1hourOn,SWT1minOn,SWT1hourOff,SWT1minOff;
int SWT2hourOn,SWT2minOn,SWT2hourOff,SWT2minOff;
int SWT3hourOn,SWT3minOn,SWT3hourOff,SWT3minOff;
int SWT4hourOn,SWT4minOn,SWT4hourOff,SWT4minOff;
//

//S
int SWShourOn,SWSminOn,SWShourOff,SWSminOff;
int SWS1hourOn,SWS1minOn,SWS1hourOff,SWS1minOff;
int SWS2hourOn,SWS2minOn,SWS2hourOff,SWS2minOff;
int SWS3hourOn,SWS3minOn,SWS3hourOff,SWS3minOff;
//

//C
int SWChourOn,SWCminOn,SWChourOff,SWCminOff;
int SWC1hourOn,SWC1minOn,SWC1hourOff,SWC1minOff;
int SWC2hourOn,SWC2minOn,SWC2hourOff,SWC2minOff;
//

//O
int SWOhourOn,SWOminOn,SWOhourOff,SWOminOff;
int SWO1hourOn,SWO1minOn,SWO1hourOff,SWO1minOff;
//

//P
int SWPhourOn,SWPminOn,SWPhourOff,SWPminOff;
//
//========================================================
int String2Int(String inString)
{
  char String_As_Char[inString.length()];
  inString.toCharArray(String_As_Char, inString.length());
  
  return int(String_As_Char);
  
}
//-------------------------------------------------------
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(led11,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(relay1,OUTPUT);
  digitalWrite(relay, HIGH); 
  digitalWrite(relay1, HIGH); 
  inputString.reserve(100);
  Serial.begin(115200); 
  DS1302_write (DS1302_ENABLE, 0);
  DS1302_write (DS1302_TRICKLE, 0x00);
}

void loop()
{
   ds1302_struct rtc;
            if( Timer_Display++ > 10000 )
            {
                      Timer_Display = 0;                    
                      DS1302_clock_burst_read( (uint8_t *) &rtc);
                      cpmhour = bcd2bin( rtc.h24.Hour10, rtc.h24.Hour);
                      cpmmin  = bcd2bin( rtc.Minutes10, rtc.Minutes);
            }
   if(stringComplete)
  {
     XPORT_Receive(inputString);
     inputString = "";
     stringComplete = false;
  }
 Check_Timer();
}

void XPORT_Receive(String XportinputString){
  
  if( XportinputString[0] == '$' && XportinputString[1] == 'X' && XportinputString[2] == 'P' && XportinputString[3] == 'O' && XportinputString[4] == 'R' && XportinputString[5] == 'T' )
  {
                  if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '1')
                  { 
                        SW1_flag = 1;                   
                        digitalWrite(led, HIGH);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '1')
                  {      
                        SW1_flag = 0;
                        digitalWrite(led, LOW); 
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '2')
                  { 
                        SW2_flag = 1;                   
                        digitalWrite(led1, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '2')
                  {      
                        SW2_flag = 0;
                        digitalWrite(led1, LOW);    
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'R' && XportinputString[10] == '1')
                  { 
                        SW3_flag = 1;                   
                        digitalWrite(relay, LOW);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'R' && XportinputString[10] == '1'){      
                        SW3_flag = 0;
                        digitalWrite(relay, HIGH);    
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'R' && XportinputString[10] == '2'){ 
                        SW4_flag = 1;                   
                        digitalWrite(relay1, LOW);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'R' && XportinputString[10] == '2'){      
                        SW4_flag = 0;
                        digitalWrite(relay1, HIGH);    
                  }  
                   else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '3')
                  { 
                        SW5_flag = 1;                   
                        digitalWrite(led2, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '3')
                  {      
                        SW5_flag = 0;
                        digitalWrite(led2, LOW);    
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '4')
                  { 
                        SW6_flag = 1;                   
                        digitalWrite(led3, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '4')
                  {      
                        SW6_flag = 0;
                        digitalWrite(led3, LOW);    
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '5')
                  { 
                        SW7_flag = 1;                   
                        digitalWrite(led4, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '5')
                  {      
                        SW7_flag = 0;
                        digitalWrite(led4, LOW);    
                  }
                       else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '6')
                  { 
                        SW8_flag = 1;                   
                        digitalWrite(led5, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '6')
                  {      
                        SW8_flag = 0;
                        digitalWrite(led5, LOW);    
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '7')
                  { 
                        SW9_flag = 1;                   
                        digitalWrite(led6, HIGH); 
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '7')
                  {      
                        SW9_flag = 0;
                        digitalWrite(led6, LOW);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '8')
                  {      
                        SW10_flag = 1;
                        digitalWrite(led7, HIGH);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '8')
                  {      
                        SW10_flag = 0;
                        digitalWrite(led7, LOW);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == '9')
                  {      
                        SW11_flag = 1;
                        digitalWrite(led8, HIGH);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == '9')
                  {      
                        SW11_flag = 0;
                        digitalWrite(led8, LOW);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == 'A')
                  {      
                        SW12_flag = 1;
                        digitalWrite(led9, HIGH);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == 'A')
                  {      
                        SW12_flag = 0;
                        digitalWrite(led9, LOW);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == 'B')
                  {      
                        SW13_flag = 1;
                        digitalWrite(led10, HIGH);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == 'B')
                  {      
                        SW13_flag = 0;
                        digitalWrite(led10, LOW);  
                  }
                   else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == 'C')
                  {      
                        SW14_flag = 1;
                        digitalWrite(led11, HIGH);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == 'C')
                  {      
                        SW14_flag = 0;
                        digitalWrite(led11, LOW);  
                  }
                   else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'L' && XportinputString[10] == 'D')
                  {      
                        SW15_flag = 1;
                        digitalWrite(led12, HIGH);  
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'L' && XportinputString[10] == 'D')
                  {      
                        SW15_flag = 0;
                        digitalWrite(led12, LOW);  
                  }
                  //ห้องนอน
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'B' && XportinputString[10] == 'E'&& XportinputString[11] == 'D'&& XportinputString[12] == 'R')
                  {      
                        SW1_flag = 1;                   
                        digitalWrite(led, HIGH); 
                        SW2_flag = 1;                   
                        digitalWrite(led1, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'B' && XportinputString[10] == 'E'&& XportinputString[11] == 'D'&& XportinputString[12] == 'R')
                  {      
                        SW1_flag = 0;
                        digitalWrite(led, LOW);
                        SW2_flag = 0;
                        digitalWrite(led1, LOW);    
                  }
                  //
                  //ห้องน้ำ
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'T' && XportinputString[10] == 'O'&& XportinputString[11] == 'I'&& XportinputString[12] == 'R')
                  {      
                        SW5_flag = 1;                   
                        digitalWrite(led2, HIGH);     
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'T' && XportinputString[10] == 'O'&& XportinputString[11] == 'I'&& XportinputString[12] == 'R')
                  {      
                       SW5_flag = 0;                   
                       digitalWrite(led2, LOW);     
                  }
                  //
                  //ห้องรับแขก
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'S' && XportinputString[10] == 'A'&& XportinputString[11] == 'L'&& XportinputString[12] == 'R')
                  {      
                       SW6_flag = 1;                   
                       digitalWrite(led3, HIGH);
                       SW7_flag = 1;                   
                       digitalWrite(led4, HIGH);
                       SW8_flag = 1;                   
                       digitalWrite(led5, HIGH);
                       SW13_flag = 1;
                       digitalWrite(led10, HIGH); 
                       SW14_flag = 1;
                       digitalWrite(led11, HIGH);      
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'S' && XportinputString[10] == 'A'&& XportinputString[11] == 'L'&& XportinputString[12] == 'R')
                  {      
                       SW6_flag = 0;                   
                       digitalWrite(led3, LOW);
                       SW7_flag = 0;                   
                       digitalWrite(led4, LOW);
                       SW8_flag = 0;                   
                       digitalWrite(led5, LOW);
                       SW13_flag = 0;
                       digitalWrite(led10, LOW); 
                       SW14_flag = 0;
                       digitalWrite(led11, LOW);  
                  }
                  //
                  //ห้องครัว
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'C' && XportinputString[10] == 'O'&& XportinputString[11] == 'O'&& XportinputString[12] == 'R')
                  {      
                       SW11_flag = 1;
                       digitalWrite(led8, HIGH); 
                       SW12_flag = 1;
                       digitalWrite(led9, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'C' && XportinputString[10] == 'O'&& XportinputString[11] == 'O'&& XportinputString[12] == 'R')
                  {      
                       SW11_flag = 0;
                       digitalWrite(led8, LOW); 
                       SW12_flag = 0;
                       digitalWrite(led9, LOW);     
                  }
                  //
                  //ห้องทำงาน
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'F' && XportinputString[10] == 'I'&& XportinputString[11] == 'C'&& XportinputString[12] == 'R')
                  {      
                       SW9_flag = 1;                   
                       digitalWrite(led6, HIGH);
                       SW10_flag = 1;
                       digitalWrite(led7, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'F' && XportinputString[10] == 'I'&& XportinputString[11] == 'C'&& XportinputString[12] == 'R')
                  {      
                       SW9_flag = 0;                   
                       digitalWrite(led6, LOW);
                       SW10_flag = 0;
                       digitalWrite(led7, LOW);    
                  }
                  //
                  //ที่จอดรถ
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'P' && XportinputString[10] == 'A'&& XportinputString[11] == 'R'&& XportinputString[12] == 'R')
                  {      
                       SW15_flag = 1;
                       digitalWrite(led12, HIGH);   
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'P' && XportinputString[10] == 'A'&& XportinputString[11] == 'R'&& XportinputString[12] == 'R')
                  {      
                       SW15_flag = 0;
                       digitalWrite(led12, LOW);    
                  }
                  //
                  //หน้าบ้าน
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'F' && XportinputString[10] == 'T'&& XportinputString[11] == 'D'&& XportinputString[12] == 'R')
                  {      
                      SW3_flag = 1;                   
                      digitalWrite(relay, LOW);     
                      SW4_flag = 1;                   
                      digitalWrite(relay1, LOW);
                  }
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'F' && XportinputString[10] == 'T'&& XportinputString[11] == 'D'&& XportinputString[12] == 'R')
                  {      
                      SW3_flag = 0;
                      digitalWrite(relay, HIGH);
                      SW4_flag = 0;
                      digitalWrite(relay1, HIGH);      
                  }
                  //
                  
                  //โหมดการทำงาน
                  
                  //1.โหมดประหยัด
                  else if(XportinputString[7] == 'S' && XportinputString[8] == 'A' && XportinputString[9] == 'V' && XportinputString[10] == 'E'&& XportinputString[11] == 'E'&& XportinputString[12] == 'N')
                  {     
                        SW1_flag = 1;                   
                        digitalWrite(led, HIGH); 
                        delay(50);
                        
                        SW2_flag = 0;  
                        digitalWrite(led1, LOW);
                        delay(50);
                        
                        SW3_flag = 1;  
                        digitalWrite(relay, LOW);
                        delay(50);   
                        
                        SW4_flag = 0;                   
                        digitalWrite(relay1, HIGH);
                        delay(50);
                        
                        SW5_flag = 1;                   
                        digitalWrite(led2, HIGH);
                        delay(50);	
                        					
                        SW6_flag = 1;                   
                        digitalWrite(led3, HIGH);
                        delay(50);
                        
                        SW7_flag = 0;                   
                        digitalWrite(led4, LOW);
                        delay(50);
                        
                        SW8_flag = 1;                   
                        digitalWrite(led5, HIGH);
                        delay(50);
                        
                        SW9_flag = 1;                   
                        digitalWrite(led6, HIGH);
                        delay(50);
                        
                        SW10_flag = 0;
                        digitalWrite(led7, LOW);
                        delay(50);
                        
                        SW11_flag = 1;
                        digitalWrite(led8, HIGH);
                        delay(50); 
                        
                        SW12_flag = 0;
                        digitalWrite(led9, LOW);
                        delay(50);
                        
                        SW13_flag = 0;
                        digitalWrite(led10, LOW);
                        delay(50); 
                        
                        SW14_flag = 0;
                        digitalWrite(led11, LOW);
                        delay(50);	
                        				
                        SW15_flag = 0;
                        digitalWrite(led12, LOW); 
                        delay(50);     
                  }
                  //End โหมดประหยัดพลังงาน
                  
                  //2.โหมดหรี่ไฟ
                  //หรี่ไฟ1 ห้องนอน
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == '1')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      analogWrite(led,c);
                      if(c==0)
                      {
                        SW1_flag = 0;
                      }
                      else 
                      {
                        SW1_flag = 1;
                      }
                  }
                  //
                  //หรี่ไฟ2 
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == '2')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      digitalWrite(led1,c);
                      if(c==0)
                      {
                        SW2_flag = 0;
                      }
                      else 
                      {
                        SW2_flag = 1;
                      }
                  }
                  //
                  //หรี่ไฟ3 ห้องน้ำ
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == '3')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      digitalWrite(led2,c);
                      if(c==0)
                      {
                        SW5_flag = 0;
                      }
                      else 
                      {
                        SW5_flag = 1;
                      }
                  }
                  //
                  //หรี่ไฟ4 ห้องรับแขก ดวงที่ 1
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == '4')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      analogWrite(led3,c);
                      if(c==0)
                      {
                        SW6_flag = 0;
                      }
                      else 
                      {
                        SW6_flag = 1;
                      }
                  }
                  //
                  //หรี่ไฟ5 ห้องรับแขก ดวงที่ 2
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == '6')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      analogWrite(led5,c);
                      if(c==0)
                      {
                        SW8_flag = 0;
                      }
                      else 
                      {
                        SW8_flag = 1;
                      }
                  }
                  //
                  
                  //หรี่ไฟ7
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == '7')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      digitalWrite(led10,c);
                      if(c==0)
                      {
                        SW13_flag = 0;
                      }
                      else 
                      {
                        SW13_flag = 1;
                      }
                  }
                  //
                  //หรี่ไฟ9 ห้องทำงาน
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == '9')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      digitalWrite(led6,c);
                      if(c==0)
                      {
                        SW9_flag = 0;
                      }
                      else 
                      {
                        SW9_flag = 1;
                      }
                  }
                  //
                  //หรี่ไฟ10
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == 'A')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      digitalWrite(led7,c);
                      if(c==0)
                      {
                        SW10_flag = 0;
                      }
                      else 
                      {
                        SW10_flag = 1;
                      }
                  }
                  //
                  //หรี่ไฟ11 ห้องครัว
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == 'B')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      digitalWrite(led8,c);
                      if(c==0)
                      {
                        SW11_flag = 0;
                      }
                      else 
                      {
                        SW11_flag = 1;
                      }
                  }
                  //
                  
                  //
                  //หรี่ไฟ15 ที่จอดรถ
                  else if(XportinputString[7] == 'D' && XportinputString[8] == 'I' && XportinputString[9] == 'O' && XportinputString[10] == 'N'&& XportinputString[11] == 'L'&& XportinputString[12] == 'G')
                  {
                      String str;
                      str=XportinputString.substring(13,16);
                      str.toInt();
                      float c;
                      c=str.toInt();
                      c=c*2.55;
                      digitalWrite(led12,c);
                      if(c==0)
                      {
                        SW15_flag = 0;
                      }
                      else 
                      {
                        SW15_flag = 1;
                      }
                  }
                  //
                  //End โหมดหรี่ไฟ
                  
                  //3.โหมดสว่างเต็มที่
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'N' && XportinputString[9] == 'A' && XportinputString[10] == 'L'&& XportinputString[11] == 'L'&& XportinputString[12] == 'L')
                  {      
                        SW1_flag = 1;                   
                        digitalWrite(led, HIGH); 
                        delay(50);
                        SW2_flag = 1;                 
                        digitalWrite(led1, HIGH);
                        delay(50);
                        SW3_flag = 1;                   
                        digitalWrite(relay, LOW);
                        delay(50);     
                        SW4_flag = 1;                   
                        digitalWrite(relay1, LOW);
                        delay(50);
                        SW5_flag = 1;                   
                        digitalWrite(led2, HIGH);
                        delay(50);						
                        SW6_flag = 1;                   
                        digitalWrite(led3, HIGH);
                        delay(50);
                        SW7_flag = 1;                   
                        digitalWrite(led4, HIGH);
                        delay(50);
                        SW8_flag = 1;                   
                        digitalWrite(led5, HIGH);
                        delay(50);
                        SW9_flag = 1;                   
                        digitalWrite(led6, HIGH);
                        delay(50);
                        SW10_flag = 1;
                        digitalWrite(led7, HIGH);
                        delay(50);
                        SW11_flag = 1;
                        digitalWrite(led8, HIGH);
                        delay(50); 
                        SW12_flag = 1;
                        digitalWrite(led9, HIGH);
                        delay(50);
                        SW13_flag = 1;
                        digitalWrite(led10, HIGH);
                        delay(50); 
                        SW14_flag = 1;
                        digitalWrite(led11, HIGH);
                        delay(50);					
                        SW15_flag = 1;
                        digitalWrite(led12, HIGH); 
                        delay(50);     
                  }
                  //End โหมดสว่างเต็มที่
                  
                   //ปิดทุกดวง
                  else if(XportinputString[7] == 'O' && XportinputString[8] == 'F' && XportinputString[9] == 'A' && XportinputString[10] == 'L'&& XportinputString[11] == 'L'&& XportinputString[12] == 'L')
                  {      
                        SW1_flag = 0;                   
                        digitalWrite(led, LOW); 
                        delay(50);
                        SW2_flag = 0;                 
                        digitalWrite(led1, LOW);
                        delay(50);
                        SW3_flag = 0;                   
                        digitalWrite(relay, HIGH);
                        delay(50);     
                        SW4_flag = 0;                   
                        digitalWrite(relay1, HIGH);
                        delay(50);
                        SW5_flag = 0;                   
                        digitalWrite(led2, LOW);
                        delay(50);						
                        SW6_flag = 0;                   
                        digitalWrite(led3, LOW);
                        delay(50);
                        SW7_flag = 0;                   
                        digitalWrite(led4, LOW);
                        delay(50);
                        SW8_flag = 0;                   
                        digitalWrite(led5, LOW);
                        delay(50);
                        SW9_flag = 0;                   
                        digitalWrite(led6, LOW);
                        delay(50);
                        SW10_flag = 0;
                        digitalWrite(led7, LOW);
                        delay(50);
                        SW11_flag = 0;
                        digitalWrite(led8, LOW);
                        delay(50); 
                        SW12_flag = 0;
                        digitalWrite(led9, LOW);
                        delay(50);
                        SW13_flag = 0;
                        digitalWrite(led10, LOW);
                        delay(50); 
                        SW14_flag = 0;
                        digitalWrite(led11, LOW);
                        delay(50);					
                        SW15_flag = 0;
                        digitalWrite(led12, LOW); 
                        delay(50);     
                  }
                  //End ปิดทุกดวง
                  
                  //จบโหมดการทำงาน   
//==============================================================================================================================
                  //$XPORTREADSTATE******
                  else if(XportinputString[6] == 'R' && XportinputString[7] == 'E' && XportinputString[8] == 'A' && XportinputString[9] == 'D' && XportinputString[10] == 'S' && XportinputString[11] == 'T'
                     && XportinputString[12] == 'A' && XportinputString[13] == 'T' && XportinputString[14] == 'E' ){

			if(SW1_flag == 1)
                          { 
                            Serial.print("SW1=ON\n");
                          }
			else if(SW1_flag == 0)
                          { 
                            Serial.print("SW1=OFF\n"); 
                          }

			if(SW2_flag == 1)
                          { 
                            Serial.print("SW2=ON\n"); 
                          }
			else if(SW2_flag == 0)
                          { 
                            Serial.print("SW2=OFF\n"); 
                          }

			if(SW3_flag == 1)
                          { 
                            Serial.print("SW3=ON\n"); 
                          }
			else if(SW3_flag == 0)
                          { 
                            Serial.print("SW3=OFF\n"); 
                          }

			if(SW4_flag == 1)
                          { 
                            Serial.print("SW4=ON\n"); 
                          }

			else if(SW4_flag == 0)
                          { 
                            Serial.print("SW4=OFF\n"); 
                          }

			if(SW5_flag == 1)
                          { 
                            Serial.print("SW5=ON\n"); 
                          }
			else if(SW5_flag == 0)
                          { 
                            Serial.print("SW5=OFF\n"); 
                          }

			if(SW6_flag == 1)
                          { 
                            Serial.print("SW6=ON\n"); 
                          }
			else if(SW6_flag == 0)
                          { 
                            Serial.print("SW6=OFF\n"); 
                          }

			if(SW7_flag == 1)
                          { 
                            Serial.print("SW7=ON\n"); 
                          }
			else if (SW7_flag == 0)
                          { 
                            Serial.print("SW7=OFF\n"); 
                          }

                        if(SW8_flag == 1)
                          { 
                            Serial.print("SW8=ON\n"); 
                          }		
                        else if(SW8_flag == 0)
                          { 
                            Serial.print("SW8=OFF\n"); 
                          }

                        if(SW9_flag == 1)
                          { 
                            Serial.print("SW9=ON\n"); 
                          }
                        			
                        else if(SW9_flag == 0)
                          { 
                            Serial.print("SW9=OFF\n"); 
                          }
                        if(SW10_flag == 1)
                          { 
                            Serial.print("SW10=ON\n"); 
                          }		
                        else if(SW10_flag == 0)
                          { 
                            Serial.print("SW10=OFF\n"); 
                          }
                        if(SW11_flag == 1)
                          { 
                            Serial.print("SW11=ON\n"); 
                          }		
                        else if(SW11_flag == 0)
                          { 
                            Serial.print("SW11=OFF\n"); 
                          }
                        if(SW12_flag == 1)
                          { 
                            Serial.print("SW12=ON\n"); 
                          }	
                        else if(SW12_flag == 0)
                          { 
                            Serial.print("SW12=OFF\n"); 
                          }
                        if(SW13_flag == 1)
                          { 
                            Serial.print("SW13=ON\n"); 
                          }
                        else if(SW13_flag == 0)
                          { 
                            Serial.print("SW13=OFF\n"); 
                          }
                        if(SW14_flag == 1)
                          { 
                            Serial.print("SW14=ON\n"); 
                          }	
                        else if(SW14_flag == 0)
                          { 
                            Serial.print("SW14=OFF\n"); 
                          }
                        if(SW15_flag == 1)
                          { 
                            Serial.print("SW15=ON\n"); 
                          }	
                        else if(SW15_flag == 0)
                          { 
                            Serial.print("SW15=OFF\n"); 
                          } 
                  }
 //End Check Status
 
 //Set Time
 //$XPORTSYNRTC + : ( ตัวแบ่งข้อมูล ) + วัน : เดือน : ปี : DOW* : ชั่วโมง : นาที : วินาที( ซึ่งทุกๆ ข้อมูลต้องคั่นด้วยตัวแบ่งข้อมูลทุกครั้ง ) ==========================================
                  if(XportinputString[6] == 'S' && XportinputString[7] == 'Y' && XportinputString[8] == 'N' && XportinputString[9] == 'R'&& XportinputString[10] == 'T'&& XportinputString[11] == 'C'){

                        //Serial.println("SYNCRTC");
                        //Serial.println("Looking for the ':' character");
		        
                        int FindPosition[7];
   
                        RTC_String = XportinputString;
                        
                        for(int i = 0; i<7; i++ ){
                            FindPosition[i] = RTC_String.indexOf(':');						// For shearching ':'
                            RTC_String = RTC_String.substring(FindPosition[i] + 1 , 35);
                            //Serial.println(RTC_String);
                        }
                        
                        RTC_Date   = XportinputString.substring(FindPosition[0] + 1 , FindPosition[0] + FindPosition[1] + 1 );
                        RTC_Month  = XportinputString.substring(FindPosition[0] + FindPosition[1] + 2 , FindPosition[0] + FindPosition[1] + FindPosition[2] + 2 );
                        RTC_Year   = XportinputString.substring(FindPosition[0] + FindPosition[1] + FindPosition[2] + 3 , FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3] + 3 );
                        RTC_DOW    = XportinputString.substring(FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3] + 4 , FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3] + FindPosition[4] + 4 );
                        RTC_Hour   = XportinputString.substring(FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3]  + FindPosition[4] + 5 , FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3] + FindPosition[4]  + FindPosition[5] + 5 );
                        RTC_Min    = XportinputString.substring(FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3]  + FindPosition[4] + FindPosition[5] + 6 , FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3] + FindPosition[4]  + FindPosition[5] + FindPosition[6] + 9);
                        RTC_Sec    = XportinputString.substring(FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3]  + FindPosition[4] + FindPosition[5] + FindPosition[6] + 7 , FindPosition[0] + FindPosition[1] + FindPosition[2] + FindPosition[3] + FindPosition[4]  + FindPosition[5] + FindPosition[6] + FindPosition[7] + 9 );
                        
                        Update_Date_Time( RTC_Date.toInt(), RTC_Month.toInt(), RTC_Year.toInt(), RTC_DOW.toInt(), RTC_Hour.toInt() , RTC_Min.toInt(), RTC_Sec.toInt()); 
                  }
                  
                  //$XPORTSETSW + SWnumber + ":ON:" + ชั่วโมง :นาที + ":OFF:" + ชั่วโมง : นาที + Loop ===========================================================================
                   if(XportinputString[6] == 'S' && XportinputString[7] == 'E' && XportinputString[8] == 'T' && XportinputString[9] == 'S'&& XportinputString[10] == 'W'){                      
                       int FindData[7];
                       
                       SETSW_String = XportinputString;
                       
                         for(int i = 0; i<7; i++ ){
                            FindData[i] = SETSW_String.indexOf(':');						// For shearching ':'
                            SETSW_String = SETSW_String.substring(FindData[i] + 1 , 35);
                            //Serial.println(SETSW_String);
                        }
                       SEThourON      = XportinputString.substring(FindData[0] + FindData[1] + 2 , FindData[0] + FindData[1] + FindData[2] + 2 );
                       SETminON       = XportinputString.substring(FindData[0] + FindData[1] + FindData[2] + 3 , FindData[0] + FindData[1] + FindData[2] + FindData[3] + 3 );
                       SEThourOFF     = XportinputString.substring(FindData[0] + FindData[1] + FindData[2] + FindData[3]  + FindData[4] + 5 , FindData[0] + FindData[1] + FindData[2] + FindData[3] + FindData[4]  + FindData[5] + 5 );
                       SETminOFF      = XportinputString.substring(FindData[0] + FindData[1] + FindData[2] + FindData[3]  + FindData[4] + FindData[5] + 6 , FindData[0] + FindData[1] + FindData[2] + FindData[3] + FindData[4]  + FindData[5] + FindData[6] + 9);
                       TimerSW_Loop   = XportinputString.substring(FindData[0] + FindData[1] + FindData[2] + FindData[3]  + FindData[4] + FindData[5] + FindData[6] + 7 , FindData[0] + FindData[1] + FindData[2] + FindData[3] + FindData[4]  + FindData[5] + FindData[6] + FindData[7] + 9 );

					if(XportinputString[11] == '1')
					{
						Timer1_flag = 1;

						SW1hourOn = SEThourON.toInt(); 
						SW1minOn  = SETminON.toInt();
						SW1hourOff= SEThourOFF.toInt();
 						SW1minOff = SETminOFF.toInt();
					}

					 if(XportinputString[11] == '2')
					{
						Timer2_flag = 1;

						SW2hourOn = SEThourON.toInt(); 
						SW2minOn  = SETminON.toInt();
						SW2hourOff= SEThourOFF.toInt();
 						SW2minOff = SETminOFF.toInt();
					}

					 if(XportinputString[11] == '3')
					{
						Timer3_flag = 1;

						SW3hourOn = SEThourON.toInt(); 
						SW3minOn  = SETminON.toInt();
						SW3hourOff= SEThourOFF.toInt();
 						SW3minOff = SETminOFF.toInt();
					}

					if(XportinputString[11] == '4')
					{
						Timer4_flag = 1;

						SW4hourOn = SEThourON.toInt(); 
						SW4minOn  = SETminON.toInt();
						SW4hourOff= SEThourOFF.toInt();
 						SW4minOff = SETminOFF.toInt();
					}

					 if(XportinputString[11] == '5')
					{
						Timer5_flag = 1;

						SW5hourOn = SEThourON.toInt(); 
						SW5minOn  = SETminON.toInt();
						SW5hourOff= SEThourOFF.toInt();
 						SW5minOff = SETminOFF.toInt();
					}

					 if(XportinputString[11] == '6')
					{
						Timer6_flag = 1;

						SW6hourOn = SEThourON.toInt(); 
						SW6minOn  = SETminON.toInt();
						SW6hourOff= SEThourOFF.toInt();
 						SW6minOff = SETminOFF.toInt();
					}
                                        
                                         if(XportinputString[11] == '7')
					{
						Timer7_flag = 1;

						SW7hourOn = SEThourON.toInt(); 
						SW7minOn  = SETminON.toInt();
						SW7hourOff= SEThourOFF.toInt();
 						SW7minOff = SETminOFF.toInt();
					}
                                        //B
                                         if(XportinputString[11] == 'B' && XportinputString[12] == '0')
					{
						TimerB_flag = 1;
						SWBhourOn = SEThourON.toInt(); 
						SWBminOn  = SETminON.toInt();
						SWBhourOff= SEThourOFF.toInt();
 						SWBminOff = SETminOFF.toInt();
					}
                                         if(XportinputString[11] == 'B' && XportinputString[12] == '1')
					{
                                                TimerB1_flag = 1;
						SWB1hourOn = SEThourON.toInt(); 
						SWB1minOn  = SETminON.toInt();
						SWB1hourOff= SEThourOFF.toInt();
 						SWB1minOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'B' && XportinputString[12] == '2')
					{
                                                TimerB2_flag = 1;
						SWB2hourOn = SEThourON.toInt(); 
						SWB2minOn  = SETminON.toInt();
						SWB2hourOff= SEThourOFF.toInt();
 						SWB2minOff = SETminOFF.toInt();
					}
                                         if(XportinputString[11] == 'B' && XportinputString[12] == '3')
					{
                                                TimerB3_flag = 1;
						SWB3hourOn = SEThourON.toInt(); 
						SWB3minOn  = SETminON.toInt();
						SWB3hourOff= SEThourOFF.toInt();
 						SWB3minOff = SETminOFF.toInt();
					}
                                         if(XportinputString[11] == 'B' && XportinputString[12] == '4')
					{
                                                TimerB4_flag = 1;
						SWB4hourOn = SEThourON.toInt(); 
						SWB4minOn  = SETminON.toInt();
						SWB4hourOff= SEThourOFF.toInt();
 						SWB4minOff = SETminOFF.toInt();
					}
                                         if(XportinputString[11] == 'B' && XportinputString[12] == '5')
					{
                                                TimerB5_flag = 1;
						SWB5hourOn = SEThourON.toInt(); 
						SWB5minOn  = SETminON.toInt();
						SWB5hourOff= SEThourOFF.toInt();
 						SWB5minOff = SETminOFF.toInt();
					}
                                        //end B
                                        
                                        //T
                                        if(XportinputString[11] == 'T' && XportinputString[12] == '0')
					{
						TimerT_flag = 1;
						SWThourOn = SEThourON.toInt(); 
						SWTminOn  = SETminON.toInt();
						SWThourOff= SEThourOFF.toInt();
 						SWTminOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'T' && XportinputString[12] == '1')
					{
                                                TimerT1_flag = 1;
						SWT1hourOn = SEThourON.toInt(); 
						SWT1minOn  = SETminON.toInt();
						SWT1hourOff= SEThourOFF.toInt();
 						SWT1minOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'T' && XportinputString[12] == '2')
					{
                                                TimerT2_flag = 1;
						SWT2hourOn = SEThourON.toInt(); 
						SWT2minOn  = SETminON.toInt();
						SWT2hourOff= SEThourOFF.toInt();
 						SWT2minOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'T' && XportinputString[12] == '3')
					{
                                                TimerT3_flag = 1;
						SWT3hourOn = SEThourON.toInt(); 
						SWT3minOn  = SETminON.toInt();
						SWT3hourOff= SEThourOFF.toInt();
 						SWT3minOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'T' && XportinputString[12] == '4')
					{
                                                TimerT4_flag = 1;
						SWT4hourOn = SEThourON.toInt(); 
						SWT4minOn  = SETminON.toInt();
						SWT4hourOff= SEThourOFF.toInt();
 						SWT4minOff = SETminOFF.toInt();
					}
                                        //end T
                                        //S
                                        if(XportinputString[11] == 'S' && XportinputString[12] == '0')
					{
						TimerS_flag = 1;
						SWShourOn = SEThourON.toInt(); 
						SWSminOn  = SETminON.toInt();
						SWShourOff= SEThourOFF.toInt();
 						SWSminOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'S' && XportinputString[12] == '1')
					{
                                                TimerS1_flag = 1;
						SWS1hourOn = SEThourON.toInt(); 
						SWS1minOn  = SETminON.toInt();
						SWS1hourOff= SEThourOFF.toInt();
 						SWS1minOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'S' && XportinputString[12] == '2')
					{
                                                TimerS2_flag = 1;
						SWS2hourOn = SEThourON.toInt(); 
						SWS2minOn  = SETminON.toInt();
						SWS2hourOff= SEThourOFF.toInt();
 						SWS2minOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'S' && XportinputString[12] == '3')
					{
                                                TimerS3_flag = 1;
						SWS3hourOn = SEThourON.toInt(); 
						SWS3minOn  = SETminON.toInt();
						SWS3hourOff= SEThourOFF.toInt();
 						SWS3minOff = SETminOFF.toInt();
					}
                                        //end S
                                        //C
                                        if(XportinputString[11] == 'C' && XportinputString[12] == '0')
					{
						TimerC_flag = 1;
						SWChourOn = SEThourON.toInt(); 
						SWCminOn  = SETminON.toInt();
						SWChourOff= SEThourOFF.toInt();
 						SWCminOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'C' && XportinputString[12] == '1')
					{
                                                TimerC1_flag = 1;
						SWC1hourOn = SEThourON.toInt(); 
						SWC1minOn  = SETminON.toInt();
						SWC1hourOff= SEThourOFF.toInt();
 						SWC1minOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'C' && XportinputString[12] == '2')
					{
                                                TimerC2_flag = 1;
						SWC2hourOn = SEThourON.toInt(); 
						SWC2minOn  = SETminON.toInt();
						SWC2hourOff= SEThourOFF.toInt();
 						SWC2minOff = SETminOFF.toInt();
					}
                                        //end C
                                        //O
                                        if(XportinputString[11] == 'O' && XportinputString[12] == '0')
					{
						TimerO_flag = 1;
						SWOhourOn = SEThourON.toInt(); 
						SWOminOn  = SETminON.toInt();
						SWOhourOff= SEThourOFF.toInt();
 						SWOminOff = SETminOFF.toInt();
					}
                                        if(XportinputString[11] == 'O' && XportinputString[12] == '1')
					{
                                                TimerO1_flag = 1;
						SWO1hourOn = SEThourON.toInt(); 
						SWO1minOn  = SETminON.toInt();
						SWO1hourOff= SEThourOFF.toInt();
 						SWO1minOff = SETminOFF.toInt();
					}
                                        //end O
                                        //P
                                        if(XportinputString[11] == 'P' && XportinputString[12] == '0')
					{
						TimerP_flag = 1;
						SWPhourOn = SEThourON.toInt(); 
						SWPminOn  = SETminON.toInt();
						SWPhourOff= SEThourOFF.toInt();
 						SWPminOff = SETminOFF.toInt();
					}
                                        //end P 
                                        
                   }
  }
}
//======================================================================================================
//	Set Timer SW1
void SW1_Timer_ON()
{
	if( SW1hourOn == cpmhour && SW1minOn == cpmmin )
	{
		SW1_flag = 1;                   
                digitalWrite(led, HIGH); 
                SW2_flag = 1;                   
                digitalWrite(led1, HIGH);   
	}
}

void SW1_Timer_OFF()
{
	if( SW1hourOff == cpmhour && SW1minOff == cpmmin )
	{
		SW1_flag = 0;                   
                digitalWrite(led, LOW); 
                SW2_flag = 0;                   
                digitalWrite(led1, LOW);   					// Only 1 round
	}
}

//======================================================================================================
//	Set Timer SW2
void SW2_Timer_ON()
{
	if( SW2hourOn == cpmhour && SW2minOn == cpmmin )
	{
		SW5_flag = 1;                   
                digitalWrite(led2, HIGH);
	}
}

void SW2_Timer_OFF()
{
	if( SW2hourOff == cpmhour && SW2minOff == cpmmin )
	{
		SW5_flag = 0;                   
                digitalWrite(led2, LOW);
	}
}
//======================================================================================================
//	Set Timer SW3
void SW3_Timer_ON()
{
	if( SW3hourOn == cpmhour && SW3minOn == cpmmin )
	{
                SW6_flag = 1;                   
                digitalWrite(led3, HIGH);
                SW7_flag = 1;                   
                digitalWrite(led4, HIGH);
                SW8_flag = 1;                   
                digitalWrite(led5, HIGH);
                SW13_flag = 1;
                digitalWrite(led10, HIGH); 
                SW14_flag = 1;
                digitalWrite(led11, HIGH); 
	}
}

void SW3_Timer_OFF()
{
	if( SW3hourOff == cpmhour && SW3minOff == cpmmin )
	{
		SW6_flag = 0;                   
                digitalWrite(led3, LOW);
                SW7_flag = 0;                   
                digitalWrite(led4, LOW);
                SW8_flag = 0;                   
                digitalWrite(led5, LOW);
                SW13_flag = 0;
                digitalWrite(led10, LOW); 
                SW14_flag = 0;
                digitalWrite(led11, LOW); 
	}
}

//======================================================================================================
//	Set Timer SW4
void SW4_Timer_ON()
{
	if( SW4hourOn == cpmhour && SW4minOn == cpmmin )
	{
		SW11_flag = 1;
                digitalWrite(led8, HIGH); 
                SW12_flag = 1;
                digitalWrite(led9, HIGH); 
	}
}

void SW4_Timer_OFF()
{
	if( SW4hourOff == cpmhour && SW4minOff == cpmmin )
	{
		SW11_flag = 0;
                digitalWrite(led8, LOW); 
                SW12_flag = 0;
                digitalWrite(led9, LOW);
	}
}

//======================================================================================================
//	Set Timer SW5
void SW5_Timer_ON()
{
	if( SW5hourOn == cpmhour && SW5minOn == cpmmin )
	{
		SW9_flag = 1;                   
                digitalWrite(led6, HIGH);
                SW10_flag = 1;
                digitalWrite(led7, HIGH);
	}
}

void SW5_Timer_OFF()
{
	if( SW5hourOff == cpmhour && SW5minOff == cpmmin )
	{
		SW9_flag = 0;                   
                digitalWrite(led6, LOW);
                SW10_flag = 0;
                digitalWrite(led7, LOW);
	}
}

//======================================================================================================
//	Set Timer SW6
void SW6_Timer_ON()
{
	if( SW6hourOn == cpmhour && SW6minOn == cpmmin )
	{
		SW15_flag = 1;
                digitalWrite(led12, HIGH);
	}
}

void SW6_Timer_OFF()
{
	if( SW6hourOff == cpmhour && SW6minOff == cpmmin )
	{
		SW15_flag = 0;
                digitalWrite(led12, LOW);
	}
}

//======================================================================================================
//	Set Timer SW7
void SW7_Timer_ON()
{
	if( SW7hourOn == cpmhour && SW7minOn == cpmmin )
	{
                SW3_flag = 1;                   
                digitalWrite(relay, LOW);     
                SW4_flag = 1;                   
                digitalWrite(relay1, LOW);
	}
}

void SW7_Timer_OFF()
{
	if( SW7hourOff == cpmhour && SW7minOff == cpmmin )
	{
		SW3_flag = 0;                   
                digitalWrite(relay, HIGH);     
                SW4_flag = 0;                   
                digitalWrite(relay1, HIGH);
	}
}
//======================================================================================================

//========================================Start B==============================================================
//	Set Timer SW Bedroom and Toilet
void SWB_Timer_ON()
{
	if( SWBhourOn == cpmhour && SWBminOn == cpmmin )
	{
                SW1_flag = 1;                   
                digitalWrite(led, HIGH); 
                SW2_flag = 1;                   
                digitalWrite(led1, HIGH);
                
                SW5_flag = 1;                   
                digitalWrite(led2, HIGH);
	}
}

void SWB_Timer_OFF()
{
	if( SWBhourOff == cpmhour && SWBminOff == cpmmin )
	{
		SW1_flag = 0;                   
                digitalWrite(led, LOW); 
                SW2_flag = 0;                   
                digitalWrite(led1, LOW);
                
                SW5_flag = 0;                   
                digitalWrite(led2, LOW);
	}
}

//======================================================================================================
//	Set Timer SW Bedroom and Saloon
void SWB1_Timer_ON()
{
	if( SWB1hourOn == cpmhour && SWB1minOn == cpmmin )
	{
                SW1_flag = 1;                   
                digitalWrite(led, HIGH); 
                SW2_flag = 1;                   
                digitalWrite(led1, HIGH);
                
                SW6_flag = 1;                   
                digitalWrite(led3, HIGH);
                SW7_flag = 1;                   
                digitalWrite(led4, HIGH);
                SW8_flag = 1;                   
                digitalWrite(led5, HIGH);
                SW13_flag = 1;
                digitalWrite(led10, HIGH); 
                SW14_flag = 1;
                digitalWrite(led11, HIGH);
	}
}

void SWB1_Timer_OFF()
{
	if( SWB1hourOff == cpmhour && SWB1minOff == cpmmin )
	{
		SW1_flag = 0;                   
                digitalWrite(led, LOW); 
                SW2_flag = 0;                   
                digitalWrite(led1, LOW);
                
                SW6_flag = 0;                   
                digitalWrite(led3, LOW);
                SW7_flag = 0;                   
                digitalWrite(led4, LOW);
                SW8_flag = 0;                   
                digitalWrite(led5, LOW);
                SW13_flag = 0;
                digitalWrite(led10, LOW); 
                SW14_flag = 0;
                digitalWrite(led11, LOW);
	}
}
//======================================================================================================
//	Set Timer SW Bedroom and Cook
void SWB2_Timer_ON()
{
	if( SWB2hourOn == cpmhour && SWB2minOn == cpmmin )
	{
                SW1_flag = 1;                   
                digitalWrite(led, HIGH); 
                SW2_flag = 1;                   
                digitalWrite(led1, HIGH);
                
                 SW11_flag = 1;
                 digitalWrite(led8, HIGH); 
                 SW12_flag = 1;
                 digitalWrite(led9, HIGH);
	}
}

void SWB2_Timer_OFF()
{
	if( SWB2hourOff == cpmhour && SWB2minOff == cpmmin )
	{
		SW1_flag = 0;                   
                digitalWrite(led, LOW); 
                SW2_flag = 0;                   
                digitalWrite(led1, LOW);
                
                SW11_flag = 0;
                digitalWrite(led8, LOW); 
                SW12_flag = 0;
                digitalWrite(led9, LOW);
	}
}
//======================================================================================================
//	Set Timer SW Bedroom and Office
void SWB3_Timer_ON()
{
	if( SWB3hourOn == cpmhour && SWB3minOn == cpmmin )
	{
                SW1_flag = 1;                   
                digitalWrite(led, HIGH); 
                SW2_flag = 1;                   
                digitalWrite(led1, HIGH);
                
                SW9_flag = 1;                   
                digitalWrite(led6, HIGH);
                SW10_flag = 1;
                digitalWrite(led7, HIGH); 
	}
}

void SWB3_Timer_OFF()
{
	if( SWB3hourOff == cpmhour && SWB3minOff == cpmmin )
	{
		SW1_flag = 0;                   
                digitalWrite(led, LOW); 
                SW2_flag = 0;                   
                digitalWrite(led1, LOW);
                
                SW9_flag = 0;                   
                digitalWrite(led6, LOW);
                SW10_flag = 0;
                digitalWrite(led7, LOW);   
	}
}
//======================================================================================================
//	Set Timer SW Bedroom and Parkroom
void SWB4_Timer_ON()
{
	if( SWB4hourOn == cpmhour && SWB4minOn == cpmmin )
	{
                SW1_flag = 1;                   
                digitalWrite(led, HIGH); 
                SW2_flag = 1;                   
                digitalWrite(led1, HIGH);
                
                SW15_flag = 1;
                digitalWrite(led12, HIGH); 
	}
}

void SWB4_Timer_OFF()
{
	if( SWB4hourOff == cpmhour && SWB4minOff == cpmmin )
	{
		SW1_flag = 0;                   
                digitalWrite(led, LOW); 
                SW2_flag = 0;                   
                digitalWrite(led1, LOW);
                
                SW15_flag = 0;
                digitalWrite(led12, LOW);
	}
}
//======================================================================================================
//	Set Timer SW Bedroom and FrontDoor
void SWB5_Timer_ON()
{
	if( SWB5hourOn == cpmhour && SWB5minOn == cpmmin )
	{
                SW1_flag = 1;                   
                digitalWrite(led, HIGH); 
                SW2_flag = 1;                   
                digitalWrite(led1, HIGH);
                
                SW3_flag = 1;                   
                digitalWrite(relay, LOW);     
                SW4_flag = 1;                   
                digitalWrite(relay1, LOW); 
	}
}

void SWB5_Timer_OFF()
{
	if( SWB5hourOff == cpmhour && SWB5minOff == cpmmin )
	{
		SW1_flag = 0;                   
                digitalWrite(led, LOW); 
                SW2_flag = 0;                   
                digitalWrite(led1, LOW);
                
                SW3_flag = 0;                   
                digitalWrite(relay, HIGH);     
                SW4_flag = 0;                   
                digitalWrite(relay1, HIGH);   
	}
}
//=======================================End B===============================================================

//========================================Start T==============================================================
//	Set Timer SW  Toilet and Saloon
void SWT_Timer_ON()
{
	if( SWThourOn == cpmhour && SWTminOn == cpmmin )
	{
                SW5_flag = 1;                   
                digitalWrite(led2, HIGH);
                
                SW6_flag = 1;                   
                digitalWrite(led3, HIGH);
                SW7_flag = 1;                   
                digitalWrite(led4, HIGH);
                SW8_flag = 1;                   
                digitalWrite(led5, HIGH);
                SW13_flag = 1;
                digitalWrite(led10, HIGH); 
                SW14_flag = 1;
                digitalWrite(led11, HIGH);
	}
}

void SWT_Timer_OFF()
{
	if( SWThourOff == cpmhour && SWTminOff == cpmmin )
	{
                SW5_flag = 0;                   
                digitalWrite(led2, LOW);
                
                SW6_flag = 0;                   
                digitalWrite(led3, LOW);
                SW7_flag = 0;                   
                digitalWrite(led4, LOW);
                SW8_flag = 0;                   
                digitalWrite(led5, LOW);
                SW13_flag = 0;
                digitalWrite(led10, LOW); 
                SW14_flag = 0;
                digitalWrite(led11, LOW);
	}
}

//======================================================================================================
//	Set Timer SW Toilet and Cook
void SWT1_Timer_ON()
{
	if( SWT1hourOn == cpmhour && SWT1minOn == cpmmin )
	{
                SW5_flag = 1;                   
                digitalWrite(led2, HIGH);
                
                SW11_flag = 1;
                digitalWrite(led8, HIGH); 
                SW12_flag = 1;
                digitalWrite(led9, HIGH);  
	}
}

void SWT1_Timer_OFF()
{
	if( SWT1hourOff == cpmhour && SWT1minOff == cpmmin )
	{
		SW5_flag = 0;                   
                digitalWrite(led2, LOW);
                
                SW11_flag = 0;
                digitalWrite(led8, LOW); 
                SW12_flag = 0;
                digitalWrite(led9, LOW);
	}
}
//======================================================================================================
//	Set Timer SW Toilet and Office
void SWT2_Timer_ON()
{
	if( SWT2hourOn == cpmhour && SWT2minOn == cpmmin )
	{
                SW5_flag = 1;                   
                digitalWrite(led2, HIGH);
                
                SW9_flag = 1;                   
                digitalWrite(led6, HIGH);
                SW10_flag = 1;
                digitalWrite(led7, HIGH);
	}
}

void SWT2_Timer_OFF()
{
	if( SWT2hourOff == cpmhour && SWT2minOff == cpmmin )
	{
		SW5_flag = 0;                   
                digitalWrite(led2, LOW);
                
                SW9_flag = 0;                   
                digitalWrite(led6, LOW);
                SW10_flag = 0;
                digitalWrite(led7, LOW);
	}
}
//======================================================================================================
//	Set Timer SW Toilet and Park
void SWT3_Timer_ON()
{
	if( SWT3hourOn == cpmhour && SWT3minOn == cpmmin )
	{
                SW5_flag = 1;                   
                digitalWrite(led2, HIGH);
                
                SW15_flag = 1;
                digitalWrite(led12, HIGH);
	}
}

void SWT3_Timer_OFF()
{
	if( SWT3hourOff == cpmhour && SWT3minOff == cpmmin )
	{
		SW5_flag = 0;                   
                digitalWrite(led2, LOW);
                
                SW15_flag = 0;
                digitalWrite(led12, LOW);
	}
}
//======================================================================================================
//	Set Timer SW Toilet and Front Door
void SWT4_Timer_ON()
{
	if( SWT4hourOn == cpmhour && SWT4minOn == cpmmin )
	{
               SW5_flag = 1;                   
               digitalWrite(led2, HIGH);
               
               SW3_flag = 1;                   
               digitalWrite(relay, LOW);     
               SW4_flag = 1;                   
               digitalWrite(relay1, LOW);
	}
}

void SWT4_Timer_OFF()
{
	if( SWT4hourOff == cpmhour && SWT4minOff == cpmmin )
	{
		SW5_flag = 0;                   
                digitalWrite(led2, LOW);
                
                SW3_flag = 0;                   
                digitalWrite(relay, HIGH);     
                SW4_flag = 0;                   
                digitalWrite(relay1, HIGH);
	}
}
//=======================================End T===============================================================
//========================================Start S==============================================================
//	Set Timer SW Saloon and Cook
void SWS_Timer_ON()
{
	if( SWShourOn == cpmhour && SWSminOn == cpmmin )
	{
              SW6_flag = 1;                   
              digitalWrite(led3, HIGH);
              SW7_flag = 1;                   
              digitalWrite(led4, HIGH);
              SW8_flag = 1;                   
              digitalWrite(led5, HIGH);
              SW13_flag = 1;
              digitalWrite(led10, HIGH); 
              SW14_flag = 1;
              digitalWrite(led11, HIGH);  
              
              SW11_flag = 1;
              digitalWrite(led8, HIGH); 
              SW12_flag = 1;
              digitalWrite(led9, HIGH);
	}
}

void SWS_Timer_OFF()
{
	if( SWShourOff == cpmhour && SWSminOff == cpmmin )
	{
             SW6_flag = 0;                   
             digitalWrite(led3, LOW);
             SW7_flag = 0;                   
             digitalWrite(led4, LOW);
             SW8_flag = 0;                   
             digitalWrite(led5, LOW);
             SW13_flag = 0;
             digitalWrite(led10, LOW); 
             SW14_flag = 0;
             digitalWrite(led11, LOW);
          
             SW11_flag = 0;
             digitalWrite(led8, LOW); 
             SW12_flag = 0;
             digitalWrite(led9, LOW);   
	}
}

//======================================================================================================
//	Set Timer SW Saloon and Office 
void SWS1_Timer_ON()
{
	if( SWS1hourOn == cpmhour && SWS1minOn == cpmmin )
	{
             SW6_flag = 1;                   
             digitalWrite(led3, HIGH);
             SW7_flag = 1;                   
             digitalWrite(led4, HIGH);
             SW8_flag = 1;                   
             digitalWrite(led5, HIGH);
             SW13_flag = 1;
             digitalWrite(led10, HIGH); 
             SW14_flag = 1;
             digitalWrite(led11, HIGH);
             
             SW9_flag = 1;                   
             digitalWrite(led6, HIGH);
             SW10_flag = 1;
             digitalWrite(led7, HIGH);
                
	}
}

void SWS1_Timer_OFF()
{
	if( SWS1hourOff == cpmhour && SWS1minOff == cpmmin )
	{
              SW6_flag = 0;                   
              digitalWrite(led3, LOW);
              SW7_flag = 0;                   
              digitalWrite(led4, LOW);
              SW8_flag = 0;                   
              digitalWrite(led5, LOW);
              SW13_flag = 0;
              digitalWrite(led10, LOW); 
              SW14_flag = 0;
              digitalWrite(led11, LOW);
              
              SW9_flag = 0;                   
              digitalWrite(led6, LOW);
              SW10_flag = 0;
              digitalWrite(led7, LOW);
	}
}
//======================================================================================================
//	Set Timer SW Saloon and Park
void SWS2_Timer_ON()
{
	if( SWS2hourOn == cpmhour && SWS2minOn == cpmmin )
	{
            SW6_flag = 1;                   
            digitalWrite(led3, HIGH);
            SW7_flag = 1;                   
            digitalWrite(led4, HIGH);
            SW8_flag = 1;                   
            digitalWrite(led5, HIGH);
            SW13_flag = 1;
            digitalWrite(led10, HIGH); 
            SW14_flag = 1;
            digitalWrite(led11, HIGH);
        
            SW15_flag = 1;
            digitalWrite(led12, HIGH);    
	}
}

void SWS2_Timer_OFF()
{
	if( SWS2hourOff == cpmhour && SWS2minOff == cpmmin )
	{
	      SW6_flag = 0;                   
              digitalWrite(led3, LOW);
              SW7_flag = 0;                   
              digitalWrite(led4, LOW);
              SW8_flag = 0;                   
              digitalWrite(led5, LOW);
              SW13_flag = 0;
              digitalWrite(led10, LOW); 
              SW14_flag = 0;
              digitalWrite(led11, LOW);
              
              SW15_flag = 0;
              digitalWrite(led12, LOW); 
	}
}
//======================================================================================================
//	Set Timer SW Saloon and Front Door
void SWS3_Timer_ON()
{
	if( SWS3hourOn == cpmhour && SWS3minOn == cpmmin )
	{
             SW6_flag = 1;                   
             digitalWrite(led3, HIGH);
             SW7_flag = 1;                   
             digitalWrite(led4, HIGH);
             SW8_flag = 1;                   
             digitalWrite(led5, HIGH);
             SW13_flag = 1;
             digitalWrite(led10, HIGH); 
             SW14_flag = 1;
             digitalWrite(led11, HIGH);
          
             SW3_flag = 1;                   
             digitalWrite(relay, LOW);     
             SW4_flag = 1;                   
             digitalWrite(relay1, LOW);  
	}
}

void SWS3_Timer_OFF()
{
	if( SWS3hourOff == cpmhour && SWS3minOff == cpmmin )
	{
	      SW6_flag = 0;                   
              digitalWrite(led3, LOW);
              SW7_flag = 0;                   
              digitalWrite(led4, LOW);
              SW8_flag = 0;                   
              digitalWrite(led5, LOW);
              SW13_flag = 0;
              digitalWrite(led10, LOW); 
              SW14_flag = 0;
              digitalWrite(led11, LOW);
              
              SW3_flag = 0;                   
              digitalWrite(relay, HIGH);     
              SW4_flag = 0;                   
              digitalWrite(relay1, HIGH);
	}
}
//=======================================End S===============================================================
//========================================Start C==============================================================
//	Set Timer SW Cook and Office
void SWC_Timer_ON()
{
	if( SWChourOn == cpmhour && SWCminOn == cpmmin )
	{
            SW11_flag = 1;
            digitalWrite(led8, HIGH); 
            SW12_flag = 1;
            digitalWrite(led9, HIGH); 
           
            SW9_flag = 1;                   
            digitalWrite(led6, HIGH);
            SW10_flag = 1;
            digitalWrite(led7, HIGH); 
	}
}

void SWC_Timer_OFF()
{
	if( SWChourOff == cpmhour && SWCminOff == cpmmin )
	{
             SW11_flag = 0;
             digitalWrite(led8, LOW); 
             SW12_flag = 0;
             digitalWrite(led9, LOW);
           
             SW9_flag = 0;                   
             digitalWrite(led6, LOW);
             SW10_flag = 0;
             digitalWrite(led7, LOW);  
	}
}

//======================================================================================================
//	Set Timer SW Cook and Park 
void SWC1_Timer_ON()
{
	if( SWC1hourOn == cpmhour && SWC1minOn == cpmmin )
	{
             SW11_flag = 1;
             digitalWrite(led8, HIGH); 
             SW12_flag = 1;
             digitalWrite(led9, HIGH);
             
             SW15_flag = 1;
             digitalWrite(led12, HIGH);   
	}
}

void SWC1_Timer_OFF()
{
	if( SWC1hourOff == cpmhour && SWC1minOff == cpmmin )
	{
              SW11_flag = 0;
              digitalWrite(led8, LOW); 
              SW12_flag = 0;
              digitalWrite(led9, LOW);
              
              SW15_flag = 0;
              digitalWrite(led12, LOW); 
	}
}
//======================================================================================================
//	Set Timer SW Cook and Front Door
void SWC2_Timer_ON()
{
	if( SWC2hourOn == cpmhour && SWC2minOn == cpmmin )
	{
             SW11_flag = 1;
             digitalWrite(led8, HIGH); 
             SW12_flag = 1;
             digitalWrite(led9, HIGH);
             
             SW3_flag = 1;                   
             digitalWrite(relay, LOW);     
             SW4_flag = 1;                   
             digitalWrite(relay1, LOW);
	}
}

void SWC2_Timer_OFF()
{
	if( SWC2hourOff == cpmhour && SWC2minOff == cpmmin )
	{
	      SW11_flag = 0;
              digitalWrite(led8, LOW); 
              SW12_flag = 0;
              digitalWrite(led9, LOW);
              
              SW3_flag = 0;                   
              digitalWrite(relay, HIGH);     
              SW4_flag = 0;                   
              digitalWrite(relay1, HIGH);
	}
}
//=======================================End C===============================================================
//========================================Start O==============================================================
//	Set Timer SW Office and Park
void SWO_Timer_ON()
{
	if( SWOhourOn == cpmhour && SWOminOn == cpmmin )
	{
            SW9_flag = 1;                   
            digitalWrite(led6, HIGH);
            SW10_flag = 1;
            digitalWrite(led7, HIGH);
            
            SW15_flag = 1;
            digitalWrite(led12, HIGH);
	}
}

void SWO_Timer_OFF()
{
	if( SWOhourOff == cpmhour && SWOminOff == cpmmin )
	{
            SW9_flag = 0;                   
            digitalWrite(led6, LOW);
            SW10_flag = 0;
            digitalWrite(led7, LOW);
           
            SW15_flag = 0;
            digitalWrite(led12, LOW); 
	}
}

//======================================================================================================
//	Set Timer SW Office and Eront Door 
void SWO1_Timer_ON()
{
	if( SWO1hourOn == cpmhour && SWO1minOn == cpmmin )
	{
            SW9_flag = 1;                   
            digitalWrite(led6, HIGH);
            SW10_flag = 1;
            digitalWrite(led7, HIGH);
            
            SW3_flag = 1;                   
            digitalWrite(relay, LOW);     
            SW4_flag = 1;                   
            digitalWrite(relay1, LOW);    
	}
}

void SWO1_Timer_OFF()
{
	if( SWO1hourOff == cpmhour && SWO1minOff == cpmmin )
	{
            SW9_flag = 0;                   
            digitalWrite(led6, LOW);
            SW10_flag = 0;
            digitalWrite(led7, LOW);
            
            SW3_flag = 0;                   
            digitalWrite(relay, HIGH);     
            SW4_flag = 0;                   
            digitalWrite(relay1, HIGH);  
	}
}
//=======================================End O===============================================================
//========================================Start P==============================================================
//	Set Timer SW Park and Front Door 
void SWP_Timer_ON()
{
	if( SWPhourOn == cpmhour && SWPminOn == cpmmin )
	{
            SW15_flag = 1;
            digitalWrite(led12, HIGH);
            
            SW3_flag = 1;                   
            digitalWrite(relay, LOW);     
            SW4_flag = 1;                   
            digitalWrite(relay1, LOW);
	}
}

void SWP_Timer_OFF()
{
	if( SWPhourOff == cpmhour && SWPminOff == cpmmin )
	{
            SW15_flag = 0;
            digitalWrite(led12, LOW);
           
            SW3_flag = 0;                   
            digitalWrite(relay, HIGH);     
            SW4_flag = 0;                   
            digitalWrite(relay1, HIGH); 
	}
}
//=======================================End P===============================================================

void Check_Timer(){
	if(Timer1_flag == 1)
	{
		SW1_Timer_ON();
		SW1_Timer_OFF();
	}

	if(Timer2_flag == 1)
	{
		SW2_Timer_ON();
		SW2_Timer_OFF();
	}

	if(Timer3_flag == 1)
	{
		SW3_Timer_ON();
		SW3_Timer_OFF();
	}

	if(Timer4_flag == 1)
	{
		SW4_Timer_ON();
		SW4_Timer_OFF();
	}

	if(Timer5_flag == 1)
	{
		SW5_Timer_ON();
		SW5_Timer_OFF();
	}

	if(Timer6_flag == 1)
	{
		SW6_Timer_ON();
		SW6_Timer_OFF();
	}
        
        if(Timer7_flag == 1)
	{
		SW7_Timer_ON();
		SW7_Timer_OFF();
	}
//B
        if(TimerB_flag == 1)
	{
		SWB_Timer_ON();
		SWB_Timer_OFF();
	}
        if(TimerB1_flag == 1)
	{
		SWB1_Timer_ON();
		SWB1_Timer_OFF();
	}
         if(TimerB2_flag == 1)
	{
		SWB2_Timer_ON();
		SWB2_Timer_OFF();
	}
         if(TimerB3_flag == 1)
	{
		SWB3_Timer_ON();
		SWB3_Timer_OFF();
	}
         if(TimerB4_flag == 1)
	{
		SWB4_Timer_ON();
		SWB4_Timer_OFF();
	}
         if(TimerB5_flag == 1)
	{
		SWB5_Timer_ON();
		SWB5_Timer_OFF();
	}
//end B

//T
        if(TimerT_flag == 1)
	{
		SWT_Timer_ON();
		SWT_Timer_OFF();
	}
        if(TimerT1_flag == 1)
	{
		SWT1_Timer_ON();
		SWT1_Timer_OFF();
	}
        if(TimerT2_flag == 1)
	{
		SWT2_Timer_ON();
		SWT2_Timer_OFF();
	}
        if(TimerT3_flag == 1)
	{
		SWT3_Timer_ON();
		SWT3_Timer_OFF();
	}
        if(TimerT4_flag == 1)
	{
		SWT4_Timer_ON();
		SWT4_Timer_OFF();
	}
//end T

//S
        if(TimerS_flag == 1)
	{
		SWS_Timer_ON();
		SWS_Timer_OFF();
	}
        if(TimerS1_flag == 1)
	{
		SWS1_Timer_ON();
		SWS1_Timer_OFF();
	}
        if(TimerS2_flag == 1)
	{
		SWS2_Timer_ON();
		SWS2_Timer_OFF();
	}
        if(TimerS3_flag == 1)
	{
		SWS3_Timer_ON();
		SWS3_Timer_OFF();
	}
//end S
//C
        if(TimerC_flag == 1)
	{
		SWC_Timer_ON();
		SWC_Timer_OFF();
	}
        if(TimerC1_flag == 1)
	{
		SWC1_Timer_ON();
		SWC1_Timer_OFF();
	}
        if(TimerC2_flag == 1)
	{
		SWC2_Timer_ON();
		SWC2_Timer_OFF();
	}
//end C
//O
        if(TimerO_flag == 1)
	{
		SWO_Timer_ON();
		SWO_Timer_OFF();
	}
        if(TimerO1_flag == 1)
	{
		SWO1_Timer_ON();
		SWO1_Timer_OFF();
	}
//end O
//P
        if(TimerP_flag == 1)
	{
		SWP_Timer_ON();
		SWP_Timer_OFF();
	}
//end P

}

