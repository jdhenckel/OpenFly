#include <Arduino.h>
/*
 * Plug in an OLED display
 */

class Display
{
public:
    Display(int pin1, int pin2 = 0);
    void update();

protected:
    int pin1;
};

Display::Display(int pin1, int pin2)
{
    this->pin1 = pin1;
    update();
}

void Display::update()
{
}

