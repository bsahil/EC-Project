#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  float t = DHT.temperature;
  float h = DHT.humidity;
  Serial.print("Temperature = ");
  
  Serial.println(t);
  
  Serial.print("Humidity = ");
  Serial.println(h);
  delay(3000);
}
