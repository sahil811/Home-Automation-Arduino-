#include<SoftwareSerial.h>
SoftwareSerial BT(10,11);
int btread;
void setup()
{
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Bluetooth AT command mode");
}
void loop()
{
  if(BT.available())
   {
     btread=BT.read();
    Serial.write(btread);
    if(btread=='1')
    digitalWrite(6,HIGH);
    else if(btread=='0')
    digitalWrite(6,LOW);
   } 
  if(Serial.available())
    BT.write(Serial.read());
}

