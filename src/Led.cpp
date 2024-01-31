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

    void Led::setOn(bool isOn) {
        _isOn = isOn;
    }

    void Led::toggle() {
        setOn(!_isOn);
    }

    void Led::update() {
        if (_isOn) {
            digitalWrite(PIN_LED_GAS_ALARM, HIGH);
        } else {
            digitalWrite(PIN_LED_GAS_ALARM, LOW);
        }
    }


} // coffeeroasters