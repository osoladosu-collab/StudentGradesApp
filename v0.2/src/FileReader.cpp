#include "FileReader.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>

std::vector<Student> FileReader::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) throw FileOpenError("Cannot open file: " + filename);

    std::vector<Student> students;
    students.reserve(1000);

    std::string line;
    std::size_t lineno = 0;

    while (std::getline(file, line)) {
        ++lineno;
        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string fn, ln;
        if (!(ss >> fn >> ln)) {
            // Header or malformed line — skip
            continue;
        }

        std::vector<int> hw;
        int val;
        while (ss >> val) hw.push_back(val);

        if (hw.empty()) {
            throw ParseError("No grade data on line " + std::to_string(lineno) +
                             " in file " + filename);
        }

        int exam = hw.back();
        hw.pop_back();

        Student st(fn, ln);

        for (int h : hw) st.addHomework(h);
        st.setExam(exam);
        st.computeFinal();

        students.push_back(std::move(st));
    }

    return students;
}
