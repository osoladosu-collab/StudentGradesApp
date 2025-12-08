#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include "Student.h"

class FileReader {
public:
    static std::vector<Student> readFile(const std::string &filename);
};

#endif
