//
// Created by Yves Peissard on 30/01/2024.
//

#include "Flamealarm.h"

namespace coffeeroasters {

    void Flamealarm::init() {
        _flame_sensor.init();
        _buzzer.init();
    }

    void Flamealarm::update() {
        _buzzer.set_on(!_flame_sensor.is_flame_detected());
    }
} // coffeeroasters