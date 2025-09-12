// Didn't work. I can disable the button in this setup, but I can't use the state variable to turn on and off my LED
const int BUTTON_LED_PIN = 10;  

bool ledOn = false;  
bool lastButtonState = HIGH;  

void setup() {
  pinMode(BUTTON_LED_PIN, OUTPUT);
}

void loop() {

  pinMode(BUTTON_LED_PIN, INPUT_PULLUP);
  bool currentButtonState = digitalRead(BUTTON_LED_PIN);
  

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    ledOn = !ledOn;  
  }
  

  pinMode(BUTTON_LED_PIN, OUTPUT);
  digitalWrite(BUTTON_LED_PIN, ledOn ? HIGH : LOW);
  

  lastButtonState = currentButtonState;
  
  delay(50);
}