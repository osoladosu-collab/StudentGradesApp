# ==========================
#     StudentGrades v0.2
# ==========================

CXX       := g++
CXXFLAGS  := -std=c++17 -O2 -Wall -Wextra -Iinclude
LDFLAGS   := 
TARGET    := studentGrades_v02

SRC_DIR   := src
INC_DIR   := include
OBJ_DIR   := obj

# All .cpp files inside src/
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Convert src/*.cpp → obj/*.o
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Dependency files
DEPS := $(OBJS:.o=.d)

# Default build
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile rule with dependency generation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Ensure obj directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean everything
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run (for quick manual tests)
run: all
	./$(TARGET)

# Include dependency files
-include $(DEPS)

.PHONY: all clean rebuild run
