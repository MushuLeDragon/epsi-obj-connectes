#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8);

char msg[16];
char accepted[] = "212072103220039";
const uint8_t address[] = { 0x25, 0x23, 0x22, 0x21, 0x20 };
const uint8_t addressC[] = { 0x28, 0x20, 0x21, 0x19, 0x15 };
int LED = 3;

void setup(void) {
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.print(F("Radio fail"));
    while (true);
  }
  radio.openWritingPipe(addressC);
  radio.openReadingPipe(1, address);
  radio.startListening();
  Serial.println(F("NRF24 Ready"));

  pinMode(LED, OUTPUT);
}

void loop() {
  if (radio.available()) {
    radio.read(msg, sizeof(msg));
    Serial.println(msg);
    if (strcmp(msg, accepted) == 0) {
      digitalWrite(LED, HIGH);
      delay(10000);
      digitalWrite(LED, LOW);
      Serial.print("OK");
    } else {
      Serial.print("NOT OK");
    }
    Serial.println();
    delay(100);
  }
}
