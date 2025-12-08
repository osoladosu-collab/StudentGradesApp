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

    FileWriter::write("students.csv", students);

    std::cout << "ID | Name | Final Grade\n";
    for (const auto &s : students) {
        std::cout << s.getId() << " | " << s.getName() << " | " << s.getFinalGrade() << "\n";
    }

    return 0;
}
