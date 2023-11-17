int potentiometr = A0;
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int ledsLength = 8;

void setup() {
  for (int i = 0; i < ledsLength; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int analog = analogRead(potentiometr);
  int ledLevel = map(analog, 0, 1020, 0, ledsLength);
  for (int i = 0; i < ledsLength; i++) {
    if (i < ledLevel) {
      digitalWrite(leds[i], HIGH);
      continue;
    }
    digitalWrite(leds[i], LOW);
  }
}