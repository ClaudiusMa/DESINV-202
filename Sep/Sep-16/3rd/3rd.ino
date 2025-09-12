
// Turns out that the button itself can store the state, thus we don't need to manually set a state variable to turn on and off the light
const int BUTTON_PIN = 2;
const int POTENTIOMETER_PIN = A0;
const int LED_PIN = 10;

bool ledOn = true;

void setup() {
  Serial.begin(9600);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50); 
    if (digitalRead(BUTTON_PIN) == LOW) {
      ledOn = !ledOn;
      delay(200); 
    }
  }
  
  int potValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(potValue, 0, 1023, 0, 255);
  
  if (ledOn) {
    analogWrite(LED_PIN, brightness);
  } else {
    analogWrite(LED_PIN, 0);
  }
  
  delay(10);
}
