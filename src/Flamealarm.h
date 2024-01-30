//
// Created by Yves Peissard on 30/01/2024.
//

#ifndef FLUID_BED_ROASTER_FLAMEALARM_H
#define FLUID_BED_ROASTER_FLAMEALARM_H

#include "FlameSensor.h"
#include "Buzzer.h"

namespace coffeeroasters {

    class Flamealarm {

        Buzzer _buzzer;
        FlameSensor _flame_sensor;

    public:
        void init();
        void update();
    };

} // coffeeroasters

#endif //FLUID_BED_ROASTER_FLAMEALARM_H
