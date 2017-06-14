/*
le bouton poussoir est connecté au pin 2 avec une résistance pull-down de 10KΩ
les LED sont connectées au pins 4 et 6 avec des résistances de 220Ω
*/

//déclaration des variables
int pinBouton = 4;
int pinLed = 5;
int state = 0;
void setup()
{
  //définition des modes
  pinMode(pinBouton, INPUT); //mode lecture pour le bouton
  pinMode(pinLed, OUTPUT); //mode ecriture pour la led
  digitalWrite(pinBouton, HIGH);
  // Active le port série
  Serial.begin(9600);
}

void loop()
{
  //lecture de l'état du bouton et stockage dans etatBouton
  boolean etatBouton = digitalRead(pinBouton);
  //test des conditions
  if (etatBouton==HIGH)//test si bouton appuyé
  {
    if(state == 0 || state == 2){
     Serial.println("Porte ouverte");
     digitalWrite(pinLed, etatBouton);
     state = 1;
    }
  }
  if (etatBouton==LOW)//test si bouton levé
  {
    if(state == 0 || state == 1){
     Serial.println("Porte fermee");
     digitalWrite(pinLed, etatBouton);
     state = 2;
    }
  }
  delay(1000);
}
