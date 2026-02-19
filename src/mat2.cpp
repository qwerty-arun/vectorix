#include "mat2.hpp"
#include "vec2.hpp"
#include <stdexcept>
#include <iostream>

namespace vectorix{

// Cosntructors
Mat2::Mat2(){
    mat[0][0] = 0;
    mat[0][1] = 0;
    mat[1][0] = 0;
    mat[1][1] = 0;
}

Mat2::Mat2(double a, double b, double c, double d) {
    mat[0][0] = a;
    mat[0][1] = b;
    mat[1][0] = c;
    mat[1][1] = d;
} 

// Display
void Mat2::display() const {
    std::cout << mat[0][0] << " " << mat[0][1] << std::endl;
    std::cout << mat[1][0] << " " << mat[1][1] << std::endl;
}

// Identity
Mat2 Mat2::identity(){
    return Mat2(1, 0, 0, 1);
}

// Addition
Mat2 Mat2::operator+(const Mat2& other) const {
    return Mat2(
        mat[0][0] + other.mat[0][0],
        mat[0][1] + other.mat[0][1],
        mat[1][0] + other.mat[1][0],
        mat[1][1] + other.mat[1][1]
    );
}

// Subtraction
Mat2 Mat2::operator-(const Mat2& other) const {
    return Mat2(
        mat[0][0] - other.mat[0][0],
        mat[0][1] - other.mat[0][1],
        mat[1][0] - other.mat[1][0],
        mat[1][1] - other.mat[1][1]
    );
}

// Multiplication
Mat2 Mat2::operator*(const Mat2& other) const {
    return Mat2(
        mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0],
        mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1],
        mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0],
        mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1]
    );
}

// Vector Multiplication
Vec2 Mat2::operator*(const Vec2& v) const {
    return Vec2(
        mat[0][0] * v.x + mat[0][1] * v.y,
        mat[1][0] * v.x + mat[1][1] * v.y
    );
} 

// Determinant
double Mat2::determinant() const {
    return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

// Transpose
Mat2 Mat2::transpose() const {
    return Mat2(
        mat[0][0],
        mat[1][0],
        mat[0][1],
        mat[1][1]
    );
}

// Inverse
Mat2 Mat2::inverse() const {
    double det = determinant();

    if(det == 0){
        throw std::runtime_error("Matrix not invertible!");
    }
    return Mat2(
        mat[1][1]/det,
        -mat[0][1]/det,
        -mat[1][0]/det,
        mat[0][0]/det
    );
}

// Index operator
double* Mat2::operator[](std::size_t row){
    return mat[row];
}

const double* Mat2::operator[](std::size_t row) const {
    return mat[row];
}

}