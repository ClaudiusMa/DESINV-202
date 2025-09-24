#include <Servo.h>

Servo myServo;
int ldrPin = A0;
int servoPin = 9;
int ledPin = 2;

int lastLdrValue = -1;
int threshold = 10;

void setup() {
  myServo.attach(servoPin); 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  
  if (ldrValue < 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  int angle = map(ldrValue, 0, 100, 0, 180);

  if (lastLdrValue == -1 || abs(ldrValue - lastLdrValue) >= threshold) {
    myServo.write(angle);
    lastLdrValue = ldrValue;
    Serial.print("SERVO MOVED! ");
  }
  
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" -> Servo Angle: ");
  Serial.print(angle);
  Serial.print(" -> LED: ");
  Serial.println(ldrValue < 30 ? "ON" : "OFF");

  delay(200);
}
