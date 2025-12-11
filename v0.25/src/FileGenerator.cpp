#include "FileGenerator.h"
#include <random>
#include <fstream>

void FileGenerator::generate(const std::string &filename,
                             std::vector<Student> &output) {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Cannot write to file: " + filename);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> gradeDist(1, 10);

    for (size_t i = 0; i < output.capacity(); i++) {
        Student s("Name" + std::to_string(i),
                  "Surname" + std::to_string(i));

        for (int j = 0; j < 5; j++)
            s.addHomework(gradeDist(gen));

        s.setExam(gradeDist(gen));
        s.calculateFinalGrade();

        output.push_back(s);

        out << s.getFirstName() << " "
            << s.getLastName() << " ";

        for (int h : s.getHomework()) out << h << " ";
        out << s.getExam() << "\n";
    }
}
