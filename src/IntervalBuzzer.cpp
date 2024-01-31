//
// Created by Yves Peissard on 30/01/2024.
//

#include "IntervalBuzzer.h"
#include "user.h"

namespace coffeeroasters {

    void Buzzer::init() {
        pinMode(PIN_BUZZER_GAS_ALARM, OUTPUT);
    }

    void IntervalBuzzer::update() {
        _newMillis = millis();
        _timeElapsed = _timeElapsed + (_newMillis - _oldMillis);
        _oldMillis = _newMillis;
        if (_timeElapsed >= GAS_ALARM_BUZZER_INTERVAL_TIME) {
            if (isOn()) {
                _setSounding(!_isSounding);
            }

            _timeElapsed = 0;
        }
        if (_isOn) {
            if (_isSounding) {
                digitalWrite(PIN_BUZZER_GAS_ALARM, HIGH);
            } else {
                digitalWrite(PIN_BUZZER_GAS_ALARM, LOW);
            }
        } else {
            digitalWrite(PIN_BUZZER_GAS_ALARM, LOW);
        }
    }


    void IntervalBuzzer::_setSounding(bool is_sounding) {
        _isSounding = is_sounding;
    }

    bool IntervalBuzzer::isOn() {
        return _isOn;
    }

    void IntervalBuzzer::setOn(bool isOn) {
        _isOn = isOn;
    }


} // coffeeroasters