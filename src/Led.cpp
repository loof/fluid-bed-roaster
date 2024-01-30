//
// Created by Yves Peissard on 24/01/2024.
//

#include <Arduino.h>
#include "user.h"
#include "Led.h"

namespace coffeeroasters {


    void Led::init() {
        pinMode(PIN_LED_GAS_ALARM, OUTPUT);
    }

    void Led::set_on(bool is_on) {
        _is_on = is_on;
        if (is_on) {
            digitalWrite(PIN_LED_GAS_ALARM, HIGH);
        } else {
            digitalWrite(PIN_LED_GAS_ALARM, LOW);
        }
    }

    void Led::toggle() {
        if (_is_on) {
            digitalWrite(PIN_LED_GAS_ALARM, LOW);
            _is_on = false;
        } else {
            digitalWrite(PIN_LED_GAS_ALARM, HIGH);
            _is_on = true;
        }
    }

} // coffeeroasters