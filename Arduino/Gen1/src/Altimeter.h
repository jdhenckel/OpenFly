#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP3XX.h>


class Altimeter
{
public: 
    Adafruit_BMP3XX bmp;
    float seaLevel = 1013.25;   // units hPa.
    float pressure;             // units hPa.
    float meters;
    float celcius;

    // Methods
    void begin_I2C();
    void update();
    float feet() { return meters * 3.28084; }
    float farenheit() { return celcius * 9.0 / 5.0 + 32.0; }
};

void Altimeter::begin_I2C() {    
    bmp.begin_I2C();
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_16X);
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    bmp.setOutputDataRate(BMP3_ODR_50_HZ);
}

void Altimeter::update() {
    if (bmp.performReading()) {
        pressure = bmp.readPressure() / 100.0;
        meters = bmp.readAltitude(seaLevel);
        celcius = bmp.readTemperature();
    }
}