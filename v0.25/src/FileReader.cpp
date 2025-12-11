#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<Student> FileReader::readStudents(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::vector<Student> students;
    std::string line;

    while (std::getline(in, line)) {
        std::stringstream ss(line);

        std::string fn, ln;
        ss >> fn >> ln;

        if (fn.empty() || ln.empty())
            continue;

        Student s(fn, ln);

        int x;
        std::vector<int> homework;

        while (ss >> x) {
            homework.push_back(x);
        }

        if (homework.empty())
            continue;

        int exam = homework.back();
        homework.pop_back();

        for (int hw : homework)
            s.addHomework(hw);

        s.setExam(exam);
        s.calculateFinal(true);

        students.push_back(s);
    }

    return students;
}
