
#include <FlexiTimer2.h>
 
int pin=2;
int buttonpin=5;
void event()
{
    static boolean output=HIGH;
    digitalWrite(buttonpin,output);
    output=!output;
}
 
void setup() {
    pinMode(pin,OUTPUT);
    pinMode(buttonpin,OUTPUT);
    FlexiTimer2::set(500,1.0/1000,event);
    FlexiTimer2::start();
}
void loop() {
    for(int i=0;i<255;i++){
      analogWrite(pin,i);
      delay(5);
    }
    for(int i=255;i>0;i--){
      analogWrite(pin,i);
      delay(5);
    }
}
