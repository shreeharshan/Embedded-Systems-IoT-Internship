#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 25
#define DHTTYPE DHT22

#define LED_PIN 32
#define BUZZER_PIN 27

#define TEMP_THRESHOLD 35.0
#define HUM_THRESHOLD 80.0

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

  dht.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Temp & Humidity");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring...");
  delay(2000);

  lcd.clear();
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT22 Read Failed!");

    lcd.setCursor(0, 0);
    lcd.print("Sensor Error    ");
    lcd.setCursor(0, 1);
    lcd.print("Check DHT22     ");

    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);

    delay(2000);
    return;
  }

  bool tempAlert = temperature > TEMP_THRESHOLD;
  bool humAlert = humidity > HUM_THRESHOLD;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (tempAlert || humAlert) {

    digitalWrite(LED_PIN, HIGH);

    lcd.setCursor(0, 0);

    if (tempAlert) {
      lcd.print("!!! WARNING: HIGH TEMP !!");
    } else {
      lcd.print("!! WARNING: HIGH HUMID !!");
    }

    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(temperature, 1);
    lcd.print((char)223);
    lcd.print("C ");

    lcd.print("H:");
    lcd.print(humidity, 0);
    lcd.print("% ");

    Serial.println("ALERT CONDITION!");

    tone(BUZZER_PIN, 1000);
    delay(300);

    noTone(BUZZER_PIN);
    delay(300);

    tone(BUZZER_PIN, 1000);
    delay(300);

    noTone(BUZZER_PIN);
    delay(300);
  }
  else {

    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature, 1);
    lcd.print((char)223);
    lcd.print("C       ");

    lcd.setCursor(0, 1);
    lcd.print("H:");
    lcd.print(humidity, 1);
    lcd.print("%       ");

    Serial.println("NORMAL CONDITION");

    delay(1000);
  }
}
