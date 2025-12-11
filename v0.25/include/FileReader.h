#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>
#include "Student.h"

class FileReader {
public:
    static std::vector<Student> readStudents(const std::string &filename);
};

#endif
