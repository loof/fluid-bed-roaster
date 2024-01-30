//
// Created by Yves Peissard on 30/01/2024.
//

#include "IntervalBuzzer.h"
#include "user.h"

namespace coffeeroasters {
    void IntervalBuzzer::update() {
        _new_millis = millis();
        _time_elapsed = _time_elapsed + (_new_millis - _old_millis);
        _old_millis = _new_millis;
        if (_time_elapsed >= GAS_ALARM_BUZZER_INTERVAL_TIME) {
            if (_is_on) {
                _set_sounding(!_is_sounding);
            }

            _time_elapsed = 0;
        }
    }
    void IntervalBuzzer::_set_sounding(bool is_sounding) {
        _is_sounding = is_sounding;
        if (is_sounding) {
            digitalWrite(PIN_BUZZER_GAS_ALARM, HIGH);
        } else {
            digitalWrite(PIN_BUZZER_GAS_ALARM, LOW);
        }
    }
} // coffeeroasters