#include <SoftwareSerial.h>

#define RX_PIN 2
#define TX_PIN 3
#define BTN_PIN 5

const byte shot[] = {0xFD, 0x03, 0x03, 0x10, 0x00};
const byte released[] = {0xFD, 0x03, 0x03, 0x00, 0x00};
SoftwareSerial bluetooth(RX_PIN, TX_PIN);

void setup() {
  bluetooth.begin(115200);
  delay(200);
}

void loop() {
  if (digitalRead(BTN_PIN)) {
    bluetooth.write(shot, 5);

    while (digitalRead(BTN_PIN))
      delay(100);
    bluetooth.write(released, 5);
  }
  delay(100);
}

/*
void setupChip(){
  while (bluetooth.available() > 0) {
    Serial.write(bluetooth.read());
  }

  while (Serial.available() > 0) {
    bluetooth.write(Serial.read());
  }
}
*/
