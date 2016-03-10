void Data_Print()
{
   DateTime now = RTC.now();
    
    lcd.clear(); 
    lcd.print(now.day(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.year(),DEC);
    lcd.setCursor(0,1);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    delay(3500);
    
  
  lcd.clear();
  for(int i = 0; i<16; i++){
    lcd.setCursor(i, 0);
    lcd.print(F("*"));
    delay(100);
    }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("EST. ACTUAL RG.:"));
  lcd.setCursor(0, 2);
  stateRg = EEPROM.read(20);  // estado sensor rega
  lcd.print(stateRg);
  lcd.setCursor(5, 2);
  if (stateRg == 1 ) {
    lcd.print("Rega ON");
  } else {
    lcd.print("Rega OFF");
  }
  delay(3000);

  Keypad();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("TEMPO REGA:"));
  lcd.setCursor(0, 2);
  stateRg = EEPROM.read(20);  // estado sensor rega
  //t = EEPROM.read(b);         //tempo de rega
  lcd.print(t);
  lcd.setCursor(5, 2);
  lcd.print(F("(Segundos)"));
  delay(3000);

  Keypad();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("INTERVALO REGA:"));
  lcd.setCursor(0, 2);
  I = EEPROM.read(30);        //intervalo de rega
  lcd.print(I);
  lcd.setCursor(5, 2);
  lcd.print(F("(Minutos)"));
  delay(3000);
  
  Keypad();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("LAST EVENT RG:"));
  lcd.setCursor(0, 2);
  lcd.print (EEPROM.read(50));
  lcd.setCursor(3, 2);
  lcd.print(F("/"));
  lcd.setCursor(4, 2);
  lcd.print (EEPROM.read(60));
  lcd.print(F(" "));
  lcd.setCursor(10, 2);
  lcd.print (EEPROM.read(80));
  lcd.setCursor(12, 2);
  lcd.print(F(":"));
  lcd.setCursor(13, 2);
  lcd.print (EEPROM.read(90));
  delay(3000);

  Keypad();
  
  
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("TEMPO VENT:"));
  lcd.setCursor(0, 2);
  lcd.print (EEPROM.read(tv));
  lcd.print(tv);
  lcd.setCursor(5, 2);
  lcd.print(F("(Minutos)"));
  delay(3500); 
  
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("LAST EVENT:"));
  lcd.setCursor(0, 2);
  lcd.print (EEPROM.read(100));
  lcd.setCursor(3, 2);
  lcd.print(F("/"));
  lcd.setCursor(4, 2);
  lcd.print (EEPROM.read(110));
  lcd.setCursor(6, 2);
  lcd.print(F("/"));
  lcd.setCursor(7, 2);
  lcd.print (EEPROM.read(120));
  lcd.setCursor(9, 2);
  lcd.print(F(" "));
  lcd.setCursor(10, 2);
  lcd.print (EEPROM.read(130));
  lcd.setCursor(12, 2);
  lcd.print(F(":"));
  lcd.setCursor(13, 2);
  lcd.print (EEPROM.read(140));
  delay(3500); 
  
  lcd.clear();
  for(int i = 0; i<16; i++){
    lcd.setCursor(i, 0);
    lcd.print(F("*"));
    delay(100);
    }

}




