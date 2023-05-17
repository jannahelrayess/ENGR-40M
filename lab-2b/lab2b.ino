//  State values live in an enum
enum states {STOP = 0, FORWARD, REVERSE, FAKE, SLOW}; // FORWARD = 1, REVERSE = 2, FAKE = 3, SLOW = 4

// this state variable saves our state between calls to loop()
int state = STOP;


void setup() {
  Serial.begin(115200);
  Serial.println("Setup complete"); 
  
  // intialize input and output pins
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  
  // Intializes initial states
  state = STOP;
}

void loop() {
  // TODO read input pins to get status of toggle and limit

  switch (state) {
    case STOP: // case for STOP 
      // Sets outputs for the motor to stop
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);

      // If toggle is pressed, move finger forward
      if (digitalRead(10) == HIGH) {
        state = FAKE;
      }
      
      break;
    case FORWARD: // case for forward 
      // Sets outputs for the motor to move forward
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);

      // If toggle is not pressed, reverse finger
      if (digitalRead(10) == LOW) {
        state = SLOW;
      }

      break;
    case REVERSE: // case for backward 
      // Sets outputs for the motor to reverse
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);

      // If limit is pressed, stop
      if (digitalRead(9) == HIGH) {
        state = STOP;
      }

      // If toggle is pressed, move finger forward
      if (digitalRead(10) == HIGH) {
        state = FORWARD;
      }
      
      break;
     case FAKE: // case for fake 
      // Finger moves up and down 3 times
      for (int i = 0; i <= 3; i++) {
        // Sets outputs for the motor to move forward
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        
        // Wait for 0.2 seconds 
        delay(200);

        // Sets outputs for the motor to stop
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);

        // Wait for 0.2 seconds 
        delay(200);
        
        // Sets outputs for the motor to reverse
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        
        // Wait for 0.2 seconds 
        delay(200);
      }
      
      state = FORWARD;

      break;
     case SLOW: // case for slow 
     // Finger moves down slowly 3 times
      for (int i = 0; i <= 3; i++) {
        // Sets outputs for the motor to reverse
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
         
        // Wait for 0.1 seconds 
        delay(100);
         
        // Sets outputs for the motor to stop
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
         
        // Wait for 0.9 seconds 
        delay(900);      
      }

      state = REVERSE;
      
      break;
        
    default: 
      Serial.println("Invalid state");
      break;
  }; // end switch
}
