// Ding Dong Ditch
// by Roald Nefs https://github.com/roaldnefs/ding-dong-ditch.git
// jan 13, 2019

// This script uses the RCSwitch library for sending the
// signal. The library is written for power outlet sockets,
// but the doorbell uses the same frequency and protocol.
//
// Usage:
//   Download the .zip from the official project page and
//   add it to your Arduino IDE:
//   Sketch >> Include Library >> Add .ZIP Library...
//
// Source:
//   https://github.com/sui77/rc-switch.git
#include <RCSwitch.h>


// Transmitter is connected to TX_PIN
#define TX_PIN 9

// Set the RCSwitch protocol used for sending the signal
#define TX_PROTOCOL 1

// Set the numer of transmission repetitions
#define TX_NUM_REPEAT 4

// Set the pulse length
#define TX_PULSE_LENGTH 320

// The inverted signal received by the SDR using rtl_433 or
// manually decoded from the raw signal
//
// Example:
//   original: 1111100110101110011010111
//   inverted: 0000011001010001100101000
#define TX_SIGNAL "0000011001010001100101000"

RCSwitch mySwitch = RCSwitch();


void setup() {
  // Set the serial baud rate to 115200
  Serial.begin(115200);

  // Transmitter is connected to TX_PIN
  mySwitch.enableTransmit(TX_PIN);

  // Set the protocol (RCSwitch default is 1)
  mySwitch.setProtocol(TX_PROTOCOL);
  
  // Set the pulse length (RCSwitch default is 320)
  mySwitch.setPulseLength(TX_PULSE_LENGTH);

  // Set the numer of transmission repetitions
  mySwitch.setRepeatTransmit(TX_NUM_REPEAT);

  Serial.println("");
  Serial.println(F("Ding Dong Ditch"));
  Serial.println(F("by Roald Nefs"));
}

void loop() {
  // Ring the doorbell
  Serial.println(F("Ding Dong!"));
  mySwitch.send(TX_SIGNAL);

  // Wait for 10 seconds
  delay(10000);
}
