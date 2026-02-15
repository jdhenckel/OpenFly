#include <Arduino.h>
/*
 * Plug in an LED with the LONG wire (positive) in pin1 and the short wire in GND or pin2,
 * then create the light and turn it off/on/blink etc.
 */

class Light
{
public:
    Light(int pin1, int pin2 = 0);
    void update();
    void set(bool turnON);
    bool isON() { return state == HIGH; }
    void toggle() { set(!isON()); }
    void blink(int ms) { rate = ms; }

protected:
    int pin1;
    int state;
    int rate; // rate of blinking (0=none)
    unsigned long lastChange;
};

Light::Light(int pin1, int pin2)
{
    this->pin1 = pin1;
    rate = 0;
    lastChange = 0;
    pinMode(pin1, OUTPUT);
    if (pin2 > 0)
    {
        pinMode(pin2, OUTPUT);
        digitalWrite(pin2, LOW);
    }
    set(false);
}

void Light::update()
{
    unsigned long now = millis();
    if (rate > 0 && now - lastChange > (unsigned long)rate)
    {
        lastChange = now;
        state = state == LOW ? HIGH : LOW;
        digitalWrite(pin1, state);
    }
}

void Light::set(bool turnON)
{
    state = turnON ? HIGH : LOW;
    digitalWrite(pin1, state);
    rate = 0;
}
