//APSC 200 SECTION 206 GROUP 2
//EMILY GIBBONS
//SHIYAN BOXER
//PUJIAN YANG
//JARED YEATES
//DAN JANG

//don't forget, include dht library
#include <DHT.h>
#define DHTTYPE DHT22

#define dataPin 9 // Defines pin number to which the sensor is connected
DHT dht(dataPin, DHTTYPE); // Creats a DHT object

int pirPin = 10; //pin for PIR
int pirValue; //storage for PIR readings
int buzzer = 8; //buzzer on pin 8
int fsrPinOne = A0; //fsr on analog pins 0, 1
int fsrPinTwo = A1;
int fsrReadingOne;
int fsrReadingTwo;

int LEDpinOne = 2; //LED pins on 2, 3, 4
int LEDpinTwo = 3;
int LEDpinThree = 4;

int buttonOne = 5; //buttons on pin 5, 6, 7
int buttonTwo = 6;
int buttonThree = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

  pinMode(buzzer, OUTPUT);
  pinMode(LEDpinOne, OUTPUT);
  pinMode(LEDpinTwo, OUTPUT);
  pinMode(LEDpinThree, OUTPUT);
  pinMode(buttonOne, INPUT_PULLUP);
  pinMode(buttonTwo, INPUT_PULLUP);
  pinMode(buttonThree, INPUT_PULLUP);
  pinMode(pirPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int ignition = digitalRead(buttonOne);
  int rearDoor = digitalRead(buttonTwo);
  int reset = digitalRead(buttonThree); //look up how to implement a reset button
  // skel code: if{ignition == LOW)
  //              do something; 

  //these are for the outputs
  tone(buzzer, [freq]);
  delay([time the buzzer is on for]);
  
  analogWrite(LEDpin, LEDbrightness); //turns on LED on the pin

  //reading values
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);

  pirValue = digitalRead(pirPin);
  Serial.print("Reading = ");
  Serial.println(pirValue);

  float t = dht.readTemperature(); // Gets the values of the temperature
  float h = dht.readHumidity(); // Gets the values of the humidity

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(2000); // Delays 2 secods, as the DHT22 sampling rate is 0.5Hz

  //logic goes here
  

}
