#pragma once

// Интерфейс светодиода.
class Gpio_interface {
public:
    // Задать текущее состояние.
    virtual void set(bool state) = 0;

    // Получить текущее состояние.
    virtual bool get() = 0;
};
