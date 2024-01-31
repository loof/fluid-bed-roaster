//
// Created by Yves Peissard on 30/01/2024.
//

#include "Flamealarm.h"

namespace coffeeroasters {

    void Flamealarm::init() {
        FlameSensor::init();
        Buzzer::init();
    }

    void Flamealarm::update() {
        _buzzer.setOn(!FlameSensor::isFlameDetected());
        _buzzer.update();
    }
} // coffeeroasters