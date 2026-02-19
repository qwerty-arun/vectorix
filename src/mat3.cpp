#include "mat3.hpp"
#include "vec3.hpp"
#include <stdexcept>
#include <iostream>

namespace vectorix {

Mat3::Mat3(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            mat[i][j] = 0;
        }
    }
}

Mat3::Mat3(double a00, double a01, double a02,
         double a10, double a11, double a12,
         double a20, double a21, double a22){
    mat[0][0] = a00;
    mat[0][1] = a01;
    mat[0][2] = a02;
    mat[1][0] = a10;
    mat[1][1] = a11;
    mat[1][2] = a12;
    mat[2][0] = a20;
    mat[2][1] = a21;
    mat[2][2] = a22;
}

// Display
void Mat3::display() const {
    std::cout << mat[0][0] << " " << mat[0][1] << " " << mat[0][2] << std::endl;
    std::cout << mat[1][0] << " " << mat[1][1] << " " << mat[1][2] << std::endl;
    std::cout << mat[2][0] << " " << mat[2][1] << " " << mat[2][2] << std::endl;
}

// Identity
Mat3 Mat3::identity(){
    return Mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

// Addition
Mat3 Mat3::operator+(const Mat3& other) const {
    Mat3 result;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result.mat[i][j] = mat[i][j] + other.mat[i][j];
        }
    }
    return result;
}

// Subtraction
Mat3 Mat3::operator-(const Mat3& other) const {
    Mat3 result;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result.mat[i][j] = mat[i][j] - other.mat[i][j];
        }
    }
    return result;
}

// Multiplication
Mat3 Mat3::operator*(const Mat3& other) const {
    Mat3 result;
        for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result.mat[i][j] += mat[i][k] * other.mat[k][j];
            }
        }
    }
    return result;
}

// Vector Multiplication
Vec3 Mat3::operator*(const Vec3& v) const {
    return Vec3(
        mat[0][0] * v.x + mat[0][1] * v.y + mat[0][2] * v.z,
        mat[1][0] * v.x + mat[1][1] * v.y + mat[1][2] * v.z,
        mat[2][0] * v.x + mat[2][1] * v.y + mat[2][2] * v.z
    );
} 

// Scalar Multiplication
Mat3 Mat3::operator*(double scalar) const {
    return Mat3(
        mat[0][0] * scalar, mat[0][1] * scalar, mat[0][2] * scalar,
        mat[1][0] * scalar, mat[1][1] * scalar, mat[1][2] * scalar,
        mat[2][0] * scalar, mat[2][1] * scalar, mat[2][2] * scalar
    );
}

Mat3 Mat3::operator/(double scalar) const {
    return Mat3(
        mat[0][0] / scalar, mat[0][1] / scalar, mat[0][2] / scalar,
        mat[1][0] / scalar, mat[1][1] / scalar, mat[1][2] / scalar,
        mat[2][0] / scalar, mat[2][1] / scalar, mat[2][2] / scalar
    );
}

// Determinant
double Mat3::determinant() const {
    // Calculating the 2x2 determinants for the cofactor expansion
    double det2x2_1 = (mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]);
    double det2x2_2 = (mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]);
    double det2x2_3 = (mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]);

    // Applying the main 3x3 determinant formula
    return mat[0][0] * det2x2_1 - mat[0][1] * det2x2_2 + mat[0][2] * det2x2_3;
}

// Transpose
Mat3 Mat3::transpose() const {
    Mat3 trans;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            trans.mat[j][i] = mat[i][j];
        }
    }
    return trans;
}

// Inverse
Mat3 Mat3::inverse() const {
    double det = determinant();

    if(det == 0){
        throw std::runtime_error("Matrix not invertible!");
    }

    Mat3 adj;
    adj[0][0] = mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1];
    adj[0][1] = -(mat[0][1]*mat[2][2] - mat[0][2]*mat[2][1]);
    adj[0][2] = mat[0][1]*mat[1][2] - mat[0][2]*mat[1][1];

    adj[1][0] = -(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0]);
    adj[1][1] = mat[0][0]*mat[2][2] - mat[0][2]*mat[2][0];
    adj[1][2] = -(mat[0][0]*mat[1][2] - mat[0][2]*mat[1][0]);

    adj[2][0] = mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0];
    adj[2][1] = -(mat[0][0]*mat[2][1] - mat[0][1]*mat[2][0]);
    adj[2][2] = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    return adj/det;
}

// Index operator
double* Mat3::operator[](std::size_t row){
    return mat[row];
}

const double* Mat3::operator[](std::size_t row) const {
    return mat[row];
}

}