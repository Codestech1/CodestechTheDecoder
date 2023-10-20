0#define button 5
#define greenLed 10
#define redLed 8
#define del 1000

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  // Mark the red led as enabled by default
  digitalWrite(redLed, HIGH);
}

void loop() {
  // Add a delay
  delay(del);
  // Mark the window as open if the button is pressed...
  if (digitalRead(button) == HIGH) {
    markOpen();
    return;
  }
  // ... or mark it as disabled otherwise.
  markClosed();
}

void markOpen() {
  // Disable the red led
  digitalWrite(redLed, LOW);
  // Enable the green led
  digitalWrite(greenLed, HIGH);
  // Send an information to the console
  Serial.println("Okno jest otwarte");
}

void markClosed() {
  // Disable the green led
  digitalWrite(greenLed, LOW);
  // Enable the red led
  digitalWrite(redLed, HIGH);
  // Send an information to the console
  Serial.println("Okno jest zamknięte");
}