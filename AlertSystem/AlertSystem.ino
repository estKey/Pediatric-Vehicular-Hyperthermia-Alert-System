#include <DHT.h>
#include <DHT_U.h>

#include <FlexiTimer2.h>

/**
  APSC 200 Section 206 Group 02
  EMILY GIBBONS
  SHIYAN BOXER
  PUJIAN YANG
  JARED YEATES
  DAN JANG
*/

#define DHTTYPE DHT22
#define LED_ONE_PIN = 1;
#define LED_TWO_PIN = 2; //LED pins on 2, 1, 4
#define LED_THREE_PIN = 4;
#define BTN_ONE_PIN = 5; //buttons on pin 5, 6, 7
#define BTN_TWO_PIN = 6;
#define BTN_THREE_PIN = 7;
#define BUZZER_PIN = 8; //buzzer on pin 8
#define DHT_SENSOR_PIN 9 // DHT
#define PIR_SENSOR_PIN = 10; //pin for PIR

int FSR_ONE_PIN, FSR_TWO_PIN;
DHT dht(dataPin, DHTTYPE);
void init_isr()
{
  cli();//stop interrupts

  //set timer2 interrupt every 128us
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 7.8khz increments
  OCR2A = 255;// = (16*10^6) / (7812.5*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  sei();//allow interrupts
  DDRC = 0xF7;//set A0-2 and A4-5 output, A3 input
  DDRB = 0xFF;//digital pins 8-13 output
}

void setup() {
  Serial.begin(9600);
  //  Serial.begin(57600);
  dht.begin();

  fsrPinOne = A0; //fsr on analog pins 0, 1
  fsrPinTwo = A1;
  pinMode(buzzer, OUTPUT);
  pinMode(LED_ONE_PIN, OUTPUT);
  pinMode(LED_ONE_PIN, OUTPUT);
  pinMode(LED_ONE_PIN, OUTPUT);
  pinMode(BTN_ONE_PIN, INPUT_PULLUP);
  pinMode(BTN_TWO_PIN, INPUT_PULLUP);
  pinMode(BTN_THREE_PIN, INPUT_PULLUP);
  pinMode(PIR_SENSOR_PIN, INPUT);
}

void loop() {
  int start = 0
              while (1)
  {
    int ignition = digitalRead(BTN_ONE_PIN);
    int rearDoor = digitalRead(BTN_ONE_PIN);
    int reset = digitalRead(BTN_THREE_PIN);

    int fsrReading = analogRead(fsrAnalogPin);
    float t = dht.readTemperature(); // Gets the values of the temperature
    float h = dht.readHumidity(); // Gets the values of the humidity

    if (ignition == HIGH)
    {
      start = 1;
    }
    delay(10);
  }
  Serial.println("Done.")
  delay(2000);
}
