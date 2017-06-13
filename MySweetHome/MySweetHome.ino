#include <SPI.h>
#include <Ethernet.h>
#include "nRF24L01.h"
#include "RF24.h"
/**
   Variable permettant de choisir entre une assignation
   fixe ou dynamique du niveau 3 OSI
   '0' --> configuration statique
   '1' --> configuration dynamique
*/
#define DHCP 1
/**
   Adresse MAC du module, doit être unique sur le réseau !
   Ici 00:01:02:03:04:05
*/
byte mac[] = { 0x92, 0xE2, 0x89, 0xCD, 0xEF, 0x4D };
#if DHCP == 0
// Adresse IP
IPAddress ip = { 192, 168, 112, 7 };
// Masque de sous-réseau
IPAddress mask = { 255, 255, 255, 0 };
// Passerelle
IPAddress gateway = { 192, 168, 112, 250 };
// DNS
IPAddress server_dns = { 192, 168, 221, 1 };
#endif

// Serveur écoutant sur le port 80
EthernetServer server(80);

//RADIO
RF24 radio(7, 8);

char msg[3];
const uint8_t address[] = { 0x10, 0x10, 0x10, 0x10, 0x01 };
int LED1 = 3;

void setup() {
  // Démarrage du port série
  Serial.begin(9600);
  /**
     Démarrage du shield Ethernet sans spécifier d'adresse IP
     Cela oblige le contrôleur Ethernet à demander une configuration OSI 3
  */
#if DHCP == 0
  Serial.println(F("Setting ip..."));
  Ethernet.begin(mac, ip, server_dns, gateway, mask);
#else
  Serial.println(F("Requesting ip..."));
  if (Ethernet.begin(mac) == 0) {
    // Si c'est un échec, pas la peine de pousuivre...
    Serial.println(F("DHCP failure !"));
    while (true);
  }
#endif
  // Affichage des informations obtenues
  Serial.print(F("IP : "));
  Serial.println(Ethernet.localIP());
  Serial.print(F("Mask : "));
  Serial.println(Ethernet.subnetMask());
  Serial.print(F("Gateway : "));
  Serial.println(Ethernet.gatewayIP());
  Serial.print(F("DNS : "));
  Serial.println(Ethernet.dnsServerIP());
  // Démarrage du serveur
  server.begin();

  //Radio
   if (!radio.begin()) {
    Serial.print(F("Radio fail"));
    while (true);
  }
  radio.openReadingPipe(1, address);
  radio.startListening();
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, HIGH);
  Serial.println(F("Ready"));
}

void loop() {
 // On écoute les connections entrantes
EthernetClient client = server.available();
// Si la connection est établie (SYN / SYN+ACK / ACK)...
if (client) {
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      // Réception des caractères
    } else {
      // Envoie du code status HTTP, ici '200 OK'
      client.println("HTTP/1.1 200 OK");
      // Entête spécifiant le contenu du corps
      client.println("Content-Type: text/html");
      /**
         On prévient le client qu'à la fin de
         la requête, on coupe la session TCP
      */
      client.println("Connection: close");
      /**
         Spération entre les entêtes HTTP et le corps du message
         !! TRES IMPORTANT, SANS LE SAUT DE LIGNE LE NAVIGATEUR
         NE FAIT PAS LA SEPARTATION ENTRE HEADER ET CORPS !!
      */
      client.println();
      // Corps du message HTTP
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("It Works !");
      client.println("</html>");
      // On donne le temps au navigateur de traiter le message
      delay(1);
      // Fermeture de la session TCP
      client.stop();
      break;
    }
  }
  // Fin de la requête
  Serial.println(F(""));
  Serial.println(F("---- end request ----"));
  }

  if (radio.available()) {
    radio.read(msg, sizeof(msg));
    Serial.println(msg);
    if (strcmp(msg, "on") == 0) {
      Serial.println("mise a feu");
      digitalWrite(LED1, LOW);
    }else if (strcmp(msg, "OF") == 0) {
      Serial.println("mise en arret");
      digitalWrite(LED1, HIGH);
    }
}
}
