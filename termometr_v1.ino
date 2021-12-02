//załączamy bibilotekę DHT
#include "DHT.h"
//definiujemy, do którego pinu podłączyliśmy czujnik
#define DHTPIN 2  
//definiujemy typ czujnika
#define DHTTYPE DHT22 
//konfigurujemy czujnik
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
//Aktywujemy transmisję szeregową
  Serial.begin(9600);
//inicjalizujemy czujnik
  dht.begin();
}

void loop() {
//definiujemy zmienną temp, do kórej przypisujemy odczyt temperatury z czujnika
  float temp = dht.readTemperature();
//definiujemy zmienną wilg, do kórej przypisujemy odczyt wilgotności z czujnika
  float wilg = dht.readHumidity();
//wyświetlamy na porcie szeregowym etykietę Temperatura:  
  Serial.print("Temperatura: ");
//wy
  Serial.print(temp);
  Serial.print("*C; ");
  Serial.print("Wilgotność: ");
  Serial.print(wilg);
  Serial.println("%");  
  delay(2000);  
}
