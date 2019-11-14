//Henry's Bench
// HC-SR501 Motion Detector
// Sample Sketch

//int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501

int pirValue; // Place to store read PIR Value


void setup() {

  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  //pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  //digitalWrite(ledPin, LOW);
  
  
  
}

void loop() {
  pirValue = digitalRead(pirPin);
  //digitalWrite(ledPin, pirValue);
  Serial.print("Reading = ");
  Serial.println(pirValue);


}
