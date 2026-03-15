#include <Arduino.h>

#include "Apps.h"

//TestApp app;
SoundApp app;

void setup() {
    Serial.begin(9600);
    delay(100);
    app.begin();
}

void loop() {
    app.update();
}
