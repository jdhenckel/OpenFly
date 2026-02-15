#include <Arduino.h>
#include "Button.h"
#include "Display.h"
#include "Light.h"

Button button(2);

void setup() {
    Serial.begin(9600);
    Serial.println("Hello, World!");
}

void loop() {
    Serial.println("Looping...");
    delay(1000);
}

