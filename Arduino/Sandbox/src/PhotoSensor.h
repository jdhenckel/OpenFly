
#include <Arduino.h>

/*
 * Use this to send AT+ commands to the SIM7600
 */

class PhotoSensor
{
public:

    void update();    // call this every timestep (100 ms)
    String info();
    const char* reason();

    int voltage;   // This is the active value
    int pin = A5;
    int threshold = 111;
    int deadzone = 50;     // ignore changes within threashold +/- deadzone
    int smooth = 10;
    int vHigh;
    int vLow = 9999;

    bool isDoorOpen = true;
    bool isChanged;

    int counter;    // to count how long the voltage is above or below threshold.
};

/*
NOTE This assumes update is called once per 100 ms.  So counter > 30 means 3 seconds.
*/
void PhotoSensor::update()
{
    int raw = analogRead(pin);
    voltage = (voltage * (smooth-1) + raw) / smooth;
    if (voltage > vHigh) vHigh = voltage;
    if (voltage < vLow) vLow = voltage;

    bool wasOpen = isDoorOpen;

    // Detect CHANGES in DOOR state
    if (isDoorOpen && voltage < threshold - deadzone)
    {
        if (++counter > 100)   // This indicates a change from DOOR OPEN to SHUT
            isDoorOpen = false;
    }
    else if (!isDoorOpen && voltage > threshold + deadzone)
    {
        if (++counter > 30)   // This indicates a change from DOOR SHUT to OPEN
            isDoorOpen = true;
    }
    else
        counter = 0;

    isChanged = (wasOpen != isDoorOpen);
}


String PhotoSensor::info()
{
    String a = String(";vh=") + vHigh + ";vl=" + vLow;
    vHigh = 0;
    vLow = 9999;
    return a;    
}

const char* PhotoSensor::reason()
{
    if (threshold == 111) return "boot";
    return isDoorOpen ? "open" : "shut";
}

