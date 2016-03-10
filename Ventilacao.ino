void Ventilacao() { 

  DateTime myRTC = RTC.now();
  Hr = (myRTC.hour());
  
if (currentMillis <= 5000 && Hr >= 9 && Hr <= 20 ){      //3600000 = 1 hora  
//if (currentMillis <= 5000){      //3600000 = 1 hora  
      lcd.clear(); 
      lcd.print(F("TESTE VENTAX...")); 
      lcd.setCursor(0, 1);
      lcd.print(F("MODO AUTOMATICO!")); 
      digitalWrite(RL1_TPAINC, LOW);
      delay(5000);
      currentMillis = millis();
      DateTime now = RTC.now(); 
      EEPROM.write(100, now.day()); 
      EEPROM.write(110, now.month()); 
      EEPROM.write(120, now.year());
      EEPROM.write(130, now.hour());
      EEPROM.write(140, now.minute());} 
      else {
    digitalWrite(RL1_TPAINC, HIGH); }
    
  if (currentMillis + 1800000 <= millis() && Hr >= 9 && Hr <= 20){      //3600000 = 1 hora 
 //if (currentMillis + 1800000 <= millis() ){      //3600000 = 1 hora   
      lcd.clear(); 
      lcd.print(F("VENTAX ON..."));
      lcd.setCursor(0, 1);
      lcd.print(F("MODO AUTOMATICO!"));
      digitalWrite(RL1_TPAINC, LOW);
      a = tv * 60 * 1000;
      delay(a);                                                     // 5 minutos
      currentMillis = millis();
    
      DateTime now = RTC.now(); 
      EEPROM.write(100, now.day()); 
      EEPROM.write(110, now.month()); 
      EEPROM.write(120, now.year());
      EEPROM.write(130, now.hour());
      EEPROM.write(140, now.minute()); }
      else {
         digitalWrite(RL1_TPAINC, HIGH); }
   
    }










