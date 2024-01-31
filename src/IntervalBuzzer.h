//
// Created by Yves Peissard on 30/01/2024.
//

#ifndef FLUID_BED_ROASTER_INTERVALBUZZER_H
#define FLUID_BED_ROASTER_INTERVALBUZZER_H

#include "Arduino.h"
#include "Buzzer.h"

namespace coffeeroasters {

    class IntervalBuzzer {

    public:
        static void init();
        void update();
        bool isOn();
        void setOn(bool isOn);
    private:
        uint16_t _oldMillis = 0;
        uint16_t _newMillis = 0;
        uint16_t _timeElapsed = 0;
        bool _isSounding = false;
        bool _isOn = false;
        void _setSounding(bool is_sounding);
    };

} // coffeeroasters

#endif //FLUID_BED_ROASTER_INTERVALBUZZER_H
