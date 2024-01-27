//
// Created by Yves Peissard on 24/01/2024.
//

#include <Arduino.h>
#include "Led.h"

namespace coffeeroasters {
    Led::Led(unsigned int pin_r, unsigned int pin_g, unsigned int pin_b, unsigned int r, unsigned int g, unsigned  int b) {
        _pin_r = pin_r;
        _pin_g = pin_g;
        _pin_b = pin_b;
        _r = r;
        _g = g;
        _b = b;
    }

    void Led::init() {
        pinMode(_pin_r, OUTPUT);
        pinMode(_pin_g, OUTPUT);
        pinMode(_pin_b, OUTPUT);
    }

    void Led::update() {
        led_color(_r, _g, _b);
    }

    void Led::set_rgb_colors(unsigned int pin_r, unsigned int pin_g, unsigned int pin_b) {
        _r = pin_r;
        _g = pin_g;
        _b = pin_b;
    }

    void Led::set_on(bool is_on) {
        _is_on = is_on;
        if (is_on) {
            led_color(_r, _g, _b);
        } else {
            led_color(0, 0, 0);
        }
    }

    void Led::toggle() {
        if (_is_on) {
            led_color(0, 0, 0);
            _is_on = false;
        } else {
            led_color(_r, _g, _b);
            _is_on = true;
        }
    }

    void Led::led_color(int r_value, int g_value, int b_value) {
        analogWrite(_pin_r, r_value);
        analogWrite(_pin_g, g_value);
        analogWrite(_pin_b, b_value);
    }
} // coffeeroasters