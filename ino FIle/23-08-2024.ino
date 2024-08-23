//Library initialization
#include "DHTesp.h"
#include <LiquidCrystal_I2C.h>

//pin initialization
const int DHT_PIN = 15;

//sensor variable initialization
DHTesp dhtSensor;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  dhtSensor.setup(DHT_PIN, DHTesp::DHT11);
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
}

void loop() {
  //read sensor
  TempAndHumidity  dht_response = dhtSensor.getTempAndHumidity();

  //print sensor response in serial monitor
  Serial.println("Suhu \t:" + String(dht_response.temperature,2)  + "C");
  Serial.println("Humi \t:" + String(dht_response.humidity,2)  + "%");

  //show sensor response in lcd
  lcd.setCursor(0, 0);
  lcd.print("Suhu \t:" + String(dht_response.temperature,2)  + "C");
  lcd.setCursor(0, 1);
  lcd.print("Humi \t:" + String(dht_response.humidity,2)  + "%");

  delay(1000);
}