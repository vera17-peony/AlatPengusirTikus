#define PIR_PIN 12
#define BUZZER_PIN 25
#define RELAY_PIN 27

void setup() {

  pinMode(PIR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);

  Serial.begin(115200);

  randomSeed(millis());

}

void loop() {

  int gerakan = digitalRead(PIR_PIN);

  Serial.println(gerakan);

  // Jika ada gerakan
  if (gerakan == HIGH) {

    // Relay ON → Lampu nyala
    digitalWrite(RELAY_PIN, HIGH);

    // Frekuensi random buzzer
    int frekuensi = random(12000, 18000);

    // Bunyikan buzzer
    tone(BUZZER_PIN, frekuensi);

    delay(3000);

    // Matikan buzzer
    noTone(BUZZER_PIN);

    // Relay OFF → Lampu mati
    digitalWrite(RELAY_PIN, LOW);

  }

  else {

    noTone(BUZZER_PIN);

    digitalWrite(RELAY_PIN, LOW);

  }

  delay(100);

}