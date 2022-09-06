#include <SoftwareSerial.h>;
#define relayPin 12
#define indPin 13

SoftwareSerial serial(2,3);
String resp;
char c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serial.begin(9600);
  pinMode(relayPin, OUTPUT);

  //start with off the light
  digitalWrite(relayPin, HIGH);
}

void loop() {

  // put your main code here, to run repeatedly:
  while (serial.available() > 0){
    delay(10); 
    resp += serial.readStringUntil('\n'); 
  } 

  if (resp.length() > 0){ 
    String data =  resp. c_str();
    data.trim();   // remove any \r \n whitespace at the end of the String
     
    if (data=="/led_on"){
      Serial.println("turning on led");
      digitalWrite(relayPin, LOW);
    }else if (data=="/led_off"){
      Serial.println("turning off led");
      digitalWrite(relayPin, HIGH);
    }else{
      Serial.print("unkown command "); 
      Serial.println(resp); 
    }
    
    resp = "";
  }
}
