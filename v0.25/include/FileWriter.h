#pragma once
#include <string>
#include <vector>
#include "Student.h"

class FileWriter {
public:
    static void write(const std::string &filename, const std::vector<Student> &students);
};
