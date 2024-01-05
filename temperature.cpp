#include <LiquidCrystal.h>

#define updateDelay 1000

#define width 20
#define height 4

#define sensor 0

float temperature;

float min = 3.402823466e+38;
float max = 1.175494351e-38;

LiquidCrystal display(12, 11, 10, 9, 8, 7);

void setup() {
  Serial.begin(9600);

  // Enable the display
  display.begin(width, height);
  // Reset the cursor of display
  display.setCursor(0, 0);
  // Print the header
  display.print("    Temperature    ");
}

void loop() {
  // Read the temperature
  temperature = analogRead(sensor) * 0.48828125;
  // Update min and max values
  if (temperature < min)
    min = temperature;
  if (temperature > max)
    max = temperature;
  // Set the cursor of the display to next line
  display.setCursor(0, 1);
  // Print the temperature
  display.print("Current: " + ((String) temperature) + " *C");
  // Set the cursor of the display to next line
  display.setCursor(0, 2);
  // Display min temperature
  display.print("Min: " + ((String) (min)) + " *C");
  // Set the cursor of the display to next line
  display.setCursor(0, 3);
  // Display max temperature
  display.print("Max: " + ((String) (max)) + " *C");
  // Wait to the next loop call
  delay(updateDelay);
}