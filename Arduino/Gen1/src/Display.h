#include <Arduino.h>
#include <U8g2lib.h>

// Note: you may need to enhance the contructor to support other displays.
// Just copy the from U8g2lib specific constructor.

class Display : public U8G2
{
public:
    Display(const u8g2_cb_t *rotation, uint8_t reset = U8X8_PIN_NONE);
    void print(uint16_t x, uint16_t y, const char* s);
    void print(uint16_t x, uint16_t y, int n);
    void print(uint16_t x, uint16_t y, float f);
    void big() { setFont(u8g2_font_fub17_tr); }
    void small() { setFont(u8g2_font_luRS08_tr); }
    void eraseRows(uint16_t y, uint16_t h=0);
};

Display::Display(const u8g2_cb_t *rotation, uint8_t reset)
{
    uint8_t clock = U8X8_PIN_NONE;
    uint8_t data = U8X8_PIN_NONE;
    u8g2_Setup_ssd1309_i2c_128x64_noname0_f(&u8g2, rotation, 
            u8x8_byte_arduino_hw_i2c, u8x8_gpio_and_delay_arduino);
    u8x8_SetPin_HW_I2C(getU8x8(), reset, clock, data);
    small();
}

void Display::print(uint16_t x, uint16_t y, const char* s) { 
    drawStr(x, y + getAscent(), s);
}

void Display::print(uint16_t x, uint16_t y, int n) { 
    char buf[10];
    itoa(n, buf, 10);
    print(x, y, buf);
}

void Display::print(uint16_t x, uint16_t y, float f) { 
    char buf[10];
    dtostrf(f, 4, 2, buf);
    print(x, y, buf);
}

void Display::eraseRows(uint16_t y, uint16_t h) {
    // y is the top row to erase, h is the number of pixels to erase. 
    if (h==0) h = getAscent() + getDescent() + 2;  // default erase text
    setDrawColor(0);
    drawBox(0, y, 128, h);
    setDrawColor(1);
}
