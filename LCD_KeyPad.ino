void Keypad(){
  
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 

k = (analogRead(0) - adc_key_in);    //gives the button a slight range to allow for a little contact resistance
 
 
 //dOUBLE PRESS
 if (5 < abs(k)){
}

//NO Press
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 
if (adc_key_in > 1000){  
}
 
 
 /****************** VENTILACAO MANUAL ********************/
 //btnSELECT
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 
 if (adc_key_in >650 && adc_key_in < 850){
   lcd.clear(); 
   lcd.print(F("VENTAX ON..."));
   lcd.setCursor(0, 1);
   lcd.print(F("MODO MANUAL!"));
   digitalWrite(RL1_TPAINC, LOW); 
   delay(a);                       
   digitalWrite(RL1_TPAINC, HIGH); 
 }
 
 
  /****************** REGA MANUAL ********************/
  //btnLEFT
  adc_key_in = 0;
  adc_key_in = analogRead(0);    // read the value from the sensor
  if (adc_key_in >450 && adc_key_in < 650){ 
    lcd.clear();
    lcd.print(F("NEBULIZADOR..."));
    lcd.setCursor(0, 1);
    lcd.print(F("MODO MANUAL!"));
    digitalWrite(RL3_NEB, LOW);
    delay(t * 1000);
    digitalWrite(RL3_NEB, HIGH);
    delay(1000);
  }
 
  /****************** Medir Temperatura ********************/
 //  btnRIGTH
  adc_key_in = 0;
  adc_key_in = analogRead(0);    // read the value from the sensor
  if (adc_key_in < 50) {
     LM335_temporizado();
   }
 
 
 
  /****************** Prog tempo ventilacao ********************/
//btnUP
  adc_key_in = 0;
  adc_key_in = analogRead(0);    // read the value from the sensor
  if (adc_key_in > 50 && adc_key_in < 250) {
     btstate = 1;
     Prog_Time();
   }
 
 
  /****************** PROGRAMACAO REGA ********************/
  //  btnDOWN
  adc_key_in = 0;
  adc_key_in = analogRead(0);    // read the value from the sensor
  if (adc_key_in > 250 && adc_key_in < 450) {
    btstate = 1;
    Prog_Nebulizadores();
  }
  
  }
 








