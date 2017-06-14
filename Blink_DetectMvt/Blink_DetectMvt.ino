int pirPin = 2;
int pirState = LOW;
 
void setup() {
  // Met la broche 2 en entrée
  pinMode(pirPin, INPUT);
  // Utilisation d'une résistance de pull-up sur le PIN 2
  digitalWrite(pirPin, HIGH);
  // Active le port série
  Serial.begin(9600);
}
 
void loop(){
  // Vérification de l'état du capteur
  if (digitalRead(pirPin ) == HIGH) {  
    if (pirState == LOW) {
      // Mouvement !
      Serial.println("Motion !");
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      // Pas de mouvement...
      Serial.println("No motion...");
      pirState = LOW;
    }
  }
}
