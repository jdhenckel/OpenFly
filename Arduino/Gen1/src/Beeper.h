#include <Arduino.h>
/*
 * Plug in a button with one wire in pin1 and the other in pin2 (or any pin that is LOW)
 */

class Beeper
{
public:
    Beeper(int pin1, int pin2 = 0);
    void update(float level);
    void play(int value);

public:
    int pin1;
    int base;
    int duration;
    static const int scale[7];
};

const int Beeper::scale[] = {440,494,554,587,660,740,831};

Beeper::Beeper(int pin1, int pin2)
{
    this->pin1 = pin1;
    base = 0;
    duration = 500;
    pinMode(pin1, OUTPUT);
    if (pin2 > 0)
    {
        pinMode(pin2, OUTPUT);
        digitalWrite(pin2, LOW);
    }
}

void Beeper::update(float level)
{
    int line = (level + 0.5) * 3.28 * 2; // 2 lines per foot
    int diff = line - base;
    if (diff) {
        play(line);
    }
    base = line;
}

void Beeper::play(int value)
{
    int N = sizeof(scale) / sizeof(scale[0]);
    value = (value % N + N) % N;
    tone(pin1, scale[value], duration);
    //tone(pin1, 440 * pow(2.0, value / 12.0), duration);
}
    
