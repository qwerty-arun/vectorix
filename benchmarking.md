# 🧪 What Is Benchmarking?

**Benchmarking** is the process of **measuring the performance** of your code.

Not “does it work?”

But:

* How fast does it run?
* How much memory does it use?
* How does it compare to another implementation?

---

# 🧠 In Simple Terms

Testing checks correctness:

> ✅ “Does Vec2::length() return 5 for (3,4)?”

Benchmarking checks performance:

> ⚡ “How fast can we compute length() 10 million times?”

---

# 🧮 Example (Your Vec2)

Suppose you want to test how fast normalization is.

You could write:

```cpp
#include <iostream>
#include <chrono>
#include "vec2.hpp"

using namespace vec2lib;

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
```

That is a **benchmark**.

---

# 📊 Why Benchmarking Matters

For math libraries especially:

* Linear algebra must be fast
* Game engines require real-time math
* Robotics systems need predictable timing
* Physics simulations run millions of operations

Performance matters.

---

# 🔬 What You Can Benchmark

For your Vec2:

* Dot product speed
* Normalization speed
* Operator overload speed
* `-O0` vs `-O3` comparison
* Double vs float performance
* With and without `inline`

---

# ⚡ Example: Debug vs Release

Run:

```bash
make DEBUG=1
make run
```

Then:

```bash
make
make run
```

You’ll likely see:

* Debug build → slower
* Release build → much faster

That’s benchmarking in action.

---

# 🧠 Important Concept: Microbenchmark vs Real Benchmark

| Type             | Meaning                            |
| ---------------- | ---------------------------------- |
| Microbenchmark   | Measure tiny function (like dot()) |
| System Benchmark | Measure full system performance    |

You are doing **microbenchmarking** for now.

---

# 🚨 Common Beginner Mistake

Compiler optimization may remove your code entirely.

Example:

```cpp
v.normalized();
```

If result is unused, compiler might delete it.

Fix:

```cpp
volatile Vec2 result;
result = v.normalized();
```

or accumulate result.

---

# 🏎 Why This Is Important For You

Since you're interested in:

* Systems programming
* Robotics
* Performance-oriented code

Benchmarking is a **core engineering skill**.

Serious engineers don’t guess performance.

They measure it.

---

# 🔧 Professional Tools (Later Stage)

When you go deeper:

* `std::chrono`
* `perf` (Linux)
* `valgrind --tool=callgrind`
* Google Benchmark library
* VTune (Intel)

But start simple.

---

# 🎯 In One Sentence

Benchmarking is:

> Measuring how fast (or efficient) your code runs under controlled conditions.

---

Good — now we move from “code runs” → “code is measurable”.

To support **benchmarking**, we need to:

1. Add a `benchmarks/` folder
2. Compile benchmark files separately
3. Add a `benchmark` target
4. (Optional) Add special optimization flags

I’ll show you the clean upgrade to your current Makefile.

---

# 📁 First: Add This Folder

Create:

```
benchmarks/
└── bench_vec2.cpp
```

Example benchmark file:

```cpp
#include <iostream>
#include <chrono>
#include "vec2.hpp"

using namespace vec2lib;

int main() {
    Vec2 v(3.0, 4.0);
    const int iterations = 50'000'000;

    auto start = std::chrono::high_resolution_clock::now();

    double sum = 0.0;
    for (int i = 0; i < iterations; ++i) {
        sum += v.length();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time: " << elapsed.count() << " seconds\n";
    std::cout << "Dummy sum: " << sum << "\n";

    return 0;
}
```

The `sum` prevents optimization removal.

---

# 🔧 Now Modify Your Makefile

Below are **only the additions and changes**.

---

## 1️⃣ Add Benchmark Variables

Add near the top:

```make
BENCH_DIR := benchmarks
BENCH_SRCS := $(wildcard $(BENCH_DIR)/*.cpp)
BENCH_BINS := $(BENCH_SRCS:$(BENCH_DIR)/%.cpp=$(BIN_DIR)/%)
```

This auto-detects all benchmark files.

---

## 2️⃣ Add Rule to Build Benchmark Executables

Add this rule:

```make
$(BIN_DIR)/%: $(BENCH_DIR)/%.cpp $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
```

This is similar to your test rule.

---

## 3️⃣ Add Benchmark Target

Add:

```make
.PHONY: benchmark
benchmark: $(BENCH_BINS)
	@echo "Running benchmarks..."
	@for b in $(BENCH_BINS); do $$b; done
```

---

# ⚡ Optional (Recommended for Benchmarking)

Benchmarking should always use maximum optimization.

Add this special target:

```make
.PHONY: bench-opt
bench-opt:
	$(MAKE) CXXFLAGS="-std=c++20 -Wall -Wextra -Iinclude -O3 -march=native" benchmark
```

Now you can run:

```bash
make bench-opt
```

---

# 🧠 Why These Changes Matter

You now have:

* Automatic benchmark discovery
* Separate benchmark binaries
* Clean separation from tests
* Optimization control
* Scalable structure

---

# 🏁 How To Use

### Normal build

```bash
make
```

### Run tests

```bash
make run
```

### Run benchmarks

```bash
make benchmark
```

### Optimized benchmarking

```bash
make bench-opt
```

---

# 🧠 What You Just Learned

You expanded your build system to:

* Handle multiple executable categories
* Automatically detect files
* Control compiler flags per target
* Separate correctness testing from performance testing

That’s real build-system maturity.

---