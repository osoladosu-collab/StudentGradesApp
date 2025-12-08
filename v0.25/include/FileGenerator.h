#pragma once
#include <vector>
#include <string>
#include "Student.h"

class FileGenerator {
public:
    // Generate random homework, exam grades, calculate final grade, and write to file
    static void generate(const std::string &filename, std::vector<Student> &students);
};
