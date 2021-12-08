#include "gpio_cli.h"

Gpio_cli::Gpio_cli(bool clear_terminal) {
    clear_terminal_ = clear_terminal;

    // При создании отображаем выключеный светодиод.
    state_ = false;
    set(state_);
}

void Gpio_cli::set(bool new_state) {

    // Проверка на задание текущего состояния.
    if (state_ == new_state) {
        return;
    }

    // Очищаем терминал, при необходимости
    if (clear_terminal_) {
        system("clear");
    }

    state_ = new_state;

    // Выводим состояния светодиода.
    if (state_) {
        cout << "X" << endl;
    } else {
        cout << "O" << endl;
    }
}
