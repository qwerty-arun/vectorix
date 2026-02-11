#include <iostream>
#include <chrono>
#include "vec2.hpp"

using namespace vectorix;

int main() {
    Vec2 v(3.0, 4.0);

    const int iterations = 10'000'000;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        v.normalized();
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken: " << elapsed.count() << " seconds\n";
}