#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>
#include <SPI.h>
#include <DHT.h>


int status = WL_IDLE_STATUS;
#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)

char serverAddress[] = "130.15.85.65";  // server address
int port = 80;
WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);

//our definitions here




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

int groupNum = 2;
int alertVar;
String Trigger_1Var = "its"; 
String Trigger_2Var = "too"; 
String Trigger_3Var = "hot";

void setup() {
  Serial.begin(9600);
    // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < "1.0.0") {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");

  //our setup stuff here
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
  Serial.println("Good ");
      wifiPost(2, 1, "Too", "HOT", "HERE");
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
      wifiPost(2, 1, "Too", "HOT", "HERE");
      digitalWrite(LED_ONE_PIN, LOW);
      digitalWrite(LED_TWO_PIN, HIGH);
      tone(BUZZER_PIN, 440);
    } else if (t > TEMP_THRESHOLD && h > HUM_THRESHOLD) Serial.println("Good ");
    if (rearDoor == LOW) {
      wifiPost(2, 0, "BABY", "IS", "SAFE");
      digitalWrite(LED_ONE_PIN, LOW);
      digitalWrite(LED_THREE_PIN, HIGH);
      tone(BUZZER_PIN, 0);
      timer_counter = 0;
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



//function to write post request to server
void wifiPost(int groupNum, int alertVar, String Trigger_1Var, String Trigger_2Var, String Trigger_3Var){
  int alert = (groupNum*10)+alertVar;
  
  //Post Request
  String postLine ="http://130.15.85.65/data.php?";
  Serial.println("making POST request");
  // Post request format ("serverLocation.php?Alert="+alertVar+"&Trigger_1="+Trigger_1Var+"&Trigger_2="+Trigger_2Var+"&Trigger_3="+Trigger_3Var)
  //"http://130.15.85.65/data.php?Alert=2&Trigger_1=Temp32&Trigger_2=PersonYes&Trigger_3=MotionYes"
  postLine += F("Alert=");
  postLine += alert;
  postLine += F("&Trigger_1=");
  postLine += Trigger_1Var;
  postLine += F("&Trigger_2=");
  postLine += Trigger_2Var;
  postLine += F("&Trigger_3=");
  postLine += Trigger_3Var;
  Serial.println(postLine);
  client.post(postLine);

  // read the status code and body of the response
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
 
}
