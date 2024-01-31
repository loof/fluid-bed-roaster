//
// Created by Yves Peissard on 30/01/2024.
//

#ifndef FLUID_BED_ROASTER_FLAMESENSOR_H
#define FLUID_BED_ROASTER_FLAMESENSOR_H

#define FLAME_SENSOR 7

namespace coffeeroasters {

    class FlameSensor {
    public:
        static void init();
        static bool isFlameDetected();
    };

} // coffeeroasters

#endif //FLUID_BED_ROASTER_FLAMESENSOR_H
