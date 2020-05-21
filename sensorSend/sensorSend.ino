#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define readPin 12
#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */ 
#define TIME_TO_SLEEP 5 /* Time ESP32 will go to sleep (in seconds) */
// Use Virtual pin 5 for uptime display
#define PIN_UPTIME V5

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "t5t9Fvvesxwb4kdSdeoqR2C_6ee77ID3";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "aterm-490439-g";
char pass[] = "7268124842724";

float value = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  value = analogRead(readPin);
  
  Blynk.begin(auth, ssid, pass);

  Serial.print("Analog input is ");
  Serial.println(value);
  Blynk.virtualWrite(PIN_UPTIME,  value);

  delay(1000);
  
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}

void loop() {
}
