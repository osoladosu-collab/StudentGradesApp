#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include "Student.h"

class FileReader {
public:
    static void readFile(const std::string &filename, std::vector<Student> &students);
};

#endif
