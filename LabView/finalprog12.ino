#include <DHT.h>

// Définition des broches et du type de capteur
#define DHTPIN 2         // Pin connectée au capteur DHT11
#define DHTTYPE DHT11    // Type de capteur : DHT11
DHT dht(DHTPIN, DHTTYPE);

// LEDs pour le climatiseur et le ventilateur
int LED1 = 13;  // LED pour le climatiseur
int LED2 = 12;  // LED pour le ventilateur

void setup() {
  Serial.begin(9600);   // Initialisation de la communication série
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  dht.begin();          // Initialisation du capteur DHT
}

void loop() {
  // Lecture des données de température et d'humidité
  float temperature = dht.readTemperature();
  float humidite = dht.readHumidity();

  // Vérification des erreurs de lecture
  if (isnan(temperature) || isnan(humidite)) {
    Serial.println("Erreur de lecture des capteurs !");
    return;
  }

  // Contrôle des LEDs en fonction des seuils
  if (temperature > 40) {
    digitalWrite(LED1, HIGH); // Allumer le climatiseur
  } else {
    digitalWrite(LED1, LOW); // Éteindre le climatiseur
  }

  if (humidite > 25) {
    digitalWrite(LED2, HIGH); // Allumer le ventilateur
  } else {
    digitalWrite(LED2, LOW); // Éteindre le ventilateur
  }

  // Envoi des données de température
 
  Serial.print(temperature);
  Serial.println(" C");

  // Envoi des données d'humidité

  Serial.print(humidite);
  Serial.println(" %");

  delay(1000); // Intervalle d'une seconde entre chaque lecture
}
