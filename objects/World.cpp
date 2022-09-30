#include <vector>
#include "Sphere.h"
#include "LightSource.h"
#include <string>

// Uses the CImg library
#include "../lib/CImg.h"


using std::vector;
using namespace cimg_library;

/*
 * The World class contains the core of the project like the main calculations and the image generation.
 */
class World {

private:
    vector<Sphere> spheres; // list of the spheres
    vector<LightSource> light_sources; // list of the light sources
    double width, height; // image resolution
    Color background; // background color
    Vec3 shift; // camera position

public:
    World(int width, int height, Vec3 shift, Color background) : width(width), height(height), shift(shift),
                                                                 background(background) {};

    void render_image(std::string path) {
        CImg<unsigned char> image(width, height, 1, 3, 0); // creates a CImg with the according data

        //loop through every pixel
        for (int y = 0; y < get_height(); ++y) {
            for (int x = 0; x < get_width(); ++x) {
                // creates a ray from every pixel with the shift vector
                Ray ray = Ray(Vec3(x + shift.get_x(), y + shift.get_y(), 0), shift);
                Vec3 int_point; // intersection point
                Color color = get_background(); // sets the background color as default color
                double t = INFINITY; // the closest calculated distance
                Sphere int_sphere; // the closest sphere to the ray origin
                bool intersect = false; // boolean if the ray intersects with a sphere


                for (Sphere sphere: get_spheres()) { //iterates through every sphere
                    double current_t;
                    if (sphere.intersect(ray, current_t)) { // checks if the current sphere intersects with the ray
                        if (current_t < t) { // checks if the distance of the new sphere to the ray is smaller than the previous distance.
                            int_sphere = sphere;
                            t = current_t;
                            intersect = true;
                        }
                    }
                }

                if (intersect) { // if the ray intersects
                    int_point = ray.get_pos(t); // Vector coordinates of the intersection point
                    Vec3 normal = (int_point - int_sphere.getCenter()) / int_sphere.getRadius(); // normal of the distance between the intersection point and the ray
                    Vec3 distance_point = get_light_source().get_center() - int_point; // distance between light source and the intersection point
                    double dt = dot_product((distance_point).normalize(), normal.normalize()); // dot product of the normalized distance_point and normal
                    color = (int_sphere.getColor() + Color::white() * dt) * get_light_source().get_intensity() * 0.5; // calculates the pixel color with the light intensity
                }

                // converts rgb color to char array and draws the color at the according coordinates on the image
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
        image.save(filename.c_str()); // saves image as .bmp
        CImgDisplay display(image, title.c_str()); // displays the generated image in a window
        while (!display.is_closed()) display.wait();


    }

    /*
     * Takes a sphere as argument and adds it to the world
     */
    void add_sphere(Sphere s) {
        spheres.push_back(s);
    }

    /*
     * Takes a light source as argument and adds it to the world
     */
    void add_light_source(LightSource ls) {
        light_sources.push_back(ls);
    }

    /*
     * Returns the vector of all spheres
     */
    vector<Sphere> &get_spheres() {
        return spheres;
    }

    /*
     * Returns the first light source of all light sources
     */
    LightSource &get_light_source() {
        return light_sources[0];
    }

    /*
     * Returns the width
     */

    double get_width() {
        return width;
    }

    /*
     * Returns the height
     */

    double get_height() {
        return height;
    }

    /*
     * Returns the background color
     */
    const Color &get_background() {
        return background;
    }


};
