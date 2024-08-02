#include <IRremote.h>

// Pin Definitions
const int irReceiverPin = 2;  // IR receiver pin
const int irSenderPin = 3;    // IR sender pin

IRrecv irrecv(irReceiverPin);
IRsend irsend(irSenderPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the received code
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }

  // For sending the signal, you can store the captured value and use it
  // for example:
  // irsend.sendNEC(0x20DF10EF, 32); // Example NEC code for sending a signal
  // You can replace 0x20DF10EF with your captured code
}
