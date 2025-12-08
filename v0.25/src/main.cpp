#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

#include "Student.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "Timer.h"

int main() {
    std::cout << "===== v0.25 Student Processor =====\n";
    std::cout << "Select container type:\n";
    std::cout << "1. vector\n";
    std::cout << "2. list\n";
    std::cout << "3. deque\n";
    std::cout << "Choose: ";

    int choice;
    std::cin >> choice;

    std::string filename;
    std::cout << "Enter input filename: ";
    std::cin >> filename;

    Timer timer;

    if (choice == 1) {
        std::vector<Student> students;
        timer.reset();
        FileReader::readFile(filename, students);
        std::cout << "Read: " << timer.elapsed() << " sec\n";

        timer.reset();
        std::sort(students.begin(), students.end(),
                  [](const Student &a, const Student &b) {
                      return a.getFinalGrade() < b.getFinalGrade();
                  });
        std::cout << "Sort: " << timer.elapsed() << " sec\n";

        std::vector<Student> passed, failed;
        timer.reset();
        for (auto &s : students) {
            (s.getFinalGrade() < 5 ? failed : passed).push_back(s);
        }
        std::cout << "Split: " << timer.elapsed() << " sec\n";

        FileWriter::write("passed_vector.txt", passed);
        FileWriter::write("failed_vector.txt", failed);
    }

    else if (choice == 2) {
        std::vector<Student> temp;
        FileReader::readFile(filename, temp);

        std::list<Student> students(temp.begin(), temp.end());

        timer.reset();
        students.sort([](const Student &a, const Student &b) {
            return a.getFinalGrade() < b.getFinalGrade();
        });
        std::cout << "Sort: " << timer.elapsed() << " sec\n";

        std::list<Student> passed, failed;
        timer.reset();
        for (auto &s : students) {
            (s.getFinalGrade() < 5 ? failed : passed).push_back(s);
        }
        std::cout << "Split: " << timer.elapsed() << " sec\n";

        FileWriter::write("passed_list.txt", passed);
        FileWriter::write("failed_list.txt", failed);
    }

    else if (choice == 3) {
        std::deque<Student> students;

        std::vector<Student> temp;
        FileReader::readFile(filename, temp);
        for (auto &s : temp) students.push_back(s);

        timer.reset();
        std::sort(students.begin(), students.end(),
                  [](const Student &a, const Student &b) {
                      return a.getFinalGrade() < b.getFinalGrade();
                  });
        std::cout << "Sort: " << timer.elapsed() << " sec\n";

        std::deque<Student> passed, failed;
        timer.reset();
        for (auto &s : students) {
            (s.getFinalGrade() < 5 ? failed : passed).push_back(s);
        }
        std::cout << "Split: " << timer.elapsed() << " sec\n";

        FileWriter::write("passed_deque.txt", passed);
        FileWriter::write("failed_deque.txt", failed);
    }

    else {
        std::cout << "Invalid choice.\n";
    }

    std::cout << "DONE.\n";
    return 0;
}
