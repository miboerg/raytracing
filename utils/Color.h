#include <string>
#include <stdio.h>

class Color {
public:
    int r;
    int g;
    int b;


    Color() = default;

    Color(int red, int green, int blue) : r(red), g(green), b(blue) {

    };

    Color(const char *hex) {
        std::sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    }



    Color(double c) : r(c), g(c), b(c) {};

    Color operator*(double d) {
        return Color(r * d, g * d, b * d);
    }

    Color operator+(Color other) const {
        return Color(r + other.r, g + other.g, b + other.b);
    }

    Color operator-(Color other) const {
        return Color(r - other.r, g - other.g, b - other.b);
    }

    static Color red() { return Color(255, 0, 0); }

    static Color green() { return Color(0, 255, 0); }

    static Color blue() { return Color(0, 0, 255); }

    static Color white() { return Color(255, 255, 255); }

    static Color black() { return Color(0, 0, 0); }
};