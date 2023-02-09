/*  
 
*/
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

 

int sensor = 2;               // sensor pin //
int state = HIGH;             // no motion state = low
int val = 0;                //the sensor status (value)

void setup() {
  mySoftwareSerial.begin(9600);
   Serial.begin(115200);                      
    pinMode(sensor, INPUT);                      
     

  //Use softwareSerial to communicate with MP3
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  //Set volume value (From 0 to 30)
   myDFPlayer.volume(25);
}  
////////////////////////////////////////////////////////////////////////////////////////////

void loop(){
  val = digitalRead(sensor);  
    if (val == HIGH) {          
		Serial.println("Sensor Activated");
		myDFPlayer.play(1);                        
		delay(5000); // record play time //  
        
    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;       // update variable state to HIGH
    }
  }
  else {
                    
      delay(1000);            
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
