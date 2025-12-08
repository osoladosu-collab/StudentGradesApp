#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "Student.h"
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>

struct FileWriter {
    template <typename Container>
    static void write(const std::string &filename, const Container &students) {
        std::ofstream out(filename);
        if (!out.is_open()) throw std::runtime_error("Cannot open file: " + filename);

        for (const auto &student : students) {
            out << student.id << "," << student.name << "," << student.grade << "\n";
        }
    }
};

#endif // FILEWRITER_H
