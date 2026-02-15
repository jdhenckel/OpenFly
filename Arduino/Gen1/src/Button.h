#include <Arduino.h>
/*
 * Plug in a button with one wire in pin1 and the other in pin2 (or any pin that is LOW)
 */

class Button
{
public:
    Button(int pin1, int pin2 = 0);
    void update();
    bool isPressed();
    bool isLongPressed(int ms);
    void waitForRelease();

protected:
    int pin1;
    int state; // LOW = button is down
    unsigned long lastChange;
};

Button::Button(int pin1, int pin2)
{
    this->pin1 = pin1;
    state = 999; // force change during update
    lastChange = 0;
    pinMode(pin1, INPUT_PULLUP);
    if (pin2 > 0)
    {
        pinMode(pin2, OUTPUT);
        digitalWrite(pin2, LOW);
    }
    update();
}

void Button::update()
{
    int old = state;
    state = digitalRead(pin1);
    if (old != state)
        lastChange = millis();
}

void Button::waitForRelease()
{
    while (isPressed()) {
        delay(10);
        update();
    }
}

bool Button::isPressed()
{
    return state == LOW;
}

bool Button::isLongPressed(int ms)
{
    return isPressed() && (millis() - lastChange) > (unsigned long)ms;
}
