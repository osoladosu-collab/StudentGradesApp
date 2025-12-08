#include <iostream>
#include <vector>
#include "Student.h"
#include "FileWriter.h"
#include "FileReader.h"

int main() {
    std::vector<Student> students = {
        Student(1, "Alice"),
        Student(2, "Bob"),
        Student(3, "Charlie")
    };

    students[0].setHomework({90, 85, 92});
    students[0].setExam(88);
    students[0].calculateFinalGrade();

    students[1].setHomework({70, 75, 80});
    students[1].setExam(78);
    students[1].calculateFinalGrade();

    students[2].setHomework({85, 90, 88});
    students[2].setExam(82);
    students[2].calculateFinalGrade();

    try {
        FileWriter::write("students.csv", students);
        std::cout << "File written successfully.\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    std::vector<Student> readStudents;
    try {
        FileReader::readFile("students.csv", readStudents);
        std::cout << "Read " << readStudents.size() << " students:\n";
        for (const auto &s : readStudents) {
            std::cout << s.getId() << " | " << s.getName()
                      << " | Grade: " << s.getGrade() << "\n";
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
