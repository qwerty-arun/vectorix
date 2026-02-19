# =========================
# Compiler Configuration
# =========================
CXX := g++

BASE_FLAGS := -std=c++20 -Wall -Wextra -Iinclude
CXXFLAGS := $(BASE_FLAGS)

# Debug vs Release
ifeq ($(DEBUG),1)
	CXXFLAGS += -g -O0
else
	CXXFLAGS += -O3
endif

# =========================
# Project Structure
# =========================
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin

SRC_DIR   := src
TEST_DIR  := tests
BENCH_DIR := benchmarks

# =========================
# Source Discovery
# =========================
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_BINS := $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BIN_DIR)/%)

BENCH_SRCS := $(wildcard $(BENCH_DIR)/*.cpp)
BENCH_BINS := $(BENCH_SRCS:$(BENCH_DIR)/%.cpp=$(BIN_DIR)/%)

# =========================
# Default Target
# =========================
.PHONY: all
all: $(TEST_BINS)

# =========================
# Object Compilation
# =========================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# =========================
# Test Executables
# =========================
$(BIN_DIR)/%: $(TEST_DIR)/%.cpp $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: run
run: $(TEST_BINS)
	@echo "Running tests..."
	@for t in $(TEST_BINS); do $$t; done

# =========================
# Benchmark Executables
# =========================
$(BIN_DIR)/%: $(BENCH_DIR)/%.cpp $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: benchmark
benchmark: $(BENCH_BINS)
	@echo "Running benchmarks..."
	@for b in $(BENCH_BINS); do $$b; done

# Optimized Benchmark
.PHONY: bench-opt
bench-opt:
	$(MAKE) CXXFLAGS="$(BASE_FLAGS) -O3 -march=native -ffast-math" benchmark

# Compare Debug vs Release Benchmarks
.PHONY: compare-debug-bench
compare-debug-bench:
	@echo "=== Debug Benchmark ==="
	rm -rf $(BUILD_DIR)
	$(MAKE) DEBUG=1 benchmark
	@echo ""
	@echo "=== Release Benchmark ==="
	rm -rf $(BUILD_DIR)
	$(MAKE) DEBUG=0 benchmark

# =========================
# Cleaning
# =========================
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# =========================
# Dependency Include
# =========================
-include $(DEPS)