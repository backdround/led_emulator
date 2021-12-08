#pragma once

// Интерфейс светодиода.
class Gpio_interface {
public:
    virtual void set(bool state) = 0;
};
