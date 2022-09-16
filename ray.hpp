#include "utils/include/Vec3.h"

class Ray {

private:
    Vec3 origin, direction;

public:
    Ray(Vec3 origin, Vec3 direction) : origin(origin), direction(direction){};

    Vec3 get_origin() const {
        return origin;
    }


    Vec3 get_direction() const {
        return direction;
    }

    Vec3 get_pos(double t) {
        return get_origin()+get_direction()*t;
    }

};