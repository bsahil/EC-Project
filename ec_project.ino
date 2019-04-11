#include "DHT.h"
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial BTserial(7,8); // RX | TX
byte degree_symbol[8] =
 {
 0b00111,
 0b00101,
 0b00111,
 0b00000,
 0b00000,
 0b00000,
 0b00000,
 0b00000
 };
#define DHTPIN 10 // what pin we're connected to
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup(){
 lcd.begin(16, 2);
 lcd.print("Temp = ");
 lcd.setCursor(0,1);
 lcd.print("Humidity = ");
 lcd.createChar(1, degree_symbol);
 lcd.setCursor(9,0);
 lcd.write(1);
 // Wait a few seconds between measurements.
 delay(2000);
 // Reading temperature or humidity takes about 250 milliseconds!
 // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 int h = dht.readHumidity();
 // Read temperature as Celsius (the default)
 int t = dht.readTemperature();
 // Check if any reads failed and exit early (to try again).
 if (isnan(h) || isnan(t)) {
 lcd.print("Failed!");
 return;
 lcd.print("C");
 lcd.setCursor(13,1);
 lcd.print("%");
 dht.begin();
 BTserial.begin(9600);
}
void loop() {
 }
 lcd.setCursor(7,0);
 lcd.print(t);
 lcd.setCursor(11,1);
 lcd.print(h);
 BTserial.print(t);
 BTserial.write(176); //character code for degree symbol
 BTserial.print("C");
 BTserial.print(",");
 BTserial.print(h);
 BTserial.print("%");
 BTserial.print(";");
 }
