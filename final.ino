
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266_SSL.h>
int sensorpin=A0;
int sensorvalue=0;
int outputvalue=0;

char auth[] = "7zGxwUna9D9CTW9jolAz767x7kP6D3F7";
char ssid[] = "smart";
char pass[] = "123456789";

void setup()
{
  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(16,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop()
{
  sensorvalue=analogRead(sensorpin);
  outputvalue=map(sensorvalue,0,1023,0,100); //100,0
  delay(1000);

  if(outputvalue>74)
  {
       Serial.println("water your plant");
       Serial.print(outputvalue);
       Blynk.notify("water your plant");
       digitalWrite(16,HIGH);
       digitalWrite(4,LOW);
       delay(5000); 
  }
  else if(outputvalue<45)
  {
       Serial.println("soil is wet enough to water");
       Serial.print(outputvalue);
       
      digitalWrite(16,LOW);
      digitalWrite(4,HIGH);
      
      
      
  }
  
  Blynk.virtualWrite(V1,outputvalue);
  Blynk.run();
  
}
