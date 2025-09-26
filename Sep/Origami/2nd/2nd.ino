int ldrPin = A0;
int redPin = 2;
int greenPin = 3;
int bluePin = 4;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  
  if (ldrValue < 18) {
    digitalWrite(redPin, 255);
    digitalWrite(greenPin,255);
    digitalWrite(bluePin, 255);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" -> RGB: ");
  Serial.print(redPin);
  Serial.print(greenPin);
  Serial.print(bluePin);
  Serial.println(ldrValue > 10 ? "ON" : "OFF");

  delay(200);
}
