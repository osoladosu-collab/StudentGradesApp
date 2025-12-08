#ifndef FILEREADER_H
#define FILEREADER_H

#include "Student.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

struct FileReader {
    static void readFile(const std::string &filename, std::vector<Student> &students) {
        std::ifstream in(filename);
        if (!in.is_open()) throw std::runtime_error("Cannot open file: " + filename);

        std::string line;
        while (std::getline(in, line)) {
            std::stringstream ss(line);
            std::string token;
            int id;
            std::string name;
            double exam;
            std::vector<double> hw;

            // read id
            std::getline(ss, token, ',');
            id = std::stoi(token);

            // read name
            std::getline(ss, name, ',');

            // read exam
            std::getline(ss, token, ',');
            exam = std::stod(token);

            // For simplicity, let's assume rest are homework grades
            hw.clear();
            while (std::getline(ss, token, ',')) hw.push_back(std::stod(token));

            Student st(id, name);
            st.setExam(exam);
            st.setHomework(hw);
            st.calculateFinalGrade();

            students.push_back(st);
        }
    }
};

#endif // FILEREADER_H
