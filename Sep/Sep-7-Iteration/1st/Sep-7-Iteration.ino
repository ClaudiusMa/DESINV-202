
// First Iteration 
// Used this code to debug LED light issue. Turned out that I didn't understand the breadboard, mistakenly put both LED legs to same row. 
int led = 10;

void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
}

void loop(){
Serial.println("Hello, world!"); 
digitalWrite(led, HIGH);       
delay(1000);                    
digitalWrite(led, LOW);         
delay(1000);                     
}

