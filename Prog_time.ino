void Prog_Time() {
  
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- PROGRAMACAO -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("--TEMPO VENT.--  "));
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("TEMPO ACTUAL:"));
  lcd.setCursor(0, 2);
  lcd.print(t);
  lcd.setCursor(5, 2);
  lcd.print(F("(Minutos)"));
  
 while (btstate == 1) {
   
    delay(200);
    //btnUP  
    adc_key_in =0;
    adc_key_in = analogRead(0);    // read the value from the sensor 
    if (adc_key_in >50 && adc_key_in < 250){
      tv = tv+1;
      EEPROM.write(10, tv);
      delay (10);
      a = tv * 60 * 1000; 
      lcd.setCursor(0, 2);
      lcd.print(tv);
      delay(10);
      }
    
    delay(200); 
    //btnDOWN
    adc_key_in =0;
    adc_key_in = analogRead(0);    // read the value from the sensor 
     if (adc_key_in >250 && adc_key_in < 450){
       tv = tv-1;
       EEPROM.write(10, tv);
       delay(10);
       a = tv * 60 * 1000;
       lcd.setCursor(0, 2);
       lcd.print(tv);    
     }
   
   //btnSELECT
    adc_key_in =0;
    adc_key_in = analogRead(0);    // read the value from the sensor 
     if (adc_key_in >650 && adc_key_in < 850){
       tv = 5 ;
       EEPROM.write(1, tv);

       delay(10);
      
       lcd.clear(); 
       lcd.setCursor(0, 0);
       lcd.print(F("EEPROM CLEARED!"));
       delay (2000);
       lcd.clear();
       lcd.setCursor(0, 0); 
       lcd.print(F("TEMPO ACTUAL:"));
       lcd.setCursor(0, 2);
       lcd.print(tv);
       lcd.setCursor(5, 2);
       lcd.print(F("(Minutos)"));
       lcd.setCursor(0, 2);
       lcd.print(tv);
       }
       
   
    //btnRIGHT
    adc_key_in =0;
    adc_key_in = analogRead(0);    // read the value from the sensor 
     
     if (adc_key_in < 50){
       
       if (tv > 30 ) { 
       tv = 5; 
       
       lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
       lcd.print(F("***  ERROR  ***"));
       lcd.setCursor(0, 1);
       delay(1000);
       lcd.clear(); 
       lcd.print(F("TMP.VENT >30mnt."));  
       delay (4000);
     }
    
       if (tv == 0 ) {    
       tv = 5;   
       
       lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
       lcd.print(F("***  ERROR  ***"));
       lcd.setCursor(0, 1);
       delay(1000);
       lcd.clear(); 
       lcd.print(F("TMP.VENT =0mnt. "));  
       delay (4000);
     }  
    
       lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
       lcd.print(F("FIM PROGRAMACAO"));
       lcd.setCursor(0, 1);
       delay(2000);
       lcd.clear(); 
       lcd.print(F("TMP. VENT.ACTUAL:"));
       lcd.setCursor(0, 2);
       lcd.print(tv);
       lcd.setCursor(5, 2);
       lcd.print(F("(Minutos)"));
       delay(4000);
       btstate = 0 ;
       
   
     
   }   
}

}











