#include <Arduino.h>
#include <Streaming.h>
#include <SoftwareSerial.h>

SoftwareSerial WiFly(8, 9);

void setup()
{
  Serial.begin(9600);
  Serial.println("WiFly Terminal. Entering command mode. Send $$$ w/o CR");
  WiFly.begin(9600);
  
  delay(1000);

  WiFly.write('$');
  WiFly.write('$');
  WiFly.write('$');
}

void loop()
{
  while(WiFly.available())
  {
    Serial.write(WiFly.read());
  }
  
  if(Serial.available())
  {
    char c = Serial.read();
    
    WiFly.write(c);
    WiFly.flush();
    
    Serial.write(c); //echo
    
  }
}

