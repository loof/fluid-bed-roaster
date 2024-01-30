//
// Created by Yves Peissard on 30/01/2024.
//

#ifndef FLUID_BED_ROASTER_INTERVALBUZZER_H
#define FLUID_BED_ROASTER_INTERVALBUZZER_H

#include "Arduino.h"
#include "Buzzer.h"

namespace coffeeroasters {

    class IntervalBuzzer : public Buzzer {

    public:
        void update();
    private:
        uint16_t _old_millis = 0;
        uint16_t _new_millis = 0;
        uint16_t _time_elapsed = 0;
        bool _is_sounding = false;
        void _set_sounding(bool is_sounding);
    };

} // coffeeroasters

#endif //FLUID_BED_ROASTER_INTERVALBUZZER_H
