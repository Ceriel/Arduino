#include <AltSoftSerial.h>
// AltSoftSerial always uses these pins:
//
// Board          Transmit  Receive   PWM Unusable
// -----          --------  -------   ------------
// Teensy 2.0         9        10       (none)
// Teensy++ 2.0      25         4       26, 27
// Arduino Uno        9         8         10
// Arduino Mega      46        48       44, 45
// Wiring-S           5         6          4
// Sanguino          13        14         12
AltSoftSerial altSerial;
char c;
void setup() {
  Serial.begin(9600);
  altSerial.begin(9600);
}
void loop() {
  if (altSerial.available()) {
    c = altSerial.read();

    // --- 7 bits instelling ---
    c &= ~(1 << 7);
    char inChar = (char)c;

    Serial.print(inChar);
  }

}

