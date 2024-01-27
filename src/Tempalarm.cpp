//
// Created by Yves Peissard on 26/01/2024.
//

#include "Arduino.h"
#include "Led.h"
#include "Tempalarm.h"

namespace coffeeroasters {

    Led _led(PIN_R, PIN_G, PIN_B, COLOR_R, COLOR_G, COLOR_B);
    unsigned long _alarm_millis;
    float _old_value;
    bool _is_first = true;
    bool _is_alarm_on = false;

    void Tempalarm::init() {
        _led.init();
        _led.set_on(true);
    }

    void Tempalarm::update(float new_value) {
        if (_is_first) {
            _is_first = false;
            _old_value = new_value;
        } else {
            if (new_value < _old_value && !_is_alarm_on) {
                _led.set_on(false);
                _alarm_millis = millis();
                _is_alarm_on = true;
            } else if (new_value > _old_value && millis() - _alarm_millis >= OK_VALUE_KEEP_TIME && _is_alarm_on) {
                _led.set_on(true);
                _is_alarm_on = false;
            }
            _old_value = new_value;
        }
    }
}