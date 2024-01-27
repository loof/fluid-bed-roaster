//
// Created by Yves Peissard on 26/01/2024.
//

#ifndef FLUID_BED_ROASTER_TEMPALARM_H
#define FLUID_BED_ROASTER_TEMPALARM_H

#include "Arduino.h"
#include "Led.h"

#define CRITICAL_ROR_DELTA -1
#define OK_ROR_DELTA 1
#define OK_VALUE_KEEP_TIME 3000

namespace coffeeroasters {
    class Tempalarm {
    public:
        void init();
        void update(float new_value);
    };
}

#endif //FLUID_BED_ROASTER_TEMPALARM_H
