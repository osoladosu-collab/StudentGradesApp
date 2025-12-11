#include "FileReader.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>

std::vector<Student> FileReader::readStudents(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) throw FileOpenError("Cannot open input file: " + filename);

    std::vector<Student> students;
    students.reserve(10000);

    std::string line;
    bool first = true;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        if (first) {
            first = false;
            if (line.find("Name") != std::string::npos ||
                line.find("Surname") != std::string::npos)
                continue;
        }

        std::istringstream iss(line);
        std::string fn, ln;
        std::vector<int> grades;
        int g;

        if (!(iss >> fn >> ln))
            throw ParseError("Invalid name fields: " + line);

        while (iss >> g) grades.push_back(g);
        if (grades.size() < 2)
            throw ParseError("Less than 2 numeric grades: " + line);

        int exam = grades.back();
        grades.pop_back();

        Student s(fn, ln);
        for (int hw : grades) s.addHomework(hw);
        s.setExam(exam);
        s.calculateFinalGrade();

        students.push_back(std::move(s));
    }

    return students;
}
