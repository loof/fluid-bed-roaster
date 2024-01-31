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
    void Buzzer::setOn(bool isOn) {
        _isOn = isOn;
    }

    bool Buzzer::isOn() {
        return _isOn;
    }

    void Buzzer::toggle() {
        setOn(!_isOn);
        _isOn = !_isOn;
    }

    void Buzzer::update() {
        if (isOn) {
            digitalWrite(PIN_BUZZER_GAS_ALARM, HIGH);
        } else {
            digitalWrite(PIN_BUZZER_GAS_ALARM, LOW);
        }
    }

} // coffeeroasters