void LM335_temporizado() {

  currentMillis_LM335 = millis();
  do
{
  sensorValue1 = analogRead(LM335_PIN);   //reads voltage on Pin A3
   sensorValue2 = analogRead(LM335_PIN);  
    sensorValue3 = analogRead(LM335_PIN);  
     sensorValue4 = analogRead(LM335_PIN);  
      sensorValue5 = analogRead(LM335_PIN);  
       sensorValue6 = analogRead(LM335_PIN);  
        sensorValue7 = analogRead(LM335_PIN);  
         sensorValue8 = analogRead(LM335_PIN);  
          sensorValue9 = analogRead(LM335_PIN);  
           sensorValue10 = analogRead(LM335_PIN);  
           
  sensorValue = (sensorValue1+sensorValue2+sensorValue3+sensorValue4+sensorValue5+sensorValue6+sensorValue7+sensorValue8+sensorValue9+sensorValue10)/10;
                         
  kelvinValue = ((sensorValue / 1024.0) * 5.0) * 100.0;     // convert Value to Kelvin
  celsiusValue = kelvinValue - 273.15; //273.15 ;           // convert Kelvin to Celsius
  
 // now print out the temperature               
  lcd.clear();                          
  lcd.print(F("TEMP. SONDA:"));
  lcd.setCursor(0, 1);
  lcd.print(celsiusValue);
  lcd.print(F(" Graus C."));
  delay(1500);
     
} while (currentMillis_LM335 + 60000 >= millis());
 
 } 











