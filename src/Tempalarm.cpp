//
// Created by Yves Peissard on 26/01/2024.
//

#include "user.h"
#include "Arduino.h"
#include "Led.h"
#include "Tempalarm.h"

namespace coffeeroasters {

    void Tempalarm::init() {
        Led::init();
        _buzzer.init();
        Button::init();
        _led.setOn(true);
        _buzzer.setOn(false);
    }

    void Tempalarm::update(float newValue) {
        if (_isFirst) {
            _isFirst = false;
            _oldValue = newValue;
        } else {
            _buzzer.update();
            if (Button::isPressed()) {
                _buzzer.setOn(false);
            }
            if (_currentState == STATE_OK) {
                if (newValue < _oldValue) {
                    _currentState = STATE_ALARM;
                    _led.setOn(false);
                    _buzzer.setOn(true);
                }
            } else if (_currentState == STATE_ALARM) {
                if (newValue > _oldValue) {
                    _currentState = STATE_WAITING_FOR_OK;
                    _millisSinceWaitingForOk = millis();
                }
            } else if (_currentState == STATE_WAITING_FOR_OK){
                if (newValue > _oldValue) {
                    if ((millis() - _millisSinceWaitingForOk) >= GAS_ALARM_OK_VALUE_KEEP_TIME) {
                        _currentState = STATE_OK;
                        _led.setOn(true);
                        _buzzer.setOn(false);
                    }
                }
            }
            _oldValue = newValue;
        }
        _led.update();
        _buzzer.update();
    }
}