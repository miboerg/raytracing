#include <vector>
#include "objects/Sphere.h"
#include "objects/LightSource.h"

using std::vector;

class World {

private:
    vector<Sphere> spheres;
    vector<LightSource> light_sources;
    double width, height;
    Color background;

public:
    World(int width, int height, Color background) : width(width), height(height), background(background) {};

    void add_sphere(Sphere s) {
        spheres.push_back(s);
    }
    void add_light_source(LightSource ls) {
        light_sources.push_back(ls);
    }


    Color trace() {

    }


};
