//
// Created by Yves Peissard on 26/01/2024.
//

#ifndef FLUID_BED_ROASTER_TEMPALARM_H
#define FLUID_BED_ROASTER_TEMPALARM_H

#include "Arduino.h"
#include "Led.h"
#include "IntervalBuzzer.h"
#include "Button.h"

#define STATE_OK 1
#define STATE_ALARM 2
#define STATE_WAITING_FOR_OK 3

namespace coffeeroasters {
    class Tempalarm {
    public:
        void init();
        void update(float new_value);
    private:
        IntervalBuzzer _buzzer;
        Led _led;
        Button _button;
        unsigned long _millis_since_waiting_for_ok;
        float _old_value;
        bool _is_first = true;
        int _current_state = STATE_OK;
    };
}

#endif //FLUID_BED_ROASTER_TEMPALARM_H
