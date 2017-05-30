int pirPin = 2;
int pirState = LOW;
 
void setup() {
  // Met la broche 2 en entrée
  pinMode(pirPin, INPUT);
  // Active le port série
  Serial.begin(9600);
  attachInterrupt(2, motion, CHANGE);
  Serial.println(F("Ready"));
}
 
void loop(){
}

void motion(){
  if (digitalRead(pirPin) == HIGH) {
    Serial.println(F("Motion !"));
  }else{
    Seriel.println(F("No motion..."));
  }
  digitalWrite(3, digitalRead(pirPin));
}
