#include <iostream>
#include "mat2.hpp"
#include "vec2.hpp"

using namespace vectorix;

int main(){
    std::cout << "\n=====START OF MAT2 TEST=====" << std::endl;
    Mat2 A(1, 2,
           3, 4);
    std::cout << "\nMatrix A: " << std::endl;
    A.display();

    Mat2 B = Mat2::identity();
    std::cout << "\nMatrix B: " << std::endl;
    B.display();

    Mat2 C = A * B;
    std::cout << "\nProduct of Matrix A and Matrix B: " << std::endl;
    C.display();

    std::cout << "\nDeterminant: " << A.determinant() << "\n";

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

    std::cout << "\n=====END OF MAT2 TEST=====\n" << std::endl;
    return 0; 
}