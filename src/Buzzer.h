//
// Created by Yves Peissard on 30/01/2024.
//

#ifndef FLUID_BED_ROASTER_BUZZER_H
#define FLUID_BED_ROASTER_BUZZER_H

namespace coffeeroasters {

    class Buzzer {

    public:
        static void init();
        void setOn(bool isOn);
        bool isOn();
        void toggle();
        void update();
    private:
        bool _isOn = false;
    };

} // coffeeroasters

#endif //FLUID_BED_ROASTER_BUZZER_H
