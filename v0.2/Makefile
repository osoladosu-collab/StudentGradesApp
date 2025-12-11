CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Iinclude

SRC = src/main.cpp \
      src/Student.cpp \
      src/FileReader.cpp \
      src/FileWriter.cpp \
      src/FileGenerator.cpp \
      src/Timer.cpp

OBJ = $(SRC:.cpp=.o)
OUT = studentGrades_v02

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)
