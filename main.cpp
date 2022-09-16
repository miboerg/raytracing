#include <iostream>
#include <fstream>
#include "objects/Sphere.h"
#include <algorithm>

#define WIDTH 1600
#define HEIGHT 900

using std::cout;


int main() {
    std::ofstream out("out.ppm");

    out << "P3\n" << WIDTH << ' ' << HEIGHT << ' ' << "255\n";
    Sphere sphere1(Vec3(800, 450, 300), 200, Color::white());
    Sphere light(Vec3(800, 450, 0), -200);

    double t;
    Color color = Color::black();
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Ray ray = Ray(Vec3(x, y, 0), Vec3(0, 0, 1));
            color = Color::black();
            if (sphere1.intersect(ray, t)) {
                Vec3 int_point = ray.get_pos(t);
                Vec3 distance = light.getCenter() - int_point;
                Vec3 normal = (int_point - sphere1.getCenter()) / sphere1.getRadius();
                double dt = dot_product(distance.normalize(), normal.normalize());
                color = (Color::red() + Color::white() * dt) * 0.5;
            }
            out << (int) color.r << ' '
                << (int) color.g << ' '
                << (int) color.b << '\n';
        }
    }
    return 0;
}