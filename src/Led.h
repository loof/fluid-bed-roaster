//
// Created by Yves Peissard on 24/01/2024.
//

#include "Arduino.h"

#ifndef FLAME_SENSOR_LED_H
#define FLAME_SENSOR_LED_H





namespace coffeeroasters {

    class Led {

        bool _is_on;

    public:
        void set_on(bool is_on);
        void toggle();
        void init();
    };

} // coffeeroasters

#endif //FLAME_SENSOR_LED_H
