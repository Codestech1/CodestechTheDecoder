int potentiometr = A0;
int leds[] = {3, 5, 6, 9, 10, 11};
int ledsLength = 6;

void setup() {
  for (int i = 0; i < ledsLength; i++)
    pinMode(leds[i], OUTPUT);
}

void loop() {
  for (int i = 0; i < ledsLength; i++)
    analogWrite(leds[i], map(analogRead(potentiometr), 0, 1023, 0, 255));
}