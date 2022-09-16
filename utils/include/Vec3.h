#ifndef RAYTRACING_VEC3_H
#define RAYTRACING_VEC3_H


class Vec3 {
private:
    double x, y, z;

public:
    Vec3(double x, double y, double z) : x(x), y(y), z(z){};

    double get_x() const;

    double get_y() const;

    double get_z() const;

    virtual double get_length() const;

    virtual double get_distance(Vec3 &other) const;

    virtual double dot_product() const;

    virtual Vec3 normalize();

    const Vec3 operator-(Vec3 const &v) const;

    const Vec3 operator+(Vec3 const &v) const;

    const Vec3 operator/(Vec3 const &v) const;

    const Vec3 operator/(double n) const;

    const Vec3 operator*(Vec3 const &v) const;

    const Vec3 operator*(double n) const;

    void operator+=(Vec3 const &u) {
        x += u.x;
        y += u.y;
        z += u.z;
    }

    void operator-=(Vec3 const &u) {
        x -= u.x;
        y -= u.y;
        z -= u.z;
    }

};

double dot_product(Vec3 const &u, Vec3 const &v);

#endif //RAYTRACING_VEC3_H
