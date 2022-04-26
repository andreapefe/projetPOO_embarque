#define Val 0

#define frequencePWMde3921hz  0b00000010
// constants won't change
const int RELAY_PIN1 = 14;  // INPUT D5(GPIO14) --> Push Button
const int RELAY_PIN2 = 6; //  OUTPUT D7 (GPIO13) --> Relay 
const int PWM_DUTY = 2; //  

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin A5 as an output.
  pinMode(RELAY_PIN1, INPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  Serial.begin(9600);

  TCCR2B &= 0b11111000;         
  TCCR2B |= frequencePWMde31372hz; 
  
  
}

// the loop function runs over and over again forever
void loop() {
  int rapportCycliqueEntre0et255 = map(100, 0, 100, 0, 255); 
      Serial.println("Hola");
      analogWrite(RELAY_PIN2, rapportCycliqueEntre0et255);
      //delay(100);
      //digitalWrite(7, LOW);
      
      
//      digitalWrite(RELAY_PIN2, HIGH); // turn on fan 5 seconds
//      delay(5);
//      digitalWrite(RELAY_PIN2, LOW);  // turn off fan 3 seconds
//      delay(50);
    
}
