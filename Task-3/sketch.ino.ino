#define BLYNK_TEMPLATE_ID "TMPL39RIRGb3q"
#define BLYNK_TEMPLATE_NAME "Smart Automatic Lighting System"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi Credentials
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Pin Definitions
const int LDR_PIN = 34;
const int LED_PIN = 32;

// Threshold for Bright/Dark
const int THRESHOLD = 2000;

// Timer
BlynkTimer timer;

// Manual Mode Flag
bool manualMode = false;

//------------------------------------------------------
// Manual Override from Blynk (V3)
//------------------------------------------------------
BLYNK_WRITE(V3)
{
  manualMode = param.asInt();

  if (manualMode)
  {
    digitalWrite(LED_PIN, HIGH);

    Serial.println("---------------------------------");
    Serial.println("Manual Mode Enabled");
    Serial.println("LED Turned ON from Blynk");
    Serial.println("---------------------------------\n");

    Blynk.virtualWrite(V1, "MANUAL");
    Blynk.virtualWrite(V2, 1);
  }
  else
  {
    Serial.println("---------------------------------");
    Serial.println("Automatic Mode Enabled");
    Serial.println("---------------------------------\n");
  }
}

//------------------------------------------------------
// Read Sensor & Send Data
//------------------------------------------------------
void sendSensorData()
{
  int lightValue = analogRead(LDR_PIN);

  // Always send LDR value
  Blynk.virtualWrite(V0, lightValue);

  // Manual Mode
  if (manualMode)
  {
    Serial.println("=================================");
    Serial.print("LDR Value   : ");
    Serial.println(lightValue);
    Serial.println("Mode        : MANUAL");
    Serial.println("LED Status  : ON");
    Serial.println("=================================\n");

    Blynk.virtualWrite(V1, "MANUAL");
    Blynk.virtualWrite(V2, 1);

    return;
  }

  // Automatic Mode
  Serial.println("=================================");
  Serial.print("LDR Value   : ");
  Serial.println(lightValue);

  if (lightValue < THRESHOLD)
  {
    digitalWrite(LED_PIN, HIGH);

    Serial.println("Environment : DARK");
    Serial.println("Light Status: LED ON");

    Blynk.virtualWrite(V1, "DARK");
    Blynk.virtualWrite(V2, 1);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);

    Serial.println("Environment : BRIGHT");
    Serial.println("Light Status: LED OFF");

    Blynk.virtualWrite(V1, "BRIGHT");
    Blynk.virtualWrite(V2, 0);
  }

  Serial.println("=================================\n");
}

//------------------------------------------------------
// Setup
//------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  Serial.println("\n=================================");
  Serial.println(" Smart Automatic Lighting System");
  Serial.println("=================================");

  Serial.println("\nConnecting to WiFi & Blynk...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("WiFi Connected!");
  Serial.println("Blynk Connected Successfully!");
  Serial.println("Device is Online.");
  Serial.println("---------------------------------\n");

  timer.setInterval(1000L, sendSensorData);
}

//------------------------------------------------------
// Main Loop
//------------------------------------------------------
void loop()
{
  Blynk.run();
  timer.run();
}