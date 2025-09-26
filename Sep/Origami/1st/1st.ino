int ldrPin = A0;
int ledPin = 2;

void setup() {
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
  
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" -> LED: ");
  Serial.println(ldrValue < 10 ? "ON" : "OFF");

  delay(200);
}
