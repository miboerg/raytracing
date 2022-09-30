#include "objects/World.cpp"
#include <fstream>
#include <string>
#include "lib/json.hpp"

using json = nlohmann::json;

int main() {

    /*
     * Reads all the data from the settings.json file and adds it to the world object
     */
    std::ifstream f("../settings.json");
    json data = json::parse(f);
    int width = data["width"];
    int height = data["height"];
    int camera_pos_x = data["camera_pos_x"];
    int camera_pos_y = data["camera_pos_y"];
    std::string hex = data["background_color"];
    std::string folder = data["image_folder"];

    World world = World(width, height, Vec3(camera_pos_x, camera_pos_y,0), Color(hex.c_str()));
    for (auto &elm: data["light_sources"]) {
        int pos_x = elm["pos_x"];
        int pos_y = elm["pos_y"];
        int pos_z = elm["pos_z"];
        double intensity = elm["intensity"];
        world.add_light_source(LightSource(Vec3(pos_x, pos_y, pos_z), intensity));
    }
    for (auto &elm: data["spheres"]) {
        int pos_x = elm["pos_x"];
        int pos_y = elm["pos_y"];
        int pos_z = elm["pos_z"];
        int radius = elm["radius"];
        std::string hex = elm["color"];
        world.add_sphere(Sphere(Vec3(pos_x, pos_y, pos_z), radius, hex.c_str()));
    }


    world.render_image(folder); // renders the image with the data
    return 0;
}