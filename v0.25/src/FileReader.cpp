#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>

void FileReader::readFile(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Cannot open file: " + filename);

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        // Parse ID
        std::getline(iss, token, ',');
        int id = std::stoi(token);

        // Parse name
        std::getline(iss, token, ',');
        std::string name = token;

        // Parse homework grades
        std::vector<double> hw;
        for (int i = 0; i < 3; ++i) { // assume 3 homework grades
            std::getline(iss, token, ',');
            hw.push_back(std::stod(token));
        }

        // Parse exam grade
        std::getline(iss, token, ',');
        double exam = std::stod(token);

        Student st(id, name);
        st.setHomework(hw);
        st.setExam(exam);
        st.calculateFinalGrade();

        students.push_back(st);
    }
}
