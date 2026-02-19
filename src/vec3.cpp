#include "vec3.hpp"
#include <cmath>
#include <stdexcept>

namespace vectorix{

// Constructors
Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}

Vec3::Vec3(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

// Operators
Vec3 Vec3::operator+(const Vec3& other) const{
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const{
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(double scalar) const{
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(double scalar) const{
    if(scalar == 0.0)
        throw std::runtime_error("Division by zero!");
    return Vec3(x / scalar, y / scalar, z / scalar);
}

// Dot product
double Vec3::dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Length
double Vec3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalize
Vec3 Vec3::normalized() const {
    double len = length();
    if(len == 0.0){
        throw std::runtime_error("Connot normalize zero vector!");
    }
    return (*this) / len;
}

// Index operator
double& Vec3::operator[](std::size_t index){
    if(index == 0) return x;
    if(index == 1) return y;
    if(index == 2) return z;
    throw std::out_of_range("Index out of range!");
}

const double& Vec3::operator[](std::size_t index) const {
    if(index == 0) return x;
    if(index == 1) return y;
    if(index == 2) return z;
    throw std::out_of_range("Index out of range!");
}

}