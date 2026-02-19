#include <iostream>
#include "vec3.hpp"

using namespace vectorix;

int main(){
    std::cout << "\n=====START OF VEC3 TEST=====\n" << std::endl;
    Vec3 a(3.0, 4.0, 5.0);
    Vec3 b(5.0, 3.0, 4.0);

    Vec3 c = a + b;
    Vec3 d = a - b;

    std::cout << "a + b = (" << c.x << ", " << c.y << ", " << c.z << ")\n";
    std::cout << "a - b = (" << d.x << ", " << d.y << ", " << d.z << ")\n";
    std::cout << "Dot = " << a.dot(b) << "\n";
    std::cout << "Length of a = " << a.length() << "\n";
    std::cout << "Length of b = " << b.length() << "\n";

    Vec3 n = a.normalized();
    std::cout << "Normalized a = (" << n.x << ", " << n.y << "," << n.z << ")\n";

    n = b.normalized();
    std::cout << "Normalized b = (" << n.x << ", " << n.y << "," << n.z << ")\n";

    std::cout << "\n=====END OF VEC3 TEST=====\n" << std::endl;
    return 0;
}