/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */

const int buzzer = 8; //buzzer to arduino pin 8
int fsrPinOne = A0;
int fsrPinTwo = A1; // FSR is connected to analog 0, 1
int LEDpinOne = 2;      // connect Red LED to pin 2,1,4
int LEDpinTwo = 1;
int LEDpinThree = 4;
int fsrReadingOne;
int fsrReadingTwo; // the analog reading from the FSR resistor divider
int LEDbrightnessOne;
int LEDbrightnessTwo;
int LEDbrightnessThree;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpinOne, OUTPUT);
  pinMode(LEDpinTwo, OUTPUT);
  pinMode(LEDpinThree, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
 
void loop(void) {
  fsrReadingOne = analogRead(fsrPinOne);
  fsrReadingTwo = analogRead(fsrPinTwo);
  Serial.print("Analog reading 1= ");
  Serial.println(fsrReadingOne);
  Serial.print("Analog reading 2= ");
  Serial.println(fsrReadingTwo);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightnessOne = map(fsrReadingOne, 0, 1023, 0, 255);
  LEDbrightnessTwo = map(fsrReadingTwo, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  
  analogWrite(LEDpinOne, LEDbrightnessOne);
  analogWrite(LEDpinTwo, LEDbrightnessTwo);
  analogWrite(LEDpinThree, LEDbrightnessTwo);
  

 //tone(buzzer, fsrReadingOne);
  delay(1000);
}
