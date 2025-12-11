#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "FileGenerator.h"
#include "Timer.h"
#include "Exceptions.h"

int main() {
    try {
        std::cout << "STUDENT GRADES APP v0.25\n";
        std::cout << "-----------------------------\n";

        std::cout << "Choose mode:\n"
                  << "1 - Manual input\n"
                  << "2 - Read from file\n"
                  << "3 - Generate file\n"
                  << "Choice: ";

        int mode;
        std::cin >> mode;

        if (mode == 1) {
            int count;
            std::cout << "How many students? ";
            std::cin >> count;

            std::vector<Student> students;
            students.reserve(count);

            for (int i = 0; i < count; i++) {
                std::string fn, ln;
                int hwCount, exam, g;

                std::cout << "\nStudent " << (i + 1) << ":\n";
                std::cout << "First name: ";
                std::cin >> fn;
                std::cout << "Last name: ";
                std::cin >> ln;
                std::cout << "Number of HW grades: ";
                std::cin >> hwCount;

                Student s(fn, ln);
                for (int j = 0; j < hwCount; j++) {
                    std::cout << "HW" << (j + 1) << ": ";
                    std::cin >> g;
                    s.addHomework(g);
                }

                std::cout << "Exam grade: ";
                std::cin >> exam;

                s.setExam(exam);
                s.calculateFinalGrade();
                students.push_back(s);
            }

            FileWriter::writeStudents("manual_output.txt", students);
            std::cout << "Saved to manual_output.txt\n";
        }

        else if (mode == 2) {
            std::string filename;
            std::cout << "Filename: ";
            std::cin >> filename;

            Timer t;
            t.start();
            auto students = FileReader::readStudents(filename);
            double ms = t.stop();

            std::cout << "Loaded " << students.size() << " students in "
                      << ms << " ms\n";

            FileWriter::writeStudents("output_sorted.txt", students);
            std::cout << "Saved to output_sorted.txt\n";
        }

        else if (mode == 3) {
            std::string filename;
            int count;

            std::cout << "Output filename: ";
            std::cin >> filename;

            std::cout << "How many records? ";
            std::cin >> count;

            std::vector<Student> students;
            students.reserve(count);

            Timer t;
            t.start();
            FileGenerator::generate(filename, students);
            double ms = t.stop();

            std::cout << "Generated file in " << ms << " ms\n";
        }

        else {
            std::cout << "Invalid selection.\n";
        }
    }
    catch (std::exception &e) {
        std::cerr << "ERROR: " << e.what() << "\n";
    }

    return 0;
}
