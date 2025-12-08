#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileReader::readFile(const std::string &filename, std::vector<Student> &students) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int id;
        std::string name;
        int grade;

        if (!(ss >> id >> name >> grade)) continue; // skip invalid lines
        students.push_back(Student(id, name));      // id first, then name
        students.back().setExam(grade);
        students.back().calculateFinalGrade();
    }

    file.close();
}
