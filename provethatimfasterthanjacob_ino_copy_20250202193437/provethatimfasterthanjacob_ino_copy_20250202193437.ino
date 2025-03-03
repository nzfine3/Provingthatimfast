// declare constants for ultrasonic sensor

const int trigPin = 9;
const int echoPin = 10;
const int swPin = 2;

const int dist = 13;
const int buttonPin = 2;
float duration, distance;

// declare time for s = d/t
float time = 0;

// declare a state for if the button has been pressed or not
bool timestate = false;

// declare speed for printing to outputs
int speed;



void setup() {

  // adding neccesary pinmodes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  // start baud rate to 9600
  Serial.begin(9600);
}

void loop() {

  // send out a wave with a length of 12 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // read whether the button has been pressed or not
  int buttonState = digitalRead(buttonPin);

  // calculate distance from ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  // start timer if button has been pressed
  if (buttonState == LOW) {
    timestate = true;
  }
  if (timestate == true){
    time = time + 0.1;
  }

  // printing speed if hand is close to ultrasonic sensor
  if (distance < 15) {
    // preform speed = distance / time calculation and convert to mph by multiplying by 2.237
    float speed = (dist / time) * 2.237;

    // print speed to serial monitor
    Serial.print("Average Speed: ");
    Serial.print(speed);

    // give output so serial monitor is not required (on a scale from 1 - 7.5 with 5 ticks, 0 - 1.5, 1.5 - 3, 3 - 4.5, 4.5 - 6, and 6 - infinity)
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

    // pause code until button is pressed again
    while (true){
      if (buttonState == LOW) {
        break;
      }
    }
  }
  // delay for timer(you need to keep it at 100 milliseconds or else timer will be messed up)
  delay(100);
}