#pragma once

#include "gpio_interface.h"
#include "ptos.h"

namespace port {

class Numeric_blinker : public ptos::Runnable {
public:
    struct config {
        Gpio_interface& gpio;
        uint8_t blink_count;
        ptos::time period;
    };

    Numeric_blinker(const config& cfg);

    // Эта функция периодически вызывается из main.
    void run() override;

private:
    const config& cfg_;
};
} // namespace port
