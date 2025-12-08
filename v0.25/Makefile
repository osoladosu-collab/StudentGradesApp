CXX = g++
CXXFLAGS = -std=c++17 -O2 -Iinclude
SRCS = src/main.cpp src/Student.cpp src/FileReader.cpp src/FileWriter.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = studentGrades_v025

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
