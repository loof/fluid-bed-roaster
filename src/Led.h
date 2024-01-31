//
// Created by Yves Peissard on 24/01/2024.
//

#include "Arduino.h"

#ifndef FLAME_SENSOR_LED_H
#define FLAME_SENSOR_LED_H





namespace coffeeroasters {

    class Led {

    public:
        void setOn(bool isOn);
        void toggle();
        static void init();
        void update();
    private:
        bool _isOn = false;
    };

} // coffeeroasters

#endif //FLAME_SENSOR_LED_H
