CXX       := g++
CXXFLAGS  := -std=c++20 -Wall -Wextra -Iinclude
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin

ifeq ($(DEBUG),1)
	CXXFLAGS += -g -O0
else
	CXXFLAGS += -O3
endif

SRC  := src/vec2.cpp
OBJ  := $(OBJ_DIR)/vec2.o
TEST := tests/test_vec2.cpp
BIN  := $(BIN_DIR)/test_vec2

# Default target
all: $(BIN)

# Compile object file
$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Build test executable
$(BIN): $(OBJ) $(TEST)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run test
.PHONY: run
run: $(BIN)
	./$(BIN)

# Clean
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Include dependency files
-include $(OBJ:.o=.d)