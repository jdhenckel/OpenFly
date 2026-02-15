#include <Arduino.h>
#include <Encoder.h>

// Connect your encoder to any two digital pins.
// On a Pro Micro, avoid pins 0/1 (USB serial).
// Example wiring:
Encoder knob(7, 8);

long lastPosition = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Rotary Encoder Test");
}

void loop() {
  long newPosition = knob.read();

  if (newPosition != lastPosition) {
    Serial.print("Position: ");
    Serial.println(newPosition);
    lastPosition = newPosition;
  }
}
