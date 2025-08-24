#include <Servo.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define SERVO_PIN 5

Servo gateServo;

const long DISTANCE_THRESHOLD = 25; // cm
const int EMPTY_COUNT_THRESHOLD = 5; // loops with no object before closing
int emptyCount = 0;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  gateServo.attach(SERVO_PIN);
  gateServo.write(0); // gate closed initially
  Serial.begin(9600);
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2; // convert to cm
  return distance;
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < DISTANCE_THRESHOLD) {
    // Object detected → open gate
    gateServo.write(90);
    emptyCount = 0; // reset counter
  } else {
    emptyCount++;
    if (emptyCount >= EMPTY_COUNT_THRESHOLD) {
      gateServo.write(0); // close gate after several empty readings
    }
  }

  delay(100); // small delay for sensor stability
}
