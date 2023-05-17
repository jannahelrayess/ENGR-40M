/*
 * ENGR 40M Prelab 2b Starter Code
 *
 * This simple program reads a character in from the Serial Port.
 * It is up to you to figure out how to move the motor based on that
 * character!
 *
 * How to run this code:
 *      * plug in your Arduino
 *      * select port (tools->port)
 *      * select board "Arduino Uno" (tools->board)
 *      * download the code (-> button)
 *      * open serial monitor (magnifying glass button)
 *      * set baud rate to "115200" (bottom right corner)
 *      * select "No Line Ending" (dropdown to the left of baud rate)
 */

/*
 * Function: setup
 * ----------------
 * This will run once to initialize your program.
 */
void setup() {
  Serial.begin(115200);
  Serial.println("Setup completed");
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

/*
 * Function: loop
 * ----------------
 * This will run continuously after setup() finishes running.
 */
void loop() {
  byte user_input = 0;

  if (Serial.available() > 0) {
    user_input = Serial.read();

    if (user_input == 'f') {
      Serial.println("Forward");
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
    } else if (user_input == 'r') {
      Serial.println("Reverse");
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    } else if (user_input == 's') {
      Serial.println("Stop");
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    } else {
      Serial.println("Invalid character");
    }
  }
}
