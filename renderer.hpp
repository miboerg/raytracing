#include <vector>
#include "Sphere.hpp"

using std::vector;

float mix(const float &a, const float &b, const float &mix)
{
    return b * mix + a * (1 - mix);
}

Color calculate_ray(Ray ray, vector<Sphere> spheres, int depth) {

    double t;
    for (size_t i = 0; i < spheres.size(); i++) {
        if (!spheres[i].intersect(ray, t)) return Color::black();

        Vec3 int_point = ray.getOrigin() + ray.getDirection() * t;
        Vec3 canon_vector = int_point - spheres[i].getCenter();
        canon_vector.normalize();

        //-----------------------




    }

}