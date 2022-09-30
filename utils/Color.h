#include <string>
#include <stdio.h>

/*
 * Class to represent a color in rgb format.
 */

class Color {
public:
    int r;
    int g;
    int b;


    Color() = default;

    // Constructor to initialize the rgb values
    Color(int red, int green, int blue) : r(red), g(green), b(blue) {};

    // Constructor with a hex color as input which will be formatted into the rgb format.
    Color(const char *hex) {
        std::sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    }


    /*
     * Constructor with only one double as input if each r,g,b value should be the same.
     * When the input is 10, the according rgb color will be rgb(10,10,10)
     */
    Color(double c) : r(c), g(c), b(c) {};


    /*
     * Operator overloading
     */
    Color operator*(double d) {
        return Color(r * d, g * d, b * d);
    }

    Color operator+(Color other) const {
        return Color(r + other.r, g + other.g, b + other.b);
    }

    Color operator-(Color other) const {
        return Color(r - other.r, g - other.g, b - other.b);
    }

    /*
     * Default initialized rgb colors.
     */
    static Color red() { return Color(255, 0, 0); }

    static Color green() { return Color(0, 255, 0); }

    static Color blue() { return Color(0, 0, 255); }

    static Color white() { return Color(255, 255, 255); }

    static Color black() { return Color(0, 0, 0); }
};