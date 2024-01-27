//
// Created by Yves Peissard on 24/01/2024.
//

#include "Arduino.h"

#ifndef FLAME_SENSOR_LED_H
#define FLAME_SENSOR_LED_H

#define PIN_R 3
#define PIN_G 5
#define PIN_B 6
#define DEFAULT_R 0
#define DEFAULT_G 0
#define DEFAULT_B 0
#define COLOR_R 0
#define COLOR_G 255
#define COLOR_B 0



namespace coffeeroasters {

    class Led {
    public:
        Led(unsigned int pin_r, unsigned int pin_g, unsigned int pin_b, unsigned int r, unsigned int g, unsigned b);

        void set_rgb_colors(unsigned int pin_r, unsigned int pin_g, unsigned int pin_b);

        void set_on(bool is_on);

        void toggle();

        void init();

        void update();


    private:
        unsigned int _pin_r;
        unsigned int _pin_g;
        unsigned int _pin_b;
        unsigned int _r;
        unsigned int _g;
        unsigned int _b;
        bool _is_on;
        void led_color(int r_value, int g_value, int b_value);
    };

} // coffeeroasters

#endif //FLAME_SENSOR_LED_H
