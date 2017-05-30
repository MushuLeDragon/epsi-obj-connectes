#include <SPI.h>
#include <Ethernet.h>
/**
   Adresse MAC du module, doit être unique sur le réseau !
   Ici 00:01:02:03:04:05
*/
byte mac[] = { 0x92, 0xE2, 0x89, 0xCD, 0xEF, 0x4F };

void setup() {
  // Démarrage du port série
  Serial.begin(9600);
  Serial.println(F("Requesting IP..."));
  /**
     Démarrage du shield Ethernet sans spécifier d'adresse IP
     Cela oblige le contrôleur Ethernet à demander une configuration OSI 3
  */
  if (Ethernet.begin(mac) == 0) {
    // Si c'est un échec, pas la peine de pousuivre...
    Serial.println(F("DHCP failure !"));
    while (true);
  }
  // Affichage des informations obtenues
  Serial.print(F("IP : "));
  Serial.println(Ethernet.localIP());
  Serial.print(F("Mask : "));
  Serial.println(Ethernet.subnetMask());
  Serial.print(F("Gateway : "));
  Serial.println(Ethernet.gatewayIP());
  Serial.print(F("DNS : "));
  Serial.println(Ethernet.dnsServerIP());
}
void loop() {
}
