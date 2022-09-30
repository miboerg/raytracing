#include "include/Vec3.h"

/*
 * Class to represent a ray.
 */
class Ray {

private:
    Vec3 origin, direction, shift;

public:

    /*
     * Constructor of the Ray.
     * Accepts a Vec3 origin and a Vec3 shift.
     * The shift vector will be added to the origin to make a shift of the image possible.
     */
    Ray(Vec3 origin, Vec3 shift) : origin(origin), shift(shift), direction(Vec3(0, 0, 1)) {};

    // returns the origin of the ray
    Vec3 get_origin() const {
        return origin;
    }

    // returns the direction of the ray
    Vec3 get_direction() const {
        return direction;
    }

    /*
     * Takes a double t as argument which is the multiplier of the direction.
     * Calculates the position of the ray with adding the shift to the origin and with adding the direction multiplied with t.
     * Returns the calculated Vec3.
     */
    Vec3 get_pos(double t) {
        return get_origin() + get_direction() * t;
    }

};