#ifndef MAT3_HPP
#define MAT3_HPP

#include <cstddef>

namespace vectorix {

class Mat3 {
public:
    double mat[3][3];

    // Constructors
    Mat3();

    Mat3(double a00, double a01, double a02,
         double a10, double a11, double a12,
         double a20, double a21, double a22);

    // Identity matrix
    static Mat3 identity();

    // Display matrix
    void display() const ;

    // Transformations

    // Translation
    static Mat3 translation(double tx, double ty);

    // Scaling matrix
    static Mat3 scale(double sx, double sy);

    // Rotation matrix (radians)
    static Mat3 rotation(double radians);

    // Shear matrix
    static Mat3 shear(double shx, double shy);

    // Reflection across X axis
    static Mat3 reflectX();

    // Reflection across Y axis
    static Mat3 reflectY();

    // Matrix operations
    Mat3 operator+(const Mat3& other) const;
    Mat3 operator-(const Mat3& other) const;
    Mat3 operator*(const Mat3& other) const;

    // Matrix-Vector Multiplication
    class Vec3 operator*(const class Vec3& v) const;
    class Vec2 operator*(const class Vec2& v) const;

    // Scalar Multiplication
    Mat3 operator*(double scalar) const;
    Mat3 operator/(double scalar) const;

    // Determinant
    double determinant() const;

    // Transpose
    Mat3 transpose() const;

    // Inverse
    Mat3 inverse() const;

    // Index access
    double* operator[](std::size_t row);
    const double* operator[](std::size_t row) const;
};

}
#endif