#define ECHOPIN 10 // Pin to receive echo pulse
#define TRIGPIN 9 // Pin to send trigger pulse

#define ECHOPIN1 11 // Pin to receive echo pulse
#define TRIGPIN1 12 // Pin to send trigger pulse

#include <dht.h>
dht DHT;
#define DHT11_PIN 8

#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
 Serial.begin(9600); //
 pinMode(ECHOPIN, INPUT);
 pinMode(TRIGPIN, OUTPUT);
 
 pinMode(ECHOPIN1, INPUT);
 pinMode(TRIGPIN1, OUTPUT);

 lcd.begin(16, 2);
 lcd.print("hello, Sahil!");
}

void loop(){

//  if(10) Serial.println("yo");
//  delay(1000);

  //sr05_1
 digitalWrite(TRIGPIN, LOW); // Set the trigger pin to low for 2uS
 delayMicroseconds(2);
 digitalWrite(TRIGPIN, HIGH); // Send a 10uS high to trigger ranging
 delayMicroseconds(10);
 digitalWrite(TRIGPIN, LOW); // Send pin low again
 int distance = pulseIn(ECHOPIN, HIGH); // Read in times pulse
 distance= distance/58; // Calculate distance from time of pulse
 Serial.print("Sensor 1: ");
 Serial.println(distance); 
 delay(200); // Wait 50mS before next ranging

  //sr05_2
 digitalWrite(TRIGPIN1, LOW); // Set the trigger pin to low for 2uS
 delayMicroseconds(2);
 digitalWrite(TRIGPIN1, HIGH); // Send a 10uS high to trigger ranging
 delayMicroseconds(10);
 digitalWrite(TRIGPIN1, LOW); // Send pin low again
 int distance1 = pulseIn(ECHOPIN1, HIGH); // Read in times pulse
 distance1= distance1/58; // Calculate distance from time of pulse
 Serial.print("Sensor 2: ");
 Serial.println(distance1); 
 delay(200); // Wait 50mS before next ranging

  //dht
 int chk = DHT.read11(DHT11_PIN);
 float t = DHT.temperature;
 float h = DHT.humidity;
 Serial.print("Temperature = ");
 Serial.println(t);
 Serial.print("Humidity = ");
 Serial.println(h);
 delay(1000);

  //lcd
 if(distance<15 || distance1<15){
    lcd.clear();
    lcd.print("BEWARE! Object");
    lcd.setCursor(0, 1);
    lcd.print("at distance: ");
    lcd.print(min(distance,distance1));
  }
 else{
   lcd.clear();
   lcd.print("TEMP:     ");
   lcd.print(t);
   lcd.setCursor(0, 1);
   lcd.print("Humidity: ");
   lcd.print(h);
 }
 
}
