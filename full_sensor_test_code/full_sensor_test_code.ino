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

#define tooHot 30

int pirPin = 10; //pin for PIR
int pirValue; //storage for PIR readings
int buzzer = 8; //buzzer on pin 8
int fsrPinOne = A0; //fsr on analog pins 0, 1
int fsrPinTwo = A1;
int fsrReadingOne;
int fsrReadingTwo;

int LEDpinOne = 2; //LED pins on 2, 1, 4
int LEDpinTwo = 1;
int LEDpinThree = 4;

int buttonOne = 5; //buttons on pin 5, 6, 7
int buttonTwo = 6;
int buttonThree = 7;

int groupNum = 2;
int alertVar;
String Trigger_1Var = "its"; 
String Trigger_2Var = "too"; 
String Trigger_3Var = "hot";

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
  // skel code: if{ignition == LOW)

  //reading values
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);

  pirValue = digitalRead(pirPin);
  Serial.print("Reading = ");
  Serial.println(pirValue);

  float t = dht.readTemperature(); // Gets the values of the temperature
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.println(" % ");
  delay(2000); // Delays 2 secods, as the DHT22 sampling rate is 0.5Hz

  //logic goes here
  while(fsrReading > 500 && pirValue == 1 && temp > tooHot)
    //button logic goes here
    /*
     * if button one gets pressed, starts a timer. 
     * if the timer runs out, send the call to wifi code, make buzzer go off.
     * alertVar = 1;
     * wifiPost(groupNum, alertVar, Trigger_1Var, Trigger_2Var, Trigger_3Var)
     * if button two is pressed, do nothing
     */
    //these are for the outputs
  tone(buzzer, [freq]);
  delay([time the buzzer is on for]);
  analogWrite(LEDpin, LEDbrightness); //turns on LED on the pin

  

}
