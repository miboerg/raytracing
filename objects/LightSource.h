//
// Created by micha on 16/09/2022.
//

#ifndef RAYTRACING_LIGHTSOURCE_H
#define RAYTRACING_LIGHTSOURCE_H


#include "../utils/include/Vec3.h"

class LightSource {
private:
    Vec3 center;

public:
    LightSource(Vec3 center) : center(center) {};

    Vec3 get_center() {
        return center;
    }
};


#endif //RAYTRACING_LIGHTSOURCE_H
