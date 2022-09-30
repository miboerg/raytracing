#include <cmath>
#include "../include/Vec3.h"

/**
 * Returns the coordinates of the vector
 */

double Vec3::get_x() const { return x; }

double Vec3::get_y() const { return y; }

double Vec3::get_z() const { return z; }


/**
 * @return the length of the vector
 */
double Vec3::get_length() const {
    return sqrt(x * x + y * y + z * z);
};

/**
 * Takes a second vector as input.
 * @return distance between both vectors
 */
double Vec3::get_distance(Vec3 &other) const {
    return sqrt(pow(x - other.get_x(), 2) + pow(y - other.get_y(), 2) + pow(z - other.get_z(), 2));
}

/**
 * @return dot product of the vector
 */
double Vec3::dot_product() const {
    return x * x + y * y + z * z;
};


/**
 * @return dot product of both input vectors
 */

double dot_product(Vec3 const &u, Vec3 const &v) {
    return u.get_x() * v.get_x() + u.get_y() * v.get_y() + u.get_z() * v.get_z();
}


/**
 * @return normalized vector
 */
Vec3 Vec3::normalize() {
    double length = get_length();
    x = x / length;
    y = y / length;
    z = z / length;
    return *this;
};

const Vec3 Vec3::operator+(Vec3 const &v) const {
    return Vec3(x + v.get_x(), y + v.get_y(), z + v.get_z());
}

const Vec3 Vec3::operator-(Vec3 const &v) const {
    return Vec3(x - v.get_x(), y - v.get_y(), z - v.get_z());
}

const Vec3 Vec3::operator*(Vec3 const &v) const {
    return Vec3(x * v.get_x(), y * v.get_y(), z * v.get_z());
}

const Vec3 Vec3::operator*(double n) const {
    return Vec3(x * n, y * n, z * n);
}

const Vec3 Vec3::operator/(Vec3 const &v) const {
    return Vec3(x / v.get_x(), y / v.get_y(), z / v.get_z());
}

const Vec3 Vec3::operator/(double n) const {
    return Vec3(x / n, y / n, z / n);
}


