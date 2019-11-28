/**
  APSC 200 Section 206 Group 02
  EMILY GIBBONS
  SHIYAN BOXER
  PUJIAN YANG
  JARED YEATES
  DAN JANG
*/
#include <DHT.h>
#include <DHT_U.h>


#define DHTTYPE DHT22
#define LED_ONE_PIN 2
#define LED_TWO_PIN 1 //LED pins on 2, 1, 4
#define LED_THREE_PIN 4
#define BTN_ONE_PIN 5 //buttons on pin 5, 6, 7
#define BTN_TWO_PIN 6
#define BTN_THREE_PIN 7
#define BUZZER_PIN 8 //buzzer on pin 8
#define DHT_SENSOR_PIN 9 // DHT
#define PIR_SENSOR_PIN 10 //pin for PIR

#define OBJECT_WEIGHT 600
#define TIME_LIMIT 100
#define TEMP_THRESHOLD 1
#define HUM_THRESHOLD 1

int FSR_ONE_PIN, FSR_TWO_PIN;
DHT dht(DHT_SENSOR_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  //  Serial.begin(57600);
  dht.begin();

  FSR_ONE_PIN = A0; //fsr on analog pins 0, 1
  FSR_TWO_PIN = A1;
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_ONE_PIN, OUTPUT);
  pinMode(LED_TWO_PIN, OUTPUT);
  pinMode(LED_THREE_PIN, OUTPUT);
  pinMode(BTN_ONE_PIN, INPUT_PULLUP);
  pinMode(BTN_TWO_PIN, INPUT_PULLUP);
  pinMode(BTN_THREE_PIN, INPUT_PULLUP);
  pinMode(PIR_SENSOR_PIN, INPUT);
}

void loop() {
  int start = 0;
  int safe = 0;
  int timer_counter = 0;
  while (1)
  {
    int ignition = digitalRead(BTN_ONE_PIN);
    int rearDoor = digitalRead(BTN_TWO_PIN);
    int reset = digitalRead(BTN_THREE_PIN);

    int fsr_one = analogRead(FSR_ONE_PIN);
    int fsr_two = analogRead(FSR_TWO_PIN);
    int isMoving = digitalRead(PIR_SENSOR_PIN);
    float t = dht.readTemperature(); // Gets the values of the temperature
    float h = dht.readHumidity(); // Gets the values of the humidity

    Serial.println(t);
    Serial.println(h);
    Serial.println(fsr_one);
    Serial.println(fsr_two);
    if (ignition == LOW && safe && (fsr_one > OBJECT_WEIGHT || fsr_two > OBJECT_WEIGHT || isMoving))
    {
      start = 1;
      digitalWrite(LED_ONE_PIN, HIGH);
      Serial.println("ignition");
    }
    if (start && !safe) timer_counter++;
    Serial.println(timer_counter);
    if (timer_counter >= TIME_LIMIT && t > TEMP_THRESHOLD && h > HUM_THRESHOLD) {
      Serial.println("Alert");
      safe = 0;
      digitalWrite(LED_ONE_PIN, LOW);
      digitalWrite(LED_TWO_PIN, HIGH);
      tone(BUZZER_PIN, 440);
    } else if (t > TEMP_THRESHOLD && h > HUM_THRESHOLD) Serial.println("Good ");
    if (rearDoor == LOW) {
      digitalWrite(LED_ONE_PIN, LOW);
      digitalWrite(LED_THREE_PIN, HIGH);
      tone(BUZZER_PIN, 0);
      timer_counter = 0;
      safe = 1;
      start = 0;
      Serial.println("Safe");
    }
    Serial.println(ignition);
    Serial.println(rearDoor);
    Serial.println(reset);
    Serial.println(timer_counter);
    if (reset == LOW)break;
    delay(10);
  }

  digitalWrite(LED_ONE_PIN, LOW);
  digitalWrite(LED_TWO_PIN, LOW);
  digitalWrite(LED_THREE_PIN, LOW);
  tone(BUZZER_PIN, 0);
  delay(2000);
  Serial.println("Done.");
}
