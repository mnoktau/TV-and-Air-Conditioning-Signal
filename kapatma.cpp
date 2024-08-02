#include <IRremote.h> // IRremote kütüphanesini dahil et

// Pin Definitions
const int irSenderPin = 3;    // IR sender pin

IRsend irsend(irSenderPin);

void setup() {
  Serial.begin(9600);
  // IR alıcıyı başlatmaya gerek yok
}

void loop() {
  // Yakalanan kodu 0x20DF10EF ile değiştirin
  irsend.sendNEC(0x20DF10EF, 32); // Sinyali gönder
  delay(1000); // 1 saniye bekle
}
