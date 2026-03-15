#include <Arduino.h>
#include <Encoder.h>

#include "Altimeter.h"
#include "Button.h"
#include "Beeper.h"
#include "Display.h"
#include "Compass.h"
#include "Light.h"
#include "LoopPacer.h"


class BaseApp
{
public:
    Button button1;
    Button button2;
    Button button3;
    Button button4;
    Encoder encoder;
    Altimeter altimeter;
    Compass compass;
    Display display;
    int32_t knob;

    BaseApp():
        button1(14), button2(16), button3(10), button4(9),
        encoder(7, 8), altimeter(), compass(), display(U8G2_R0, 4)
    {
    }

    void begin() {        
        altimeter.begin_I2C();
        compass.begin();
        display.begin();
    }


    void update() {
        altimeter.update();
        compass.update();
        button1.update();
        button2.update();
        button3.update();
        button4.update();
        knob = encoder.read();
    }
};


// class TestApp : public BaseApp
// {
//     LoopPacer pacer;

// public:
//     TestApp() : BaseApp(), pacer(50) {}

//     void update() {
//         BaseApp::update();

//         display.big();
//         display.eraseRows(0);
//         display.print(0, 0, "Altimeter Test");
//         display.small();
//         display.eraseRows(20);
//         display.print(0, 20, "Hello");
//         display.print(50, 20, (int) button1.isPressed());
//         display.print(60, 20, (int) button2.isPressed());
//         display.print(70, 20, (int) button3.isPressed());
//         display.print(80, 20, (int) button4.isPressed());
//         display.print(90, 20, (int) knob);
//         display.eraseRows(40);
//         display.print(0, 40, "Feet:");
//         display.print(50, 40, altimeter.feet());

//         static float a = altimeter.feet();
//         a = a * 0.98 + altimeter.feet() * 0.02;
//         display.eraseRows(50);
//         display.print(0, 50, "Smooth:");
//         display.print(50, 50, a);

//         display.sendBuffer();

//         pacer.update();
//     }
// };




class SoundApp : public BaseApp
{
    LoopPacer pacer;
    Beeper beeper;

public:
    SoundApp() : BaseApp(), pacer(500), beeper(15) {}

    void update() {
        BaseApp::update();

        beeper.update(altimeter.meters);

        // display.big();
        // display.eraseRows(0);
        // display.print(0, 0, "Beeper");
        display.small();
        display.eraseRows(20);
        display.print(0, 20, "Hello");
        display.print(50, 20, (int) button1.isPressed());
        display.print(60, 20, (int) button2.isPressed());
        display.print(70, 20, (int) button3.isPressed());
        display.print(80, 20, (int) button4.isPressed());
        display.print(90, 20, (int) knob);
        display.eraseRows(40);
        display.print(0, 40, "Feet:");
        display.print(50, 40, altimeter.feet());

        display.eraseRows(50);        
        display.print(0, 50, "Base:");
        display.print(50, 50, beeper.base);


        display.sendBuffer();

        pacer.update();
    }
};