#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8);

char msg[3];
const uint8_t address[] = { 0x10, 0x10, 0x10, 0x10, 0x01 };
int LED1 = 3;

void setup(void) {
  Serial.begin(9600);
  if (!radio.begin()) {
    Serial.print(F("Radio fail"));
    while (true);
  }
  radio.openReadingPipe(1, address);
  radio.startListening();
  pinMode(LED1, OUTPUT);
  Serial.println(F("Ready"));
}

void loop(void) {
  if (radio.available()) {
    radio.read(msg, sizeof(msg));
    Serial.println(msg);
    if (strcmp(msg, "on") == 0) {
      digitalWrite(LED1, HIGH);
    }else if (strcmp(msg, "of") == 0) {
      digitalWrite(LED1, LOW);
    }
    delay(100);
  }
}
