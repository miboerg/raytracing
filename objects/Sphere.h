#include "../utils/ray.h"
#include "../utils/Color.h"
#include <cmath>

/**
 * This class represents a sphere object which can be added to a world
 */

class Sphere {


private:
    Vec3 center;
    double radius, radius2;
    Color color;


public:
    Sphere() = default;

    /**
     * Takes a Vec3 and double as input.
     * The Vec3 represents the center of the sphere.
     * The double represents the radius of the sphere
     * The default color is set to red.
     */
    Sphere(Vec3 center, double radius) : center(center),
                                         radius(radius),
                                         radius2(radius * radius),
                                         color(Color::red()) {};

    /**
     * Takes a Vec3, double and color as input.
     * The Vec3 represents the center of the sphere.
     * The double represents the radius of the sphere.
     * The color represents the color of the sphere.
     */
    Sphere(Vec3 center, double radius, Color c) : center(center),
                                                  radius(radius),
                                                  radius2(radius * radius),
                                                  color(c) {}


    /**
     *  Use equations from https://collaborating.tuhh.de/cpf5546/oop-sose22/-/blob/master/project/doc/objects.md#primitive-objects
     */
    bool intersect(Ray ray, double &t) const {
        Vec3 sc = center - ray.get_origin();
        double dp = dot_product(ray.get_direction(), sc); // dot product
        double delta = radius2 + pow(dp, 2) - pow(sc.get_length(), 2);
        if (delta < 0) return false;
        double t1, t2;
        t1 = dp + sqrt(delta);
        t2 = dp - sqrt(delta);
        t = t1 > t2 ? t2 : t1;
        return true;
    }


    /**
     * Returns the center of the sphere
     */
    const Vec3 getCenter() const {
        return center;
    }

    /**
     * Returns the radius of the sphere
     */
    double getRadius() const {
        return radius;
    }

    /**
     * Returns the color of the sphere
     */
    const Color &getColor() const {
        return color;
    }

};

