#define readPin 34
#define switchPin 12

float value = 0;

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, OUTPUT);
  delay(1000);
}

void loop() {
  digitalWrite(switchPin, HIGH);
  delay(100);
  value = analogRead(readPin);
  Serial.print("Switch on; ");Serial.println(value);
  digitalWrite(switchPin, LOW);
  delay(1000);
  digitalWrite(switchPin, LOW);
  delay(100);
  value = analogRead(readPin);
  Serial.print("Switch off; ");Serial.println(value);
  delay(1000);
}
