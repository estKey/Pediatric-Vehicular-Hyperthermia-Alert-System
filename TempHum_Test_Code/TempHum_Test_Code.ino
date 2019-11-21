/*  DHT11/ DHT22 Sensor Temperature and Humidity Tutorial
 *  Program made by Dejan Nedelkovski,
 *  www.HowToMechatronics.com 
 */
/*
 * You can find the DHT Library from Arduino official website
 * https://playground.arduino.cc/Main/DHTLib
 */
 
#include <DHT.h>
#define DHTTYPE DHT22

#define dataPin 9 // Defines pin number to which the sensor is connected
DHT dht(dataPin, DHTTYPE); // Creats a DHT object


void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  //int readData = dht.(dataPin); // Reads the data from the sensor
  float t = dht.readTemperature(); // Gets the values of the temperature
  float h = dht.readHumidity(); // Gets the values of the humidity
  
  // Printing the results on the serial monitor
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(2000); // Delays 2 secods, as the DHT22 sampling rate is 0.5Hz
}
