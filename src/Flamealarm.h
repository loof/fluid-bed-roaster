//
// Created by Yves Peissard on 30/01/2024.
//

#ifndef FLUID_BED_ROASTER_FLAMEALARM_H
#define FLUID_BED_ROASTER_FLAMEALARM_H

#include "FlameSensor.h"
#include "Buzzer.h"

namespace coffeeroasters {

    class Flamealarm {

    public:
        static void init();
        void update();
    private:
        Buzzer _buzzer;
        FlameSensor _flameSensor;
    };

} // coffeeroasters

#endif //FLUID_BED_ROASTER_FLAMEALARM_H
