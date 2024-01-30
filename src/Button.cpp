//
// Created by Yves Peissard on 30/01/2024.
//

#include "Arduino.h"
#include "user.h"
#include "Button.h"

namespace coffeeroasters {
    void Button::init() {
        pinMode(PIN_GAS_ALARM_MUTE_BUTTON, INPUT_PULLUP);
    }
    bool Button::is_pressed() {
        return !digitalRead(PIN_GAS_ALARM_MUTE_BUTTON);
    }
} // coffeeroasters