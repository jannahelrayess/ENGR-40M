/* LED plane responding to audio by amplitude (starter code)
 *
 * Lights an LED array to respond to audio.
 *
 * == Setting up the Serial Monitor ==
 * The Serial Monitor must be configured (bottom-right corner of the screen) as
 * baud rate 115200.
 *
 * ENGR 40M
 * Stanford University
 * July 2018
 */

const byte ANODE_PINS[8] = {13, 12, 11, 10, 9, 8, 7, 6};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};
const byte AUDIO_INPUT_PIN = A5;

byte pattern1[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1} };      

byte pattern2[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 1},
                        {1, 0, 1, 1, 1, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1} };     

byte pattern3[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0},
                        {1, 1, 0, 1, 0, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1} }; 

byte pattern4[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 1},
                        {0, 0, 1, 1, 1, 1, 0, 1},
                        {0, 0, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1} }; 

byte pattern5[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0},
                        {1, 0, 1, 1, 0, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1} }; 

byte pattern6[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 1},
                        {1, 1, 0, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1} }; 

byte pattern7[8][8] = { {1, 0, 0, 1, 0, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0, 0, 0},
                        {1, 0, 1, 1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1} }; 

byte pattern8[8][8] = { {0, 1, 0, 1, 1, 0, 0, 1},
                        {1, 1, 1, 1, 1, 0, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1} }; 

void setup() {
  for (byte i = 0; i < 8; i++) {
    pinMode(ANODE_PINS[i], OUTPUT);
    pinMode(CATHODE_PINS[i], OUTPUT);
  }
  
  for (byte i = 0; i < 8; i++) {
    digitalWrite(ANODE_PINS[i], HIGH);
    digitalWrite(CATHODE_PINS[i], HIGH);
  }
  
  pinMode(AUDIO_INPUT_PIN, INPUT);
  Serial.begin(115200);
}

/* Function: display
 * -----------------
 * Runs through one multiplexing cycle of the LEDs, controlling which LEDs are
 * on.
 *
 * During this function, LEDs that should be on will be turned on momentarily,
 * one row at a time. When this function returns, all the LEDs will be off
 * again, so it needs to be called continuously for LEDs to be on.
 */
void display(byte pattern[8][8]) {
  //   for each anode (+/row) wire
  //     for each cathode (-/column) wire
  //       look up in pattern whether this LED should be on or off
  //       if LED should be on, activate cathode (-) wire, else deactivate it
  //     end for
  //     activate anode (+) wire
  //     wait a short time (hint: try delayMicroseconds())
  //     deactivate anode (+) wire
  //   end for
  for (byte i = 0; i < 8; i++) {
    for (byte j = 0; j < 8; j++) {
      if (pattern[i][j] == 1) {
        digitalWrite(CATHODE_PINS[j], LOW);
      }
      else {
        digitalWrite(CATHODE_PINS[j], HIGH);
      }
    }
    digitalWrite(ANODE_PINS[i], LOW);
    delayMicroseconds(50);
    digitalWrite(ANODE_PINS[i], HIGH);
  }
}

/* Function: getSample
 * -------------------
 * Returns an unbiased sample of the audio signal. The returned value will be
 * "centered around zero", i.e., sometimes positive and sometimes negative.
 */
int getSample() {
  // TODO: Fill this in!
  int sample = analogRead(AUDIO_INPUT_PIN);
  
  // You might want to do some processing here, to unbias the sample.
  Serial.println(sample); // to serial monitor
  return sample;
}


/* Function: setLEDs
 * -----------------
 * Sets the LEDs array based on the given sample. The sample is assumed to
 * be returned by getSample() (and have the consequent properties).
 */
void setLEDs(byte pattern[8][8], int sample) {
  for (byte i = 0; i < 8; i++) {
    for (byte j = 0; j < 8; j++) {
      if (sample < 470) {
        pattern[i][j] = pattern1[i][j];
      }
      else if (sample < 485) {
        pattern[i][j] = pattern2[i][j];
      }
      else if (sample < 500) {
        pattern[i][j] = pattern3[i][j];
      }
      else if (sample < 515) {
        pattern[i][j] = pattern4[i][j];
      }
      else if (sample < 530) {
        pattern[i][j] = pattern5[i][j];
      }
      else if (sample < 545) {
        pattern[i][j] = pattern6[i][j];
      }
      else if (sample < 560) {
        pattern[i][j] = pattern7[i][j];
      }
      else if (sample < 575) {
        pattern[i][j] = pattern8[i][j];
      }
    }
  }
}

void loop() {
  static byte pattern[8][8];
  int sample = getSample();
  setLEDs(pattern, sample);
  display(pattern);
}
