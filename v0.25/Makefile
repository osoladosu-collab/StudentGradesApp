TARGET = studentGrades_v025
SRC = src/main.cpp
OBJ = obj/main.o
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Iinclude

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

obj/main.o: src/main.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

clean:
	rm -rf obj $(TARGET)
