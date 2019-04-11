#define ECHOPIN 2 // Pin to receive echo pulse
#define TRIGPIN 3 // Pin to send trigger pulse

#define ECHOPIN1 4 // Pin to receive echo pulse
#define TRIGPIN1 5 // Pin to send trigger pulse

void setup(){
 Serial.begin(9600); //
 pinMode(ECHOPIN, INPUT);
 pinMode(TRIGPIN, OUTPUT);
 
 pinMode(ECHOPIN1, INPUT);
 pinMode(TRIGPIN1, OUTPUT);
}

void loop(){

  //sr05_1
 digitalWrite(TRIGPIN, LOW); // Set the trigger pin to low for 2uS
 delayMicroseconds(2);
 digitalWrite(TRIGPIN, HIGH); // Send a 10uS high to trigger ranging
 delayMicroseconds(10);
 digitalWrite(TRIGPIN, LOW); // Send pin low again
 int distance = pulseIn(ECHOPIN, HIGH); // Read in times pulse
 distance= distance/58; // Calculate distance from time of pulse
 Serial.println(distance); 
 delay(200); // Wait 50mS before next ranging

  //sr05_2
 digitalWrite(TRIGPIN1, LOW); // Set the trigger pin to low for 2uS
 delayMicroseconds(2);
 digitalWrite(TRIGPIN1, HIGH); // Send a 10uS high to trigger ranging
 delayMicroseconds(10);
 digitalWrite(TRIGPIN1, LOW); // Send pin low again
 distance = pulseIn(ECHOPIN1, HIGH); // Read in times pulse
 distance= distance/58; // Calculate distance from time of pulse
 Serial.print("fasd");
 Serial.println(distance); 
 delay(200); // Wait 50mS before next ranging

  //dht
 
}
