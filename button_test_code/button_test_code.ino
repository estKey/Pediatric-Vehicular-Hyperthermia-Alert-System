//this turns on the LEDs, I'm too lazy to make them go off

int LEDpinOne = 2; //LED pins on 2, 1, 4
int LEDpinTwo = 1;
int LEDpinThree = 4;

int buttonOne = 5; //buttons on pin 5, 6, 7
int buttonTwo = 6;
int buttonThree = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDpinOne, OUTPUT);
  pinMode(LEDpinTwo, OUTPUT);
  pinMode(LEDpinThree, OUTPUT);
  pinMode(buttonOne, INPUT_PULLUP);
  pinMode(buttonTwo, INPUT_PULLUP);
  pinMode(buttonThree, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valueOne = digitalRead(buttonOne);
  int valueTwo = digitalRead(buttonTwo);
  int valueThree = digitalRead(buttonThree);
  
  if (valueOne == LOW){
    Serial.println("pressed 1");
    digitalWrite(LEDpinOne, HIGH);
  }
  if (valueTwo == LOW){
    Serial.println("pressed 2");
    digitalWrite(LEDpinTwo, HIGH);
  }
  if (valueThree == LOW){
    Serial.println("pressed 3");
    digitalWrite(LEDpinThree, HIGH);
  }
}
