#include "vec2.hpp"
#include <cmath>
#include <stdexcept>

namespace vectorix {

// Constructors
Vec2::Vec2() : x(0.0), y(0.0) {}

Vec2::Vec2(double xVal, double yVal) : x(xVal), y(yVal) {}

// Operators
Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(double scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(double scalar) const {
    if (scalar == 0.0)
        throw std::runtime_error("Division by zero");
    return Vec2(x / scalar, y / scalar);
}

// Dot product
double Vec2::dot(const Vec2& other) const {
    return x * other.x + y * other.y;
}

// Length
double Vec2::length() const {
    return std::sqrt(x * x + y * y);
}

// Normalize
Vec2 Vec2::normalized() const {
    double len = length();
    if (len == 0.0)
        throw std::runtime_error("Cannot normalize zero vector");
    return (*this) / len;
}

// Index operator
double& Vec2::operator[](std::size_t index) {
    if (index == 0) return x;
    if (index == 1) return y;
    throw std::out_of_range("Index out of range");
}

const double& Vec2::operator[](std::size_t index) const {
    if (index == 0) return x;
    if (index == 1) return y;
    throw std::out_of_range("Index out of range");
}

}