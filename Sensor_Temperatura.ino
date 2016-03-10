void Temperatura_Incubacao() {
  
  DHT.read11(DHT11_1);     
  TPA1_value = DHT.temperature -1;
  
  /*DHT.read11(DHT11_2);     
  TPA2_value = DHT.temperature;
  
  DHT.read11(DHT11_3);     
  TPA3_value = DHT.temperature;
  */
  
  DateTime myRTC = RTC.now();
  H = 0;
  H = (myRTC.hour());
  
  lcd.clear();                                     
  lcd.print(F("TEMP. INCU. #2:"));
  lcd.setCursor(0, 1);
  lcd.print(TPA1_value);
  lcd.print(F(" Graus C."));
  delay(4000);
  
  /*
  
  lcd.clear();                                     
  lcd.print(F("TEMP. INCU. #1:"));
  lcd.setCursor(0, 1);
  lcd.print(TPA3_value);
  lcd.print(F(" Graus C."));
  delay(4000);
  */

  }
 











