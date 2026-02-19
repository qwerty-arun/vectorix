#ifndef MAT2_HPP
#define MAT2_HPP

#include <cstddef>

namespace vectorix {

class Mat2 {
public:
    double mat[2][2];

    // Constructors
    Mat2();
    Mat2(double a, double b, double c, double d);

    // Identity matrix
    static Mat2 identity();

    // Display matrix
    void display() const ;

    // Matrix operations
    Mat2 operator+(const Mat2& other) const;
    Mat2 operator-(const Mat2& other) const;
    Mat2 operator*(const Mat2& other) const;
    class Vec2 operator*(const class Vec2& v) const;

    // Determinant
    double determinant() const;

    // Transpose
    Mat2 transpose() const;

    // Inverse
    Mat2 inverse() const;

    // Index access
    double* operator[](std::size_t row);
    const double* operator[](std::size_t row) const;
};

}
#endif