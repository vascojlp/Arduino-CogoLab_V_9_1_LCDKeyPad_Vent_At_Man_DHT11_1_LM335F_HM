

/////  OK COM KEYPAD, VENTILACAO MANUAL E AUTO, SONDA TEMPERATURA MANUAL E AUTO !!! 

//--- BIBLIOTECAS 
#include <LiquidCrystal.h> 
#include <dht.h>
#include <Wire.h>
#include <RTClib.h>  
#include "Variaveis.h"
#include <Event.h>
#include <Timer.h>
#include <EEPROM.h>

//--- Inicializacao dos Sensores 
dht DHT;                                        
RTC_DS1307 RTC;

//--- DEFINICAO DE PINOS 
// Analog Pins
#define DHT11_1 A1       // Sala de Incuba #2
#define DHT11_2 A2        // Sala de Laboratorio#2
#define LM335_PIN   A3      // PSonda Temp. Laboratorio#2
#define DHT11_3 A4        // Sala de incubaÃ#1

// digital pins
#define RL1_TPAINC 2 
#define RL2_HMINC  3
#define RL3_NEB      12          //Humidade do ar
//#define RL4_?????  11



//--- LCD Key Pad Panel 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//--- KEYPAD
// define some values used by the panel and buttons
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5



//--- RTC - Definicao Chars 
const int DS1307 = 0x68; // Address of DS1307 see data sheets
const char* days[] =
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* months[] =
{"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};
 
byte second = 0;
byte minute = 0;
byte hour = 0;
byte weekday = 0;
byte monthday = 0;
byte month = 0;
byte year = 0;

//--- VOID SETUP 
void setup() {
  
  Serial.begin(9600); 
  lcd.begin(16, 2);                    // start the library
  lcd.setCursor(0,0);

  // Inicializacao do RTC
  Wire.begin();
  RTC.begin(); 

  //--- Boot
  Serial.println(F("CogusLab V9.0"));
  Serial.print(F("\n"));
  delay(1000);
  
  lcd.setCursor(0,0);                  //Situamos o cursor no caracter 0, linha 
  lcd.print(F("BOOTING..."));
  delay(500); 
  lcd.clear();
  lcd.print(F("BOOTING......"));
  delay(500); 
  lcd.clear();
  lcd.print(F("BOOTING........."));
  delay(500);   
  lcd.clear();                  
  lcd.print(F("COGUSLAB V9.0"));
  delay(2000);    
 
 tv = EEPROM.read(10);    //tempo ventilacao
 delay(10);
 if (tv > 30 ) {
  tv = 5;    
    } 
  if ( tv < 5){
     tv = 5;
    } 
 a = tv * 60 * 1000;
 
 
 stateRg = EEPROM.read(20);  // estado sensor rega
 delay(50);
  
  I = EEPROM.read(30);        //intervalo de rega
  delay(50);
  
  t = EEPROM.read(1);
  delay(50);
  if (t <= 0 ) {
    t = 3;
    EEPROM.write(1, t);
    delay(50);
    }
  
  //--- Config values
 Config();            
             
//--- DESMARCAR PARA ACERTAR A HORA 
//Acertar_Hora();

  // analog pins
  pinMode(DHT11_1,INPUT);
  pinMode(DHT11_2,INPUT);
  pinMode(DHT11_3,INPUT);
  pinMode(LM335_PIN, INPUT);  
   
  // digital pins
  pinMode(RL1_TPAINC,OUTPUT);
  pinMode(RL2_HMINC,OUTPUT); 
  pinMode(RL3_NEB , OUTPUT);
  
  digitalWrite(RL3_NEB , HIGH);
  digitalWrite(RL1_TPAINC,HIGH);
  digitalWrite(RL2_HMINC,HIGH);
}

//--- VOID LOOP 
void loop() {

  //--- DATA E HORA 
    Data_Print();
    Keypad();
    Nebulizadores();
    Keypad();
    Ventilacao();
    Keypad();
   
  //--- SENSOR TEMPERATURA INCUBAÃ 
  Temperatura_Incubacao();
  Keypad();
  
   //--- SENSOR HUMIDADE INCUBA 
  Humidade();
  Keypad();
  
  //--- SENSOR TEMPERATURA LM35 
  LM335_temp(); 
  Keypad();

}

//--- FIM VOID LOOP 
 byte decToBcd(byte val) {
  return ((val/10*16) + (val%10));
}
byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}

//---
void setTime() {
 
  Serial.print(F("Please enter the current year, 00-99. - "));
  year = readByte();
  Serial.println(year);
  Serial.print(F("Please enter the current month, 1-12. - "));
  month = readByte();
  Serial.println(months[month-1]);
  Serial.print(F("Please enter the current day of the month, 1-31. - "));
  monthday = readByte();
  Serial.println(monthday);
  Serial.println(F("Please enter the current day of the week, 1-7."));
  Serial.print(F("1 Sun | 2 Mon | 3 Tues | 4 Weds | 5 Thu | 6 Fri | 7 Sat - "));
  weekday = readByte();
  Serial.println(days[weekday-1]);
  Serial.print(F("Please enter the current hour in 24hr format, 0-23. - "));
  hour = readByte();
  Serial.println(hour);
  Serial.print(F("Please enter the current minute, 0-59. - "));
  minute = readByte();
  Serial.println(minute);
  second = 0;
  Serial.println(F("The data has been entered."));
 
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}

byte readByte() {
  while (!Serial.available()) delay(10);
  byte reading = 0;
  byte incomingByte = Serial.read();
  while (incomingByte != '\n') {
    if (incomingByte >= '0' && incomingByte <= '9')
      reading = reading * 10 + (incomingByte - '0');
    else;
    incomingByte = Serial.read();
  }
  Serial.flush();
  return reading;
}

//---
void printTime() {
  char buffer[3];
  readTime();
  Serial.print(days[weekday-1]);
  Serial.print(F(" "));
  Serial.print(months[month-1]);
  Serial.print(F(" "));
  Serial.print(monthday);
  Serial.print(F(", 20"));
  Serial.print(year);
  Serial.print(F(" "));
  /*if (hour > 12) {
    hour -= 12;
    AMPM = " PM";
  }
  else AMPM = " AM";*/
  Serial.print(hour);
  Serial.print(F(":"));
  sprintf(buffer, "%02d", minute);
  Serial.print(buffer);
  //Serial.println(AMPM);
}

//---
void readTime() {
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.endTransmission();
  Wire.requestFrom(DS1307, 7);
  second = bcdToDec(Wire.read());
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read());
  weekday = bcdToDec(Wire.read());
  monthday = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}

//--- FIM  DO PROGRAMA 







