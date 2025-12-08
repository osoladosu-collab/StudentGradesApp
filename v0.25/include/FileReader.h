#pragma once
#include <string>
#include <vector>
#include "Student.h"

class FileReader {
public:
    static void readFile(const std::string &filename, std::vector<Student> &students);
};
