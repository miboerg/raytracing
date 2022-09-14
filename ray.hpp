#include "Vec3.hpp"

class Ray {

private:
    Vec3 origin, direction;

public:
    Ray(Vec3 origin, Vec3 direction) : origin(origin), direction(direction){};

    Vec3 getOrigin() const {
        return origin;
    }


    Vec3 getDirection() const {
        return direction;
    }

};