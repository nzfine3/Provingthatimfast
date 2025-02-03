#include <LiquidCrystal.h>

const int trigPin = 9;
const int echoPin = 10;
const int swPin = 2;
const int dist = 13;
const int buttonPin = 2;
float duration, distance;
float time = 0;
int buttonpresses = 0;
bool timestate = false;
int speed;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int buttonState = digitalRead(buttonPin);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  if (buttonState == LOW) {
    timestate = true;
    buttonpresses = buttonpresses + 1;
  }
  if (timestate == true){
    time = time + 0.1;
  }
  if (distance < 10) {
    float speed = (dist / time) * 2.237;
    Serial.print("Average Speed: ");
    Serial.print(speed);

    if (speed < 1.5){
      digitalWrite(7, HIGH);
    } 
    if (1.5 < speed) {
      if (speed < 3) {
        digitalWrite(8, HIGH);
      }
    } 
    if (3 < speed) {
      if (speed < 4.5) {
        digitalWrite(11, HIGH);
      }
    } 
    if (4.5 < speed) {
      if (speed < 6){
        digitalWrite(12, HIGH);
      }
    } 
    if (speed > 7.5) {
      digitalWrite(13, HIGH);
    }

    while (true){
      ;
    }
  }
  delay(100);
}