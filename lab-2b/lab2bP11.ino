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
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
}

/*
 * Function: loop
 * ----------------
 * This will run continuously after setup() finishes running.
 */
void loop() {
    if (digitalRead(10) == HIGH) {
      Serial.println("Toggle: high");
    }
    if (digitalRead(10) == LOW) {
      Serial.println("Toggle: low");
    }
    if (digitalRead(9) == HIGH) {
      Serial.println("Limit: high");
    }
    if (digitalRead(9) == LOW) {
      Serial.println("Limit: low");
    }
}
