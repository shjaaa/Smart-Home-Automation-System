// Smart Home Automation System

#define PIR_PIN 4
#define BUZZER_PIN 3
#define BULB_PIN 2
#define GAS_SENSOR A1
#define TEMP_SENSOR A0
#define ULTRA_PIN 6
#define MOTOR_PIN 5

#define GAS_THRESHOLD 400
#define TEMP_THRESHOLD 35.0
#define WATER_EMPTY_DIST 20
#define WATER_FULL_DIST 5

bool motorStatus = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BULB_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("System Initializing...");
}

void loop() {

  bool alarmActive = false;

  // =========================
  // 1. PIR MOTION SENSOR
  // =========================
  if (digitalRead(PIR_PIN) == HIGH) {
    digitalWrite(BULB_PIN, HIGH);
    alarmActive = true;
    Serial.println("Motion Detected -> Bulb ON");
  }
  else {
    digitalWrite(BULB_PIN, LOW);
  }

  // =========================
  // 2. GAS SENSOR
  // =========================
  int gasValue = analogRead(GAS_SENSOR);

  if (gasValue > GAS_THRESHOLD) {
    alarmActive = true;
    Serial.println("GAS LEAK DETECTED!");
  }

  // =========================
  // 3. TMP36 TEMPERATURE SENSOR
  // =========================
  int tempReading = analogRead(TEMP_SENSOR);

  float voltage = tempReading * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100.0;

  if (tempC > TEMP_THRESHOLD) {
    alarmActive = true;
    Serial.print("HIGH TEMPERATURE: ");
    Serial.println(tempC);
  }

  // =========================
  // 4. WATER LEVEL
  // =========================
  float distance = getUltrasonicDistance();

  if (distance > WATER_EMPTY_DIST && distance < 400) {
    if (!motorStatus)
      Serial.println("Water LOW -> Motor ON");

    motorStatus = true;
  }
  else if (distance < WATER_FULL_DIST) {
    if (motorStatus)
      Serial.println("Water FULL -> Motor OFF");

    motorStatus = false;
  }

  digitalWrite(MOTOR_PIN, motorStatus);

  // =========================
  // 5. BUZZER
  // =========================
  digitalWrite(BUZZER_PIN, alarmActive);

  // =========================
  // DEBUG OUTPUT
  // =========================
  Serial.print("Gas: ");
  Serial.print(gasValue);

  Serial.print(" | Temp: ");
  Serial.print(tempC);

  Serial.print(" | Water: ");
  Serial.println(distance);

  delay(500);
}

// =========================
// PING))) SENSOR FUNCTION
// =========================
float getUltrasonicDistance() {

  pinMode(ULTRA_PIN, OUTPUT);

  digitalWrite(ULTRA_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(ULTRA_PIN, HIGH);
  delayMicroseconds(5);

  digitalWrite(ULTRA_PIN, LOW);

  pinMode(ULTRA_PIN, INPUT);

  long duration = pulseIn(ULTRA_PIN, HIGH);

  float distance = duration * 0.0343 / 2;

  return distance;
}