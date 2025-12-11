# =========================================
#   StudentGradesApp v0.25 - Makefile
# =========================================

CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Iinclude
TARGET   := studentGrades_v025

SRC_DIR  := src
OBJ_DIR  := obj

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

DEPS := $(OBJS:.o=.d)

# -----------------------------------------
# Default build rule
# -----------------------------------------
all: $(TARGET)
	@echo "Build complete."

# -----------------------------------------
# Link
# -----------------------------------------
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# -----------------------------------------
# Compile with automatic dependency files
# -----------------------------------------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# -----------------------------------------
# Ensure obj directory exists
# -----------------------------------------
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# -----------------------------------------
# Cleaning rules
# -----------------------------------------
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# -----------------------------------------
# Include dependency files
# -----------------------------------------
-include $(DEPS)

.PHONY: all clean
