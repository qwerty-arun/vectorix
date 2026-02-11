# Vectorix 

- A lightweight 2D vector mathematics library written in modern C++20.

- This project is built to practice:
  - Clean C++ API design
  - Separation of header and implementation
  - Advanced Makefile usage
  - Debug vs Release builds
  - Dependency tracking

---

## Features

- 2D Vector class (`Vec2`)
- Operator overloading (+, -, *, /)
- Dot product
- Length calculation
- Normalization
- Bounds-checked indexing
- Exception-safe operations

---

## Build Instructions

### Release Build (Optimized) (Normal)

```bash
make
```

### Debug Build
```bash
make DEBUG=1
```

### Run Test
```bash
make run
```

### Run Benchmarks
```bash
make benchmark
```

### Run Optimized Benchmarks
```bash
make bench-opt
```

### Clean Build Files
```bash
make clean
```

---

## Example Usage
```c
#include "vec2.hpp"
#include <iostream>

using namespace vec2lib;

int main() {
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);

    Vec2 c = a + b;

    std::cout << "Result: ("
              << c.x << ", "
              << c.y << ")\n";

    std::cout << "Dot product: " << a.dot(b) << "\n";
    std::cout << "Length of a: " << a.length() << "\n";

    return 0;
}
```

## Build System Details
- The project uses GNU Make with:
  - Separate build directory (build/)
  - Automatic header dependency generation (-MMD -MP)
  - Debug and Release configuration
  - Object file isolation
  - Clean rebuild targets
- This structure scales well for larger math libraries.