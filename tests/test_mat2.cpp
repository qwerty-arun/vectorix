#include <iostream>
#include "mat2.hpp"
#include "vec2.hpp"

#define PI 3.14159265259

using namespace vectorix;

int main(){
    std::cout << "\n=====START OF MAT2 TEST=====" << std::endl;
    Mat2 A(1, 2,
           3, 4);
    std::cout << "\nMatrix A: " << std::endl;
    A.display();

    Mat2 B(5, -1, 0, 7);
    std::cout << "\nMatrix B: " << std::endl;
    B.display();

    Mat2 C = A * B;
    std::cout << "\nProduct of Matrix A and Matrix B: " << std::endl;
    C.display();

    std::cout << "\nDeterminant of Matrix A: " << A.determinant() << "\n";
    std::cout << "\nDeterminant of Matrix B: " << B.determinant() << "\n";

    Vec2 v(1, 1);
    Vec2 result = A * v;

    std::cout << "\nVector v: " << v.x << " " << v.y << std::endl;

    std::cout << "\nA * v = (" << result.x
              << ", " << result.y << ")\n";

    Mat2 transposeA = A.transpose();
    std::cout << "\nTranspose of Matrix A: " << std::endl;
    transposeA.display();

    Mat2 inverseA = A.inverse();
    std::cout << "\nInverse of Matrix A: " << std::endl;
    inverseA.display();

    Vec2 vec(1, 0);
    std::cout << "\nVector vec: " << vec.x << " " << vec.y << std::endl;

    Mat2 R = Mat2::rotation(PI/2);
    std::cout << "\nRotation Matrix: " << std::endl;
    R.display();

    result = R * vec;
    std::cout << "\nVector result = R * vec: " << result.x << " " << result.y << std::endl;

    std::cout << "\n=====END OF MAT2 TEST=====\n" << std::endl;
    return 0; 
}