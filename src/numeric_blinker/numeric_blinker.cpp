#include <iostream>
using namespace std;

#include "numeric_blinker.h"
#include "ptos.h"


using namespace port;

Numeric_blinker::Numeric_blinker(const config& cfg) : cfg_(cfg) {
}

void Numeric_blinker::run() {
    // Включаем светодиод
    cfg_.gpio.set(true);

    cout << "hi" << endl;
}
