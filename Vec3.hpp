#include <cmath>
#include <iostream>

using std::ostream;

class Vec3 {

private:
    double x, y, z;

public:
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    double get_x() const { return x; }

    double get_y() const { return y; }

    double get_z() const { return z; }

    double get_length() {
        return sqrt(x * x + y * y + z * z);
    }

    double get_distance(Vec3 const &other) {
        return sqrt(pow(x - other.get_x(), 2) + pow(y - other.get_y(), 2) + pow(z - other.get_z(), 2));
    }

    double dot_product(Vec3 const &other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    double dot_product() {
        return dot_product(*this);
    }

    Vec3 &normalize() {
        double length = get_length();
        x = x / length;
        y = y / length;
        z = z / length;
        return *this;
    }

    Vec3 operator+(Vec3 const &other) const {
        return Vec3(x + other.get_x(), y + other.get_y(), z + other.get_z());
    }

    Vec3 operator-(Vec3 const &other) const {
        return Vec3(x - other.get_x(), y - other.get_y(), z - other.get_z());
    }

    Vec3 operator*(Vec3 const &other) const {
        return Vec3(x * other.get_x(), y * other.get_y(), z * other.get_z());
    }

    Vec3 operator*(double const &n) const {
        return Vec3(x * n, y * n, z * n);
    }

    Vec3 operator/(double d) const {
        return Vec3(x / d, y / d, z / d);
    }

    Vec3 operator+=(Vec3 const &other) {
        x += other.get_x();
        y += other.get_y();
        z += other.get_z();
        return *this;
    }

    Vec3 operator-=(Vec3 const &other) {
        x -= other.get_x();
        y -= other.get_y();
        z -= other.get_z();
        return *this;
    }


};

//ostream &operator<<(ostream &out, Vec3 const &vec) {
//   out << "[" << vec.get_x() << "," << vec.get_y() << "," << vec.get_z() << "]";
//   return out;

//}