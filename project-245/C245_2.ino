#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 15
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 sensor");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    Serial.println("Failed to read the DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print(", Temperature: ");
  Serial.println(t);
  delay(2000);
}
