//init jazz
//the_lick.wav
const int buzzer = 8; //buzzer to arduino pin 9

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer, 146.83);
  delay(200);
  tone(buzzer, 164.81);
  delay(200);
  tone(buzzer, 174.61);
  delay(200);
  tone(buzzer, 196);
  delay(200);
  tone(buzzer, 164.81);
  delay(400);
  tone(buzzer, 130.81);
  delay(200);
  tone(buzzer, 146.83);
  delay(1000);
}
