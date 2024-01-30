//
// Created by Yves Peissard on 30/01/2024.
//

#include "Arduino.h"
#include "user.h"
#include "Buzzer.h"

namespace coffeeroasters {

    void Buzzer::init() {
        pinMode(PIN_BUZZER_GAS_ALARM, OUTPUT);
    }
    void Buzzer::set_on(bool is_on) {
        _is_on = is_on;
        if (is_on) {
            digitalWrite(PIN_BUZZER_GAS_ALARM, HIGH);
        } else {
            digitalWrite(PIN_BUZZER_GAS_ALARM, LOW);
        }
    }

    void Buzzer::toggle() {
        set_on(!_is_on);
        _is_on = !_is_on;
    }
} // coffeeroasters