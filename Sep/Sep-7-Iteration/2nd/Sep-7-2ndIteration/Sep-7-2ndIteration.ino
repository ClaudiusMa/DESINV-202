
// second iteration I saw some issue with my condition statement. I used 50 and the light was always on. I had to test the output to find the correct range
const int LDR_PIN = A0;
const int LED_PIN = 10;   

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int raw = analogRead(LDR_PIN); 
  
  if (raw < 15) {
    digitalWrite(LED_PIN, HIGH);  
  } else {
    digitalWrite(LED_PIN, LOW);  
  }
  
  // Debug
  Serial.print("LDR=");
  Serial.print(raw);
  Serial.print("  LED=");
  Serial.println(raw < 50 ? "ON" : "OFF");
  
  delay(100);
}
