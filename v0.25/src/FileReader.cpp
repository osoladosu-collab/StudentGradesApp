#include "FileReader.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>

std::vector<Student> FileReader::readStudents(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) throw FileOpenError("Cannot open file: " + filename);

    std::vector<Student> out;
    out.reserve(1024);

    std::string line;
    std::size_t lineNo = 0;
    while (std::getline(in, line)) {
        ++lineNo;
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string fn, ln;
        if (!(ss >> fn >> ln)) {
            // skip lines that don't have at least two tokens
            continue;
        }

        std::vector<int> hw;
        int value;
        while (ss >> value) hw.push_back(value);

        if (hw.empty()) {
            throw ParseError("No grades on line " + std::to_string(lineNo) + " in " + filename);
        }
        int exam = hw.back(); hw.pop_back();

        Student s(fn, ln);
        s.setHomework(hw);
        s.setExam(exam);
        // don't calculate final yet (main will choose avg/med)
        out.push_back(std::move(s));
    }
    return out;
}
