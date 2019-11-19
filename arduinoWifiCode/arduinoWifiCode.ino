#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>
#include <SPI.h>

int status = WL_IDLE_STATUS;
#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)

char serverAddress[] = "130.15.85.65";  // server address
int port = 80;
WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);




void setup() {
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
 

}

void loop() {
  // put your main code here, to run repeatedly:

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
