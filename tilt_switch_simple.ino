const int tiltSwitchPin = 8; // Définir le numéro de broche du capteur tilt switch
int previousTiltSwitchState = LOW; // Stocker l'état précédent du capteur tilt switch

void setup() {
  Serial.begin(9600); // Initialiser la communication série
  pinMode(tiltSwitchPin, INPUT); // Configurer la broche du capteur tilt switch en entrée
}

void loop() {
  int tiltSwitchState = digitalRead(tiltSwitchPin); // Lire l'état du capteur tilt switch
  
  if (tiltSwitchState != previousTiltSwitchState) { // Si l'état du capteur tilt switch a changé
    previousTiltSwitchState = tiltSwitchState; // Stocker le nouvel état du capteur tilt switch
    if (tiltSwitchState == HIGH) { // Si le capteur tilt switch est activé
      Serial.println("Désactivé"); // Envoyer un message "Activé" à la console
    } else { // Sinon, si le capteur tilt switch est désactivé
      Serial.println("Activé"); // Envoyer un message "Désactivé" à la console
    }
  }

  delay(100); // Attendre un court instant avant de vérifier à nouveau l'état du capteur
}
