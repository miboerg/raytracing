#include "../ray.hpp"
#include "../utils/include/Color.h"
#include <cmath>

class Sphere {

private:
    Vec3 center;
    double radius, radius2, transparacy, reflection;
    Color color;


public:
    Sphere(Vec3 center, double radius, Color color, double reflection, double transparacy) : center(center),
                                                                                             radius(radius),
                                                                                             radius2(radius * radius),
                                                                                             color(color),
                                                                                             transparacy(transparacy),
                                                                                             reflection(reflection) {};

    Sphere(Vec3 center, double radius) : center(center),
                                         radius(radius),
                                         radius2(radius * radius),
                                         color(Color::red()),
                                         transparacy(0),
                                         reflection(1) {};

    Sphere(Vec3 center, double radius, Color c) : center(center),
                                                  radius(radius),
                                                  radius2(radius * radius),
                                                  color(c),
                                                  transparacy(0),
                                                  reflection(1) {}


    //Use equations from https://collaborating.tuhh.de/cpf5546/oop-sose22/-/blob/master/project/doc/objects.md#primitive-objects
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

    Vec3 canonical_form(Vec3 x) const {
        return (x - getCenter()) / radius;
    }

    const Vec3 getCenter() const {
        return center;
    }

    double getRadius() const {
        return radius;
    }

    double getRadius2() const {
        return radius2;
    }

    double getTransparacy() const {
        return transparacy;
    }

    double getReflection() const {
        return reflection;
    }

    const Color &getColor() const {
        return color;
    }

};
