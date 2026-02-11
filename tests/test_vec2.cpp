#include <iostream>
#include "vec2.hpp"

using namespace vectorix;

int main() {
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);

    Vec2 c = a + b;
    Vec2 d = a - b;

    std::cout << "a + b = (" << c.x << ", " << c.y << ")\n";
    std::cout << "a - b = (" << d.x << ", " << d.y << ")\n";
    std::cout << "Dot = " << a.dot(b) << "\n";
    std::cout << "Length of a = " << a.length() << "\n";

    Vec2 n = a.normalized();
    std::cout << "Normalized a = (" << n.x << ", " << n.y << ")\n";

    return 0;
}