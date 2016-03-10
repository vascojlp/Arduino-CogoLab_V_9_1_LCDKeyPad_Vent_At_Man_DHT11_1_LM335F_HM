void Humidade(){
  
  DHT.read11(DHT11_1);     
  HM1_value = DHT.humidity ;
  
  DHT.read11(DHT11_2);     
  HM2_value = DHT.humidity ;
  
  DHT.read11(DHT11_3);     
  HM3_value = DHT.humidity ;
  
  lcd.clear();                          
  lcd.print(F("HUMID. INCUB.#2:"));
  lcd.setCursor(0, 1);
  lcd.print(HM1_value);
  lcd.print(F(" (%)"));
  delay(4000);
  
  /*  
  lcd.clear();                          
  lcd.print(F("HUMIDADE INC.#1"));
  lcd.setCursor(0, 1);
  lcd.print(HM3_value);
  lcd.print(F(" (%)"));
  delay(4000);
  
  if(HM3_value < 75) {
    
   lcd.clear(); 
   lcd.print(F("NEBULIZAD.#1 ... "));
   lcd.setCursor(0, 1);
   lcd.print(F("MODO AUTO!"));
   digitalWrite(RL2_HMINC, LOW); 
   delay(60000);                        //3 minutos
   digitalWrite(RL2_HMINC, HIGH);    
    } else {
      digitalWrite(RL2_HMINC, HIGH);
      }
  */
  }











