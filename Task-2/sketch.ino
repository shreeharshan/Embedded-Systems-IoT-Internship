#include <Arduino.h>

// Pin Definitions
const int LDR_PIN = 34;   // LDR Analog Output
const int LED_PIN = 32;   // LED

// Threshold for dark/light
const int THRESHOLD = 2000;

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  Serial.println("=================================");
  Serial.println(" Automatic Light Detection System");
  Serial.println("=================================");
}

void loop() {

  int lightValue = analogRead(LDR_PIN);

  Serial.println("=================================");
  Serial.print("LDR Value : ");
  Serial.println(lightValue);

  if (lightValue < THRESHOLD) {

    digitalWrite(LED_PIN, HIGH);

    Serial.println("Environment : DARK");
    Serial.println("Light Status: LED ON");
  }
  else {

    digitalWrite(LED_PIN, LOW);

    Serial.println("Environment : BRIGHT");
    Serial.println("Light Status: LED OFF");
  }

  Serial.println("=================================\n");

  delay(1000);
}