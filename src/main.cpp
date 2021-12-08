// Основной файл программы.
#include <iostream>

#include "numeric_blinker.h"
#include "gpio_cli.h"

int main(int argc, char** argv) {
    // Создание блинкера и его зависимостей.
    bool clear_terminal = true;
    Gpio_cli gpio(clear_terminal);
    port::Numeric_blinker::config cfg = {
        gpio,
        10,
        1000
    };
    port::Numeric_blinker blinker(cfg);

    // Вызов блинкера каждые 50мс.
    while (true) {
        ptos::delay(50);
        blinker.run();
    }

    return 0;
}
