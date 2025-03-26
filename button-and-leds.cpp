int lastState = LOW;
boolean enabled = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(6);
  boolean shouldReturn = state == lastState || state == LOW;

  lastState = state;
  if (shouldReturn) return;

  enabled = !enabled;

  int ledState = enabled ? HIGH : LOW;
  digitalWrite(12, ledState);
  digitalWrite(13, ledState);
  delay(50);
}
