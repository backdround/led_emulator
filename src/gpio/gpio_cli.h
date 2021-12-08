#pragma once
#include <iostream>
#include "gpio_interface.h"
using namespace std;

// Эмуляция светодиода, выводящая текущее значение в терминал.
class Gpio_cli : public Gpio_interface {
public:
    // clear_terminal - Нужно ли очищать экран перед выводом
    // состояния светодиода.
    Gpio_cli(bool clear_terminal);

    void set(bool state) override;

private:
    // Флаг необходимости очищать экран перед изменением состояния
    // светодиода.
    bool clear_terminal_;

    // Текущее состояние светодиода.
    bool state_;
};
