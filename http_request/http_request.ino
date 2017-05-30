#include "SPI.h"
#include "Ethernet.h"

// Serveur écoutant sur le port 80
EthernetServer server(80);

void setup() {
  // put your setup code here, to run once:
  // Démarrage du serveur
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // On écoute les connections entrantes
  EthernetClient client = server.available();
  // Si la connection est établie (SYN / SYN+ACK / ACK)...
  if (client) {
    Serial.println(F("---- new request ----"));
    // ...pendant que le client maintient la session TCP...
    while (client.connected()) {
      // ...et que la requête contient des caractères...
      if (client.available()) {
        // ...on récupére les caractères...
        char c = client.read();
        // ... et on les affiche sur le terminal série
        Serial.print(c);
      }
    }
    // Fin de la requête
    Serial.println(F(""));
    Serial.println(F("---- end request ----"));
  }
}
