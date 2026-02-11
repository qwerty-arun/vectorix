#ifndef VEC2_HPP
#define VEC2_HPP

#include <cstddef>

namespace vectorix{
    
class Vec2{
public:
    double x;
    double y;

    // Constructors
    Vec2();
    Vec2(double xVal, double yVal);

    // Basic operations
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(double scalar)const;
    Vec2 operator/(double scalar)const;

    // Dot product
    double dot(const Vec2& other) const;

    // Length
    double length() const;

    // Normalize
    Vec2 normalized() const;

    // Index access
    double& operator[](std::size_t index);
    const double& operator[](std::size_t index) const;
};

}
#endif