#include "include/Vec3.h"


class Ray {

private:
    Vec3 origin, direction, shift;

public:

    /** @brief
     * Constructor of the Ray.
     * Accepts a Vec3 origin and a Vec3 shift.
     * The shift vector will be added to the origin to make a shift of the image possible.
     */
    Ray(Vec3 origin, Vec3 shift) : origin(origin), shift(shift), direction(Vec3(0, 0, 1)) {};

   /** @brief
    * This function returns the origin of the ray
    *
    * @return origin of type Vec3
    */
    Vec3 get_origin() const {
        return origin;
    }

    /** @brief
     * This function returns the direction of the ray
     *
     * @return direction of type Vec3
     */
    Vec3 get_direction() const {
        return direction;
    }

    /** @brief
     * Calculates the position according to the input value.
     *
     * Takes a double t as argument which is the multiplier of the direction.
     * Calculates the position of the ray with adding the shift to the origin and with adding the direction multiplied with t.
     * Returns the calculated Vec3.
     */
    Vec3 get_pos(double t) {
        return get_origin() + get_direction() * t;
    }

};