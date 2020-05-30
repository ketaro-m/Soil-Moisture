#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define readPin1 34 //readPin for sensor1
#define readPin2 39 //readPin for sensor2
#define switchPin 12
#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */ 
#define TIME_TO_SLEEP (29*60+30) /* Time ESP32 will go to sleep (in seconds) */
// Use Virtual pin 5,6 for uptime display
#define PIN_UPTIME1 V5 //virtual pin for sensor1
#define PIN_UPTIME2 V6 //virtual pin for sensor2

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword"; 

int v1 = 0; //value for sensor1
int v2 = 0; //value for sensor2

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
  delay(9000);
  sensorRead();
  
  Blynk.begin(auth, ssid, pass);

  Serial.print("sensor1, 2 = ");Serial.print(v1);Serial.print(", ");Serial.println(v2);
  Blynk.virtualWrite(PIN_UPTIME1,  v1);
  Blynk.virtualWrite(PIN_UPTIME2,  v2);
  digitalWrite(switchPin, LOW);
  delay(1000);

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
  delay(1000);
}

void sensorRead() {
  int dur = 20;
  v1 = 0;v2 = 0;
  Serial.print("sensor1 ");Serial.println("sensor2");
  for (int i = 0; i < dur; i += 1) {
    Serial.print(analogRead(readPin1));Serial.print(" ");Serial.println(analogRead(readPin2));
    v1 += analogRead(readPin1);
    v2 += analogRead(readPin2);
    delay(1000);
  }
  v1 /= dur;v2 /= dur;
  v1 = convert(v1);v2 = convert(v2);
}

float convert(int x) {
  return log(x/3115.2)/(-0.026);
}
void loop() {
}
