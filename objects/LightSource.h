#ifndef RAYTRACING_LIGHTSOURCE_H
#define RAYTRACING_LIGHTSOURCE_H


#include "../utils/include/Vec3.h"

/**
 * This class represents a light source which can be added to a world
 */
class LightSource {

private:
    Vec3 center;
    double intensity;

public:
    /**
     * Takes a Vec3 and double as input.
     * The Vec3 represents the center of the light source.
     * The double represents the intensity of the light source.
     * The value of the intensity must be between 1 and 0 and will be limited if the value isn't in this interval.
     */
    LightSource(Vec3 center, double intensity) : center(center), intensity(intensity) {
        if(intensity > 1) intensity = 1;
        if(intensity < 0) intensity = 0;
    };

    /**
     * Returns the center of the light source
     * @return center of type Vec3
     */
    Vec3 get_center() const {
        return center;
    }
    /**
     * Returns the intensity of the light source
     */
    double get_intensity() {
        return intensity;
    }

};


#endif //RAYTRACING_LIGHTSOURCE_H
