#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include "Student.h"

class FileReader {
public:
    // returns vector of students read from a file (each line: Name Surname hw1 ... hwN exam)
    static std::vector<Student> readStudents(const std::string &filename);
};

#endif // FILEREADER_H
