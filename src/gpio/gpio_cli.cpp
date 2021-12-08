#include "gpio_cli.h"

Gpio_cli::Gpio_cli(bool clear_terminal) {
    clear_terminal_ = clear_terminal;

    // При создании отображаем выключеный светодиод.
    set(false);
}

void Gpio_cli::set(bool new_state) {

    // Пропуск повторного включения или выключения.
    if (state_ != State::UNINITED) {
        if (state_ == State::ON && new_state) {
            return;
        }
        if (state_ == State::OFF && !new_state) {
            return;
        }
    }

    // Очищаем терминал, при необходимости
    if (clear_terminal_) {
        system("clear");
    }

    // Меняем состояние светодиода
    if (new_state) {
        state_ = State::ON;
    } else {
        state_ = State::OFF;
    }

    // Выводим состояния светодиода.
    if (state_ == State::ON) {
        cout << "X" << endl;
    } else {
        cout << "O" << endl;
    }
}

bool Gpio_cli::get() {
    return state_ == State::ON;
}
