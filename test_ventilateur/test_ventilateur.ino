#include "ventilateur.h"
#define Val 0

// constants won't change
const int RELAY_PIN1 = 14;  // INPUT D5(GPIO14) --> Push Button
const int RELAY_PIN2 = 13; //  OUTPUT D7 (GPIO13) --> Relay 
const int PWM_DUTY = 2; //

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin A5 as an output.
  pinMode(RELAY_PIN1, INPUT);
  pinMode(RELAY_PIN2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(RELAY_PIN1)==HIGH)
    {
      analogWrite(RELAY_PIN2, PWM_DUTY);
      delay(15000);
      digitalWrite(RELAY_PIN2, LOW);
    }
      
//      digitalWrite(RELAY_PIN2, HIGH); // turn on fan 5 seconds
//      delay(5);
//      digitalWrite(RELAY_PIN2, LOW);  // turn off fan 3 seconds
//      delay(50);
    
}
