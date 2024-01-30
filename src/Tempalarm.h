//
// Created by Yves Peissard on 26/01/2024.
//

#ifndef FLUID_BED_ROASTER_TEMPALARM_H
#define FLUID_BED_ROASTER_TEMPALARM_H

#include "Arduino.h"
#include "Led.h"
#include "IntervalBuzzer.h"

namespace coffeeroasters {
    class Tempalarm {
    public:
        void init();
        void update(float new_value);
    private:
        IntervalBuzzer _buzzer;
        Led _led;
    };
}

#endif //FLUID_BED_ROASTER_TEMPALARM_H
