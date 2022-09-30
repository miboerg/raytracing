//
// Created by micha on 16/09/2022.
//

#ifndef RAYTRACING_LIGHTSOURCE_H
#define RAYTRACING_LIGHTSOURCE_H


#include "../utils/include/Vec3.h"

class LightSource {
private:
    Vec3 center;
    double intensity;

public:
    LightSource(Vec3 center, double intensity) : center(center), intensity(intensity) {
        if(intensity > 1) intensity = 1;
        if(intensity < 0) intensity = 0;
    };

    Vec3 get_center() const {
        return center;
    }
    double get_intensity() {
        return intensity;
    }

};


#endif //RAYTRACING_LIGHTSOURCE_H
