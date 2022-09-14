#include <iostream>
#include <fstream>
#include "Sphere.hpp"
#include <algorithm>

#define WIDTH 2000
#define HEIGHT 2000

using std::cout;


int main() {
    std::ofstream out("out.ppm");

    out << "P3\n" << WIDTH << ' ' << HEIGHT << ' ' << "255\n";
    Sphere sphere1(Vec3(1500, 1500, 1500), 400, Color::white());
    Sphere sphere2(Vec3(500, 500, 500), 500, Color::white());
    Sphere sphere3(Vec3(1500, 1500, 1000), 300, Color::white());
    Sphere light(Vec3(1100, 1100, 1100), 100);

    double t;
    Color color = Color::black();
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Ray ray = Ray(Vec3(x, y, 0), Vec3(0, 0, 1));
            color = Color::black();
            if (sphere1.intersect(ray, t)) {
                Vec3 int_point = ray.getOrigin() + ray.getDirection() * t;
                Vec3 distance = light.getCenter() - int_point;
                Vec3 normal = (int_point-sphere1.getCenter()) / sphere1.getRadius();
                double dt = distance.normalize().dot_product(normal.normalize());
                color = (Color::red() + Color::white() * dt) * 0.5;
            }else if (sphere2.intersect(ray, t)) {
                Vec3 int_point = ray.getOrigin() + ray.getDirection() * t;
                Vec3 distance = light.getCenter() - int_point;
                Vec3 normal = (int_point-sphere2.getCenter()) / sphere2.getRadius();
                double dt = distance.normalize().dot_product(normal.normalize());
                color = (Color::green() + Color::white() * dt) * 0.5;
            }
            out << (int) color.r << ' '
                << (int) color.g << ' '
                << (int) color.b << '\n';
        }
    }

    return 0;
}