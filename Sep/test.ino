void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  Serial.println("hey i'm the lil guy");
  
  for(int i = 0; i < 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(200);                      
    digitalWrite(LED_BUILTIN, LOW);   
    delay(1000);                      
  }
  
  delay(2000);
}
