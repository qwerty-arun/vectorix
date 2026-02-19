#include <iostream>
#include "mat3.hpp"
#include "vec3.hpp"

using namespace vectorix;

int main(){
    std::cout << "\n=====START OF MAT3 TEST=====" << std::endl;
    Mat3 A(1, 2, 3, 4, 5, 6, 7, 8, 9);
    std::cout << "\nMatrix A: " << std::endl;
    A.display();

    Mat3 B = Mat3::identity();
    std::cout << "\nMatrix B: " << std::endl;
    B.display();

    Mat3 C = A * B;
    std::cout << "\nProduct of Matrix A and Matrix B: " << std::endl;
    C.display();

    std::cout << "\nDeterminant: " << A.determinant() << "\n";

    Vec3 v(1, 1, 1);
    Vec3 result = A * v;

    std::cout << "\nVector v: " << v.x << " " << v.y << " " << v.z << std::endl;

    std::cout << "\nA * v = (" << result.x
              << ", " << result.y << ", " << result.z << ")\n";

    Mat3 transposeA = A.transpose();
    std::cout << "\nTranspose of Matrix A: " << std::endl;
    transposeA.display();

    Mat3 inverseA = A.inverse();
    std::cout << "\nInverse of Matrix A: " << std::endl;
    inverseA.display();

    std::cout << "\n=====END OF MAT3 TEST=====\n" << std::endl;
    return 0; 
}