#include <SPI.h>
#include <Ethernet.h>
// Adresse IP
IPAddress ip = { 192, 168, 112, 32 };
// Masque de sous-réseau
IPAddress mask = { 255, 255, 255, 0 };
// Passerelle
IPAddress gateway = { 192, 168, 112, 250 };
// DNS
IPAddress server_dns = { 192, 168, 221, 1 };
/**
   Adresse MAC du module, doit être unique sur le réseau !
   Ici 00:01:02:03:04:05
*/
byte mac[] = { 0x92, 0xE2, 0x89, 0xCD, 0xEF, 0x4D };

void setup() {
  // Démarrage du port série
  Serial.begin(9600);
  Serial.println(F("Setting ip..."));
  /**
    Démarrage du shield Ethernet en spécifiant la configuration OSI 3
  */
  Ethernet.begin(mac, ip, server_dns, gateway, mask);
  // Affichage des informations
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
