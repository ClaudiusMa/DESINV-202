
const int LDR_PIN = A0;
const int LED_PIN = 10;   

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int raw = analogRead(LDR_PIN); 
  
  int brightness = map(raw, 1, 25, 255, 0);
  

  brightness = constrain(brightness, 0, 255);
  

  analogWrite(LED_PIN, brightness);

  
  delay(100);
}
