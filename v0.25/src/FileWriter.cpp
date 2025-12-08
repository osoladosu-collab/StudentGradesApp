#include "FileWriter.h"
#include <fstream>
#include <iostream>

void FileWriter::write(const std::string &filename, const std::vector<Student> &students) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto &student : students) {
        file << student.getId() << "," << student.getName() << "," << student.getFinalGrade() << "\n";
    }
    file.close();
}
