#include <Arduino.h>

class LoopPacer {
public:
    LoopPacer(uint32_t targetMs) {
        target = targetMs;
        last = millis();
    }

    void update() {
        uint32_t now = millis();
        uint32_t elapsed = now - last;

        if (elapsed < target)
            delay(target - elapsed);
        last = now;
    }

private:
    uint32_t target;
    uint32_t last;
};
