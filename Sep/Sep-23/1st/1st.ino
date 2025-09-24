#include <Servo.h>

Servo myServo;   // create servo object
int ldrPin = A0; // LDR connected to analog pin A0
int servoPin = 9; // Servo control pin

void setup() {
  myServo.attach(servoPin); 
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); // read LDR (0–1023)
  
  // Map LDR value to servo angle (0–180 degrees)
  int angle = map(ldrValue, 0, 40, 0, 180);

  myServo.write(angle); // move servo
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" -> Servo Angle: ");
  Serial.println(angle);

  delay(200); // small delay for smooth movement
}
