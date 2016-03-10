void Nebulizadores() {
  
  DateTime myRTC = RTC.now();
  Hr = (myRTC.hour());

  stateRg = EEPROM.read(20);  // estado sensor rega
  delay(50);
  I = EEPROM.read(30);        //intervalo de rega
  delay(50);
  t = EEPROM.read(1);         //tempo de rega
  delay(50);
  

  Int = I * 60 * 1000; //milisegundos
  delay(50);
  
  //b = t * 1000;        //milisegundos
  //delay(50);

  if ( stateRg == 1) {
    if (H >= 9 && H <= 21 && currentMillisHM == 0) {     //3600000 = 1 hora
      lcd.clear();
      lcd.print(F("TESTE REGA..."));
      lcd.setCursor(0, 1);
      lcd.print(F("...MODO AUTO!"));

      digitalWrite(RL3_NEB, LOW);
      delay(t * 1000);
      currentMillisHM = millis();

      DateTime now = RTC.now();
      EEPROM.write(50, now.day());
      EEPROM.write(60, now.month());
      EEPROM.write(70, now.year());
      EEPROM.write(80, now.hour());
      EEPROM.write(90, now.minute());

      digitalWrite(RL3_NEB, HIGH);
    } else {
      digitalWrite(RL3_NEB, HIGH);
    }

    if (H >= 8 && H <= 21 && currentMillisHM + Int <= millis() ) {
      lcd.clear();
      lcd.print(F("REGA EM..."));
      lcd.setCursor(0, 1);
      lcd.print(F("...MODO AUTO!"));

      digitalWrite(RL3_NEB, LOW);
      delay(t * 1000);                                                     // 5 minutos
      currentMillisHM = millis();

      DateTime now = RTC.now();
      EEPROM.write(50, now.day());
      EEPROM.write(60, now.month());
      EEPROM.write(70, now.year());
      EEPROM.write(80, now.hour());
      EEPROM.write(90, now.minute());
      digitalWrite(RL3_NEB, HIGH);
      delay(1000);

    }
    else {
      digitalWrite(RL3_NEB, HIGH);

    }

  
}
  
  
  
  
  
  
  
}
