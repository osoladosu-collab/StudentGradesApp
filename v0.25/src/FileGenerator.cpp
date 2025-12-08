#include "FileGenerator.h"
#include "FileWriter.h"
#include <random>
#include <numeric> // for std::accumulate

void FileGenerator::generate(const std::string &filename, std::vector<Student> &students) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> hwDist(60.0, 100.0);   // Homework grades
    std::uniform_real_distribution<> examDist(60.0, 100.0); // Exam grades

    for (auto &student : students) {
        // Generate 5 random homework grades
        student.homework.resize(5);
        for (auto &h : student.homework) {
            h = hwDist(gen);
        }

        // Generate exam grade
        student.exam = examDist(gen);

        // Calculate final grade (e.g., 40% homework average + 60% exam)
        double hwAverage = std::accumulate(student.homework.begin(), student.homework.end(), 0.0) / student.homework.size();
        student.finalGrade = hwAverage * 0.4 + student.exam * 0.6;
    }

    // Write to file using FileWriter
    FileWriter::write(filename, students);
}
