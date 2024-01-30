//
// Created by Yves Peissard on 26/01/2024.
//

#include "user.h"
#include "Arduino.h"
#include "Led.h"
#include "Tempalarm.h"

#define STATE_OK 1
#define STATE_ALARM 2
#define STATE_WAITING_FOR_OK 3

namespace coffeeroasters {

    unsigned long _millis_since_waiting_for_ok;

    float _old_value;
    bool _is_first = true;
    bool _is_alarm_on = false;
    int _current_state = STATE_OK;

    void Tempalarm::init() {
        _led.init();
        _led.set_on(true);
        _buzzer.init();
        _buzzer.set_on(false);
    }

    void Tempalarm::update(float new_value) {
        if (_is_first) {
            _is_first = false;
            _old_value = new_value;
        } else {
            _buzzer.update();
            if (_current_state == STATE_OK) {
                if (new_value < _old_value) {
                    _current_state = STATE_ALARM;
                    _led.set_on(false);
                    _buzzer.set_on(true);
                }
            } else if (_current_state == STATE_ALARM) {
                if (new_value > _old_value) {
                    _current_state = STATE_WAITING_FOR_OK;
                    _millis_since_waiting_for_ok = millis();
                }
            } else if (_current_state == STATE_WAITING_FOR_OK){
                if (new_value > _old_value) {
                    if ((millis() - _millis_since_waiting_for_ok) >= GAS_ALARM_OK_VALUE_KEEP_TIME) {
                        _current_state = STATE_OK;
                        _led.set_on(true);
                        _buzzer.set_on(false);
                    }
                }
            }
            _old_value = new_value;
        }
    }
}