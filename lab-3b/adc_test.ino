/* ADC test code
 *  
 * Continually prints the value read by analogRead() to the Serial Monitor.
 * 
 * == Setting up the Serial Monitor ==
 * The Serial Monitor must be configured (bottom-right corner of the screen) as
 * baud rate 115200.
 *
 * ENGR 40M
 * Stanford University
 * July 2018
 */

const byte AUDIO_INPUT_PIN = A1;

void setup() {
  pinMode(AUDIO_INPUT_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(AUDIO_INPUT_PIN);
  Serial.println(value);
}
