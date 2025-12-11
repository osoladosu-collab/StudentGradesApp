#ifndef FILEGENERATOR_H
#define FILEGENERATOR_H

#include <string>
#include <vector>
#include "Student.h"

class FileGenerator {
public:
    static void generate(const std::string &filename,
                         std::vector<Student> &output);
};

#endif
