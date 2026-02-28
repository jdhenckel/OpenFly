#include <Arduino.h>
#include <Encoder.h>
#include "Altimeter.h"
#include "Button.h"
#include "Display.h"
#include "Compass.h"
#include "Light.h"
#include "LoopPacer.h"

Button button1(14);
Button button2(16);
Button button3(10);
Button button4(9);
Encoder knob(7, 8);
Altimeter altimeter;
Compass compass;
Display display(U8G2_R0, 4);
LoopPacer pacer(50);


void setup() {
    Serial.begin(9600);
    delay(100);

    altimeter.begin_I2C();
    compass.begin();
    display.begin();

    display.clearBuffer();
    display.print(0, 20,"Hello");
    display.sendBuffer();
    
}

int32_t k;
float a = 700;

void loop() {
    altimeter.update();
    compass.update();
    button1.update();
    button2.update();
    button3.update();
    button4.update();
    k = knob.read();
    // Serial.print("Feet: ");
    // Serial.print(altimeter.feet());
    // Serial.print(" Buttons: ");
    // Serial.print(button1.isPressed());
    // Serial.print(" ");
    // Serial.print(button2.isPressed());
    // Serial.print(" ");
    // Serial.print(button3.isPressed());
    // Serial.print(" Knob: ");
    // Serial.print(button4.isPressed());
    // Serial.print(" ");
    // Serial.print(k);
    //Serial.println("   ok");

    display.big();
    display.eraseRows(0);
    display.print(0, 0, "Altimeter Test");
    display.small();
    display.eraseRows(20);
    display.print(0, 20, "Hello");
    display.print(50, 20, (int) button1.isPressed());
    display.print(60, 20, (int) button2.isPressed());
    display.print(70, 20, (int) button3.isPressed());
    display.print(80, 20, (int) button4.isPressed());
    display.print(90, 20, (int) k);
    display.eraseRows(40);
    display.print(0, 40, "Feet:");
    display.print(50, 40, altimeter.feet());
    display.eraseRows(50);
    a = a * 0.98 + altimeter.feet() * 0.02;
    display.print(0, 50, "Smooth:");
    display.print(50, 50, a);

    display.sendBuffer();


    pacer.update();
}

