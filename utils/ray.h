#include "include/Vec3.h"

class Ray {

private:
    Vec3 origin, direction, shift;

public:

    Ray(Vec3 origin, Vec3 shift) : origin(origin), shift(shift), direction(Vec3(0, 0, 1)) {};

    Vec3 get_origin() const {
        return origin;
    }


    Vec3 get_direction() const {
        return direction;
    }

    Vec3 get_pos(double t) {
        return get_origin() + get_direction() * t;
    }

};