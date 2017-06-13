#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8);

char ON[] = "on";
char OFF[] = "of";
const uint8_t address[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };

void setup(void) {
  Serial.begin(9600);
  if(!radio.begin()){
    Serial.print(F("Radio fail"));
    while(true);
  }
  radio.openWritingPipe(address);
  Serial.println(F("Ready"));
}

void loop(void) {
  radio.write(ON, sizeof(ON));
  delay(1500);
  radio.write(OFF, sizeof(OFF));
  delay(1500);
}
