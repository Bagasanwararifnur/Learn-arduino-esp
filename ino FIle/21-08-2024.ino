#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <DHT.h>

#define DHTPIN 7     // Pin digital yang terhubung ke DATA pin DHT11
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
int val = 0;

int temp_button = 4;
int hum_button = 12;

int temp_cond = 1;
int hum_cond = 0;

float temp = 0;

void setup() {
  lcd.init();
  dht.begin();
  pinMode(4, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

  //default
  lcd.setCursor(0, 0);
  lcd.print("Detik = "+String(val));
  lcd.setCursor(0, 1);
  lcd.print("Temp = "+String(temp));
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  //button temp
  if (digitalRead(4)==LOW){
    temp_cond = 1;
    hum_cond = 0;
  }

  //button hum
  else if (digitalRead(12)==LOW){
    hum_cond = 1;
    temp_cond = 0;
  }

  else if (digitalRead(13)==LOW){
    hum_cond = 0;
    temp_cond = 0;
  }

  if (temp_cond == 1){
    lcd.setCursor(0, 0);
    lcd.print("Detik = "+String(val));
    lcd.setCursor(0, 1);
    lcd.print("Temp = "+String(temp));
  }

  //button hum
  else if (hum_cond==1){
    lcd.setCursor(0, 0);
    lcd.print("Detik = "+String(val));
    lcd.setCursor(0, 1);
    lcd.print("Hum = "+String(hum));
  }

  else if (hum_cond==0 && temp_cond == 0){
    lcd.clear();
  }

  
  
  val += 1;
  delay(0.1);
}