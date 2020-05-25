#define readPin 34

float value = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  value = analogRead(readPin);
  Serial.println(value);
  delay(2000);
}
