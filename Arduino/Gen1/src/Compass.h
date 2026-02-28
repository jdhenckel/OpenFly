#include <Adafruit_HMC5883_U.h>

class Compass
{
public:
    Adafruit_HMC5883_Unified hmc;
    float x,y,z,o;

    Compass() {}
    bool begin() { return hmc.begin(); }
    void update();
    float heading();   // Returns 0 to 360.
};

void Compass::update() {
    sensors_event_t event;
    hmc.getEvent(&event);
    x = event.magnetic.x;
    y = event.magnetic.y;
    z = event.magnetic.z;        
}


float Compass::heading() {
    // NOTE!!! this assumes North is -Y and East is +X.
    // If you have a different orientation, you may need to swap or negate them.
    float heading = atan2(-y, x);
    if (heading < 0) {
        heading += 2 * PI;
    }
    return heading * 180 / PI;
}