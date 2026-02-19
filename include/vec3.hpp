#ifndef VEC3_HPP
#define VEC3_HPP

#include <cstddef>

namespace vectorix{

class Vec3{
public:
    double x;
    double y;
    double z;

    // Constructors
    Vec3();
    Vec3(double xVal, double yVal, double zVal);

    // Basic Operations
    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    Vec3 operator*(double scalar) const;
    Vec3 operator/(double scalar) const;

    // Dot product
    double dot(const Vec3& other) const;

    // Length
    double length() const;

    // Normalize
    Vec3 normalized() const;

    // Indeex access
    double& operator[](std::size_t index);
    const double& operator[](std::size_t index) const;
};

}

#endif