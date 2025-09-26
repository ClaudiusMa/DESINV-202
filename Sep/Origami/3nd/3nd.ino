#include <Servo.h>

int ldrPin = A0;
int redPin = 2;
int greenPin = 3;
int bluePin = 4;
int servoPin = 9; 
int servoAngle = 0; 

int onThreshold =8;   
int offThreshold = 20; 
bool ledOn = false;     

// Sample the LDR less often to ignore quick changes in room light
unsigned long lastSampleMs = 0;
const unsigned long sampleIntervalMs = 800; 

Servo lightServo;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  lightServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  if (now - lastSampleMs >= sampleIntervalMs) {
    lastSampleMs = now;

    int ldrValue = analogRead(ldrPin);

    // Update state using hysteresis
    if (ldrValue <= onThreshold) {
      ledOn = true;
    } else if (ldrValue >= offThreshold) {
      ledOn = false;
    }

    // Apply outputs and report
    if (ledOn) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      servoAngle = 90;
      lightServo.write(servoAngle); // move to active position
    } else {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      servoAngle = 180;
      lightServo.write(servoAngle);   // move to rest position
    }

    Serial.print("LDR: ");
    Serial.print(ldrValue);
    Serial.print(" -> LED: ");
    Serial.print(ledOn ? "ON" : "OFF");
    Serial.print(" | Servo: ");
    Serial.println(servoAngle);
  }
}
