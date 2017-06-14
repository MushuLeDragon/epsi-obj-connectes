#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8);

char ON[] = "on";
char OFF[] = "OF";
const uint8_t address[] = { 0x10, 0x10, 0x10, 0x10, 0x01 };

int pirPin = 2;
int pirState = LOW;

void setup(void) {
  Serial.begin(9600);
  if(!radio.begin()){
    Serial.print(F("Radio fail"));
    while(true);
  }
  radio.openWritingPipe(address);
  Serial.println(F("Ready"));
  
  // Met la broche 2 en entrée
  pinMode(pirPin, INPUT);
  // Utilisation d'une résistance de pull-up sur le PIN 2
  digitalWrite(pirPin, HIGH);
}

void loop(void) {
  // Vérification de l'état du capteur
  if (digitalRead(pirPin ) == HIGH) {
    if (pirState == LOW) {
      // Mouvement !
      Serial.println("Motion !");
      pirState = HIGH;
      radio.write(ON, sizeof(ON));
    }
  } else {
    if (pirState == HIGH){
      // Pas de mouvement...
      Serial.println("No motion...");
      pirState = LOW;
      radio.write(OFF, sizeof(OFF));
    }
  }
}
