#include <BlynkSimpleEsp32.h>

#define readPin 34
#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */ 
#define TIME_TO_SLEEP 5 /* Time ESP32 will go to sleep (in seconds) */

float value = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Wake up!");
  value = analogRead(readPin);
  Serial.print("Analog input is ");
  Serial.println(value);
  Serial.println();
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}

void loop() {
}
