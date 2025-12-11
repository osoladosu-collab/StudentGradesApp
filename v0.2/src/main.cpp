#include <iostream>
#include <algorithm>
#include <vector>

#include "Student.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "FileGenerator.h"
#include "Timer.h"

int main() {
    std::cout << "===== STUDENT GRADES v0.2 =====\n";
    std::cout << "1. Generate files\n";
    std::cout << "2. Process existing file\n";
    std::cout << "Choose: ";

    int option;
    std::cin >> option;

    if (option == 1) {
        std::cout << "Generating files...\n";
        FileGenerator::generate("students10000.txt", 10000);
        FileGenerator::generate("students100000.txt", 100000);
        FileGenerator::generate("students1000000.txt", 1000000);
        FileGenerator::generate("students10000000.txt", 10000000);
        std::cout << "Generation complete.\n";
        return 0;
    }

    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    Timer totalTimer;
    totalTimer.reset();

    Timer timer;
    timer.reset();

    std::vector<Student> students;

    try {
        students = FileReader::readFile(filename);
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
        return 1;
    }

    std::cout << "Loaded " << students.size() << " students in "
              << timer.elapsed() << " sec\n";

    timer.reset();
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b) {
                  return a.getFinalGrade() < b.getFinalGrade();
              });

    std::cout << "Sorted in " << timer.elapsed() << " sec\n";

    std::vector<Student> passed, failed;

    timer.reset();
    for (const auto &s : students) {
        if (s.getFinalGrade() < 5.0)
            failed.push_back(s);
        else
            passed.push_back(s);
    }
    std::cout << "Split into passed/failed in " << timer.elapsed() << " sec\n";

    timer.reset();
    FileWriter::writeStudents("failed.txt", failed);
    FileWriter::writeStudents("passed.txt", passed);
    std::cout << "Wrote output in " << timer.elapsed() << " sec\n";

    std::cout << "TOTAL program time: " << totalTimer.elapsed() << " sec\n";

    return 0;
}

    std::cout << "Enter filename: ";
    std::cin >> filename;

    Timer timer;
    timer.reset();

    std::vector<Student> students;

    try {
        students = FileReader::readFile(filename);
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
        return 1;
    }

    std::cout << "Loaded " << students.size() << " students in "
              << timer.elapsed() << " sec\n";

    timer.reset();
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b) {
                  return a.getFinalGrade() < b.getFinalGrade();
              });

    std::cout << "Sorted in " << timer.elapsed() << " sec\n";

    std::vector<Student> passed, failed;

    timer.reset();
    for (const auto &s : students) {
        if (s.getFinalGrade() < 5.0)
            failed.push_back(s);
        else
            passed.push_back(s);
    }
    std::cout << "Split into passed/failed in " << timer.elapsed() << " sec\n";

    timer.reset();
    FileWriter::writeStudents("failed.txt", failed);
    FileWriter::writeStudents("passed.txt", passed);
    std::cout << "Wrote output in " << timer.elapsed() << " sec\n";

    return 0;
}
