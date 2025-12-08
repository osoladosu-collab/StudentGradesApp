CXX = g++
CXXFLAGS = -std=gnu++17 -O2

SRC = src/main.cpp src/Student.cpp src/FileReader.cpp src/FileWriter.cpp src/FileGenerator.cpp src/Timer.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = studentGrades_v02

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
