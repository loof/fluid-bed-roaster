//
// Created by Yves Peissard on 30/01/2024.
//

#include "Arduino.h"
#include "FlameSensor.h"

namespace coffeeroasters {
    void FlameSensor::init() {
        pinMode(FLAME_SENSOR, INPUT);
    }

    bool FlameSensor::is_flame_detected() {
        return !digitalRead(FLAME_SENSOR);
    }
} // coffeeroasters