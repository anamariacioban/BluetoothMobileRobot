#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);  

void setup() {
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(38400);
  Serial.println("Enter AT Commands:");
  BTSerial.begin(38400); 

}

void loop() {
 if(Serial.available())           
   BTSerial.write(Serial.read());

 if(BTSerial.available())         
   Serial.write(BTSerial.read());   

}
