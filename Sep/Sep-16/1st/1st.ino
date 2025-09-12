
// In my 1st iteration, I found that I probably should make BUTTON a state variable.
const int POTENTIOMETER_PIN = A0;
const int LED_PIN = 10;

bool ledOn = true;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  
  int potValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  if (ledOn) {
    analogWrite(LED_PIN, brightness);
  } else {
    analogWrite(LED_PIN, 0);
  }
  
  delay(10);
}
