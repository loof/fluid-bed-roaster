//
// Created by Yves Peissard on 30/01/2024.
//

#ifndef FLUID_BED_ROASTER_BUZZER_H
#define FLUID_BED_ROASTER_BUZZER_H

namespace coffeeroasters {

    class Buzzer {

    public:
        static void init();
        void set_on(bool is_on);
        bool is_on();
        void toggle();
    private:
        bool _is_on = false;
    };

} // coffeeroasters

#endif //FLUID_BED_ROASTER_BUZZER_H
