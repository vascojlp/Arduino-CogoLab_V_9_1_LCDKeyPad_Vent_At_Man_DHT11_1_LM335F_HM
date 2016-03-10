//--- Sensor de Temperatura
int TPAINC_max;    //valor maximo de temperatura 
int TPAINC_min;
int TPAINC_med;
int TPA1_value;
int TPA2_value;
int TPA3_value;
int HM1_value;
int HM2_value;
int HM3_value;

int H;
int Hr;


int state = LOW;      // the current state of the output pin
int previous = LOW;    // the previous reading from the input pin
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

float sensorValue = 0; //Set the sensor values as a floating number
float sensorValue1 = 0;
float sensorValue2 = 0;
float sensorValue3 = 0;
float sensorValue4 = 0;
float sensorValue5 = 0;
float sensorValue6 = 0;
float sensorValue7 = 0;
float sensorValue8 = 0;
float sensorValue9 = 0;
float sensorValue10 = 0;

float kelvinValue = 0;
float celsiusValue = 0;

int adc_key_in;
int k;
unsigned long currentMillis = 0;
unsigned long currentMillis_LM335 = 0;
unsigned long currentMillisHM = 0;


int btstate = 0;
int EEsize = 1024;
unsigned long tv = 0;
unsigned long a = 0 ;
int btstateRg = 0;
int stateRg;
//unsigned long b = 0 ;
unsigned long I = 0;
unsigned long Int = 0;
unsigned long t = 0;










