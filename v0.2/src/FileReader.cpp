#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<Student> FileReader::readFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("ERROR: Cannot open file " + filename);

    std::vector<Student> students;
    std::string line;
    students.reserve(1000); // optimization, increased later in main

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string fn, ln;
        int value;

        if (!(ss >> fn >> ln)) continue;

        std::vector<int> hw;
        while (ss >> value) hw.push_back(value);

        if (hw.size() < 2) continue; // <--- FIX

        int exam = hw.back();
        hw.pop_back();

        Student st(fn, ln);
        st.setHomework(hw);
        st.setExam(exam);
        st.calculateFinalGrade();

        students.push_back(st);
    }

    return students;
}
