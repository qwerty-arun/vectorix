#include <iostream>
#include "mat3.hpp"
#include "vec3.hpp"
#include "vec2.hpp"

#define PI 3.14159265

using namespace vectorix;

int main(){
    std::cout << "\n=====START OF MAT3 TEST=====" << std::endl;
    Mat3 A(1, 2, 3, 4, 5, 6, 7, 8, 8);
    std::cout << "\nMatrix A: " << std::endl;
    A.display();

    Mat3 B = Mat3(-1, 0, 2, -4, -3, 7, 8, 5, 6);
    std::cout << "\nMatrix B: " << std::endl;
    B.display();

    Mat3 C = A * B;
    std::cout << "\nProduct of Matrix A and Matrix B: " << std::endl;
    C.display();

    std::cout << "\nDeterminant of Matrix A: " << A.determinant() << "\n";
    std::cout << "\nDeterminant of Matrix B: " << B.determinant() << "\n";

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

    Vec2 p(2, 3);
    std::cout << "\nVector p: " << p.x << " " << p.y << std::endl;
    std::cout << "\nMatrix T: " << std::endl;
    Mat3 T = Mat3::translation(5, -2);
    T.display();
    Vec2 res = T * p;
    std::cout << "\nTranslated Vector result = T * p: " << res.x << " " << res.y << std::endl;

    Vec2 q(3, -4);
    std::cout << "\nVector q: " << q.x << " " << q.y << std::endl;
    Mat3 S = Mat3::scale(2, 0.5);
    std::cout << "\nMatrix S: " << std::endl;
    S.display();
    res = S * q;
    std::cout << "\nScaled Vector result = S * q: " << res.x << " " << res.y << std::endl;

    double theta = PI / 2;
    Vec2 r(1, 0);
    std::cout << "\nVector r: " << r.x << " " << r.y << std::endl;
    Mat3 R = Mat3::rotation(theta);
    std::cout << "\nMatrix R: " << std::endl;
    R.display();
    res = R * r;
    std::cout << "\nRotated Vector (pi/2) result = R * r: " << res.x << " " << res.y << std::endl;

    R = Mat3::rotation(PI);
    std::cout << "\nMatrix R: " << std::endl;
    R.display();
    res = R * r;
    std::cout << "\nRotated Vector (pi) result = R * r: " << res.x << " " << res.y << std::endl;

    Vec2 s(3, 4);
    std::cout << "\nVector s: " << s.x << " " << s.y << std::endl;
    Mat3 Sh = Mat3::shear(1, 0); // x shear
    std::cout << "\nMatrix Sh: " << std::endl;
    Sh.display();
    res = Sh * s;
    std::cout << "\nSheared Vector result = Sh * s: " << res.x << " " << res.y << std::endl;

    Vec2 t(4, -7);
    std::cout << "\nVector t: " << t.x << " " << t.y << std::endl;
    Mat3 Rx = Mat3::reflectX();
    std::cout << "\nMatrix Rx: " << std::endl;
    Rx.display();
    res = Rx * t;
    std::cout << "\nSheared Vector result = Rx * t: " << res.x << " " << res.y << std::endl;
    
    Vec2 u(4, -7);
    std::cout << "\nVector u: " << u.x << " " << u.y << std::endl;
    Mat3 Ry = Mat3::reflectY();
    std::cout << "\nMatrix Ry: " << std::endl;
    Ry.display();
    res = Ry * u;
    std::cout << "\nSheared Vector result = Ry * u: " << res.x << " " << res.y << std::endl;

    std::cout << "\nComposition Testing:" << std::endl;
    std::cout << "\nPoint: (1,0):" << std::endl;
    std::cout << "\nScale (2,2) -> Rotate (pi/2) -> Translate (5, 0)" << std::endl;
    Vec2 v1(1, 0);
    Mat3 s1 = Mat3::scale(2, 2);
    Mat3 r1 = Mat3::rotation(PI/2);
    Mat3 t1 = Mat3::translation(5, 0);
    Mat3 transform = t1 * r1 * s1;
    Vec3 tmp = transform * Vec3{v1.x, v1.y, 1.0f};
    Vec2 final_result = {tmp.x, tmp.y};
    std::cout << "\nFinal Vector Result after transformation: " << final_result.x << " " << final_result.y << std::endl;

    std::cout << "\nRotate Around Arbitrary Point:" << std::endl;
    std::cout << "\nPoint: (3,2)" << std::endl;
    std::cout << "\nScale (-2,-2) -> Rotate (pi/2) -> Translate (2, 2)" << std::endl;
    Vec2 v2(3, 2);
    Mat3 t2 = Mat3::translation(-2, -2);
    Mat3 r2 = Mat3::rotation(PI/2);
    Mat3 t3 = Mat3::translation(2, 2);
    Mat3 transformed = t3 * r2 * t2;
    Vec2 rotate_result = transformed * v2;
    std::cout << "\nFinal Vector Result after rotation: " << rotate_result.x << " " << rotate_result.y << std::endl;

    std::cout << "\n=====END OF MAT3 TEST=====\n" << std::endl;
    return 0; 
}