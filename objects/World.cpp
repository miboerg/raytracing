#include <vector>
#include "Sphere.h"
#include "LightSource.h"
#include <string>

#include "../lib/CImg.h"


using std::vector;
using namespace cimg_library;

class World {

private:
    vector<Sphere> spheres;
    vector<LightSource> light_sources;
    double width, height;
    Color background;
    Vec3 shift;

public:
    World(int width, int height, Vec3 shift, Color background) : width(width), height(height), shift(shift),
                                                                 background(background) {};

    void render_image(std::string path) {
        CImg<unsigned char> image(width, height, 1, 3, 0);
        for (int y = 0; y < get_height(); ++y) {
            for (int x = 0; x < get_width(); ++x) {
                Ray ray = Ray(Vec3(x + shift.get_x(), y + shift.get_y(), 0), shift);
                Vec3 int_point;
                Color color = get_background();
                double t = INFINITY;
                Sphere int_sphere;
                bool intersect = false;


                for (Sphere sphere: get_spheres()) { //iterates through every sphere and finds the closest one
                    double current_t;
                    if (sphere.intersect(ray, current_t)) {
                        if (current_t < t) {
                            int_sphere = sphere;
                            t = current_t;
                            intersect = true;
                        }
                    }
                }

                if (intersect) {
                    int_point = ray.get_pos(t);
                    Vec3 normal = (int_point - int_sphere.getCenter()) / int_sphere.getRadius();
                    Vec3 distance_point = get_light_source().get_center() - int_point;
                    double dt = dot_product((distance_point).normalize(), normal.normalize());
                    color = (int_sphere.getColor() + Color::white() * dt) * get_light_source().get_intensity() * 0.5;
                }

                unsigned char c[3];
                if (color.r < 0) color.r = 0;
                if (color.g < 0) color.g = 0;
                if (color.b < 0) color.b = 0;
                c[0] = color.r;
                c[1] = color.g;
                c[2] = color.b;
                image.draw_point(x, y, c);
            }
        }

        std::string filename = path == "" ? "output.bmp" : path + "\\output.bmp";
        std::string title = path == "" ? "Your image" : "Saved to " + path;
        image.save(filename.c_str(), 60);
        CImgDisplay display(image, title.c_str());
        while (!display.is_closed()) display.wait();


    }

    void add_sphere(Sphere s) {
        spheres.push_back(s);
    }

    void add_light_source(LightSource ls) {
        light_sources.push_back(ls);
    }

    vector<Sphere> &get_spheres() {
        return spheres;
    }

    LightSource &get_light_source() {
        return light_sources[0];
    }

    double get_width() {
        return width;
    }

    double get_height() {
        return height;
    }

    const Color &get_background() {
        return background;
    }


};
