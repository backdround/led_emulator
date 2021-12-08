#pragma once
// Файл с функциями ptos'а, необходимых для совместимого кода.

#include <chrono>
#include <thread>


namespace ptos {
    using namespace std::chrono;
    using time = long;

    // Остановить процесс исполнения на t милисекунд.
    static void delay(time t) {
        std::this_thread::sleep_for(milliseconds(t));
    }

    // Получить время в данный момент.
    static time time_get() {
        auto current_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        return current_time.count();
    }

    // Интерфейс, для исполнения класса.
    class Runnable {
    public:
        virtual void run() = 0;
    };
}
