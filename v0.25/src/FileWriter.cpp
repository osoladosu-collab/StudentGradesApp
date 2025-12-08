#include "FileWriter.h"
#include <fstream>
#include <iomanip>

void FileWriter::write(const std::string &filename, const std::vector<Student> &students) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    // Write header
    file << "Name,HW1,HW2,HW3,HW4,HW5,Exam,FinalGrade\n";

    for (const auto &student : students) {
        file << student.name;

        // Write homework grades
        for (const auto &hw : student.homework) {
            file << "," << std::fixed << std::setprecision(2) << hw;
        }

        // If fewer than 5 homework grades, fill with empty
        for (size_t i = student.homework.size(); i < 5; ++i) {
            file << ",";
        }

        // Write exam and final grade
        file << "," << std::fixed << std::setprecision(2) << student.exam;
        file << "," << std::fixed << std::setprecision(2) << student.finalGrade;
        file << "\n";
    }

    file.close();
}
