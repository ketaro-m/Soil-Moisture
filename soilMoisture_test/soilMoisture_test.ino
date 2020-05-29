#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define readPin 34
#define switchPin 12
#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */ 
#define TIME_TO_SLEEP (29*60+30) /* Time ESP32 will go to sleep (in seconds) */
// Use Virtual pin 5 for uptime display
#define PIN_UPTIME V5

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

int value = 0;

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
  delay(9000);
  value = sensorRead();
  
  Blynk.begin(auth, ssid, pass);

  //Serial.print("Analog input is ");Serial.println(value);
  Blynk.virtualWrite(PIN_UPTIME,  value);
  digitalWrite(switchPin, LOW);
  delay(1000);

  Serial.println(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
  delay(1000);
}

int sensorRead() {
  int dur = 20;
  int val = 0;
  for (int i = 0; i < dur; i += 1) {
    //Serial.println(analogRead(readPin));
    val += analogRead(readPin);
    delay(1000);
  }
  val /= dur;
  return val;
}

void loop() {
}
